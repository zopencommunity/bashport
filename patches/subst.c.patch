diff --git a/subst.c b/subst.c
index d9feabc..14d7516 100644
--- a/subst.c
+++ b/subst.c
@@ -6505,6 +6505,7 @@ process_substitute (string, open_for_read_in_child)
 
   pathname = make_dev_fd_filename (parent_pipe_fd);
 #endif /* HAVE_DEV_FD */
+  
 
   if (pathname == 0)
     {
@@ -6648,6 +6649,10 @@ process_substitute (string, open_for_read_in_child)
 
       exit (127);
     }
+#ifdef __MVS__
+  __chgfdccsid(fd, 819);
+#endif
+
   if (open_for_read_in_child)
     {
       if (sh_unset_nodelay_mode (fd) < 0)
@@ -6659,7 +6664,7 @@ process_substitute (string, open_for_read_in_child)
 #else /* HAVE_DEV_FD */
   fd = child_pipe_fd;
 #endif /* HAVE_DEV_FD */
-
+  
   /* Discard  buffered stdio output before replacing the underlying file
      descriptor. */
   if (open_for_read_in_child == 0)
