#include"tlsh.h"

void getTaskList(queue<string> & task_queue)
{
	while(!task_queue.empty()) task_queue.pop();
	string command_line;
	getline(cin, command_line);
	if(command_line.empty())
		return;
	auto base_iter = command_line.begin();
	for(auto off_iter = command_line.begin(); off_iter != command_line.end(); ++ off_iter )
	{
		if(*off_iter == '|')
		{
			if(off_iter != command_line.begin() && *(off_iter - 1) == '\\')
			{
				off_iter = command_line.erase(off_iter - 1);
				continue;
			}
			task_queue.push(string(base_iter, off_iter));
			base_iter = off_iter + 1;
		}
	}
	task_queue.push(string(base_iter, command_line.end()));
	return;
}
