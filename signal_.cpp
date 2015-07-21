#include"tlsh.h"


sigset_t sigMaskBlock(int sig)
{
	sigset_t sigMask, o_sigMask;
	sigemptyset(&sigMask);

	sigaddset(&sigMask, sig);

	if(sigprocmask(SIG_BLOCK, &sigMask, &o_sigMask) < 0)
	{
		cout << "SigProcMask Error!" << endl;
		exit(0);
	}
	return o_sigMask;
}

void sigMaskSet(sigset_t Mask)
{
	if(sigprocmask(SIG_SETMASK, &Mask, nullptr) < 0)
	{
		cout << "SigSet Error!" << endl;
		cout << "errno: " << errno << endl;
		exit(0);
	}
	return;
}

void (*signal_(int signo, void(*func)(int))) (int)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	act.sa_flags = 0;
	act.sa_flags |= SA_RESTART;
	sigemptyset(&act.sa_mask);
	if(sigaction(signo, &act, &oact) < 0)
	{
		return SIG_ERR;
	}
	return oact.sa_handler;
}
