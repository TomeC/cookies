#ifndef DAEMON_H
#define DAEMON_H

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void Ignore(int signum)
{
    struct sigaction sig;
    sig.sa_handler = SIG_IGN;
    sig.sa_flags = 0;

    sigemptyset(&sig.sa_mask);
    sigaction(signum, &sig, 0);
}

void InitDaemon()
{
    pid_t pid;

    if ((pid = fork()) != 0)
    {
        exit(0);
    }

    setsid();

    signal(SIGINT,  SIG_IGN);
    signal(SIGHUP,  SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGHUP,  SIG_IGN);
    signal(SIGUSR1, SIG_IGN);
    signal(SIGUSR2, SIG_IGN);
    Ignore(SIGPIPE);
    Ignore(SIGHUP);

    if ((pid = fork()) != 0)
    {
        exit(0);
    }

    umask(0);
}

#endif
