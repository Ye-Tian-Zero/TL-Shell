#include"tlsh.h"

void sigMaskSet(int sig)
{
	sigset_t sigMask;
	sigemptyset(&sigMask);

	sigaddset(&sigMask, sig);
	if(sigprocmask(SIG_BLOCK, &sigMask, nullptr) < 0)
	{
		cout << "SigProcMask Error!" << endl;
		exit(0);
	}
	
}
