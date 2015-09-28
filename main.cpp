#include"tlsh.h"
int main()
{
	init();
	queue<string> task_queue;
	while(true)
	{
		cout << getPrefix() << flush;
		getTaskList(task_queue);
		executeTaskList(task_queue);
	}
	return 0;
}
