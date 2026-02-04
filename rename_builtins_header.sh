#!/bin/sh
# Script to rename builtins.h to bashbuiltins.h to avoid z/OS header collision
# Run this from the bash-5.3 source directory

set -e

BASH_SRC_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$BASH_SRC_DIR"

echo "Renaming builtins.h to bashbuiltins.h..."

# Step 1: Rename the header file
if [ -f "builtins.h" ]; then
    mv builtins.h bashbuiltins.h
    echo "  Renamed: builtins.h -> bashbuiltins.h"
else
    echo "  Warning: builtins.h not found in current directory"
fi

# Step 2: Update include guard in the renamed file
if [ -f "bashbuiltins.h" ]; then
    tmpfile="bashbuiltins.h.tmp.$$"
    sed 's/BUILTINS_H/BASHBUILTINS_H/g' bashbuiltins.h > "$tmpfile" && mv "$tmpfile" bashbuiltins.h
    echo "  Updated include guard in bashbuiltins.h"
fi

# Step 3: Global find and replace in all source files
echo "Updating includes globally..."

find . -type f \( -name "*.c" -o -name "*.h" -o -name "*.def" -o -name "*.in" \) | while read file; do
    if grep -q 'builtins\.h' "$file"; then
        sed -i 's|builtins\.h|bashbuiltins.h|g' "$file"
        echo "  Updated: $file"
    fi
done

echo ""
echo "Done! The header has been renamed to bashbuiltins.h"

