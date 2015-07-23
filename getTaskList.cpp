#include"tlsh.h"

void getTaskList(queue<string> & task_queue)
{
	while(!task_queue.empty()) task_queue.pop();
	string command_line;
	getline(cin, command_line);

	if(cin.eof())
	{
		exit(0);
	}	

	if(command_line.empty())
		return;

	if(command_line.back() == '&')
	{
		getIfDetach() = true;
		command_line.erase(command_line.end() - 1);
	}
	else
	{
		getIfDetach() = false;
	}

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
