#define _POSIX_SOURCE
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define NULL_HANDLER SIG_DFL
struct termsig {
  int name; void (*hdlr)(); int orig_flags; int core_dump;
};

static struct termsig terminating_signals[] = {
{  SIGHUP, NULL_HANDLER, 0 },
{  SIGINT, NULL_HANDLER, 0 },
{  SIGILL, NULL_HANDLER, 0, 1},
{  SIGTRAP, NULL_HANDLER, 0, 1 },
{  SIGDANGER, NULL_HANDLER, 0 },
{  SIGFPE, NULL_HANDLER, 0, 1 },
{  SIGSEGV, NULL_HANDLER, 0, 1 },
{  SIGPIPE, NULL_HANDLER, 0 },
{  SIGALRM, NULL_HANDLER, 0 },
{  SIGTERM, NULL_HANDLER, 0 },
{  SIGUSR1, NULL_HANDLER, 0 },
{  SIGUSR2, NULL_HANDLER, 0 },
};

#define TERMSIGS_LENGTH (sizeof (terminating_signals) / sizeof (struct termsig))

main() {
  register int i;
  struct sigaction act;

  memset(&act, 0x7D, sizeof(struct sigaction));
  for (i=0; i<TERMSIGS_LENGTH; ++i) {
    if (signal_is_trapped (terminating_signals[i].name) || signal_is_special ((terminating_signals[i].name)))
      continue;

    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = terminating_signals[i].hdlr;
    act.sa_flags = terminating_signals[i].orig_flags;

    sigaction(terminating_signals[i].hdlr, &act, NULL);
    signal(terminating_signals[i].name, terminating_signals[i].hdlr);
  }
}

