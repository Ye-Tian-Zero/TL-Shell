#include"tlsh.h"
#include<sys/wait.h>
#include<cstdlib>
#include<errno.h>
#include<cstdio>
int main()
{
	init();
	queue<string> task_queue;
	while(true)
	{
		cout << getPrefix();
		getTaskList(task_queue);
		executeTaskList(task_queue);
	}
	return 0;
}
