#include"tlsh.h"
#include<sys/wait.h>
#include<fcntl.h>
#include<cstdio>
#include<pwd.h>
#include<algorithm>
void executeTaskList(queue<string>& task_queue)
{
	//cout << "SIZE: " << task_queue.size() << endl;
	if(task_queue.empty())
		return;
	pid_t pid;
	string command;
	vector<string> Dcommand;
	while(!get_pidQueue().empty()) get_pidQueue().pop();
	if(task_queue.size() == 1)
	{
		command = task_queue.front();
		task_queue.pop();
		divideCommand(Dcommand, command);

		if(Dcommand[0] == "exit")
		{
			exit(0);
		}

		if(Dcommand[0] == "cd")
		{
			string user_name = getpwuid(getuid())->pw_name;
			if(Dcommand.size() >= 2)
			{
				string path;
				if(Dcommand[1][0] == '~')
				{
					path = "/home/" + user_name + string(Dcommand[1].begin() + 1, Dcommand[1].end());
					chdir(path.c_str());
				}
				else
				{
					chdir(Dcommand[1].c_str());
				}
			}
			else
			{
				chdir(("/home/" + user_name).c_str());
			}
			getPrefix() = updatePrefix();

			return;
		}
		


		if((pid = fork()) == 0)
		{
			execute(Dcommand);
			exit(0);
		}
		else
		{
			waitpid(pid, nullptr, 0);
		}
	}
	else
	{

		pipe(get_pipefd());
		command = task_queue.front();
		task_queue.pop();
		divideCommand(Dcommand, command);

		if(Dcommand[0] == "cd")
		{
			string user_name = getpwuid(getuid())->pw_name;
			if(Dcommand.size() >= 2)
			{
				string path;
				if(Dcommand[1][0] == '~')
				{
					path = "/home/" + user_name + string(Dcommand[1].begin() + 1, Dcommand[1].end());
					chdir(path.c_str());
				}
				else
				{
					chdir(Dcommand[1].c_str());
				}
			}
			else
			{
				chdir(("/home/" + user_name).c_str());
			}
			getPrefix() = updatePrefix();

			return;
		}

		if((pid = fork()) == 0)
		{
			close(get_pipefd()[0]);
			if(get_pipefd()[1] != STDOUT_FILENO)
			{
				dup2(get_pipefd()[1], STDOUT_FILENO);
				close(get_pipefd()[1]);
			}
			execute(Dcommand);
			exit(0);
		}
		else
		{
			get_pidQueue().push(pid);
		}

		while(!task_queue.empty())
		{
			close(get_pipefd()[1]);
			if(get_pipefd()[0] != STDIN_FILENO)
			{
				dup2(get_pipefd()[0], STDIN_FILENO);
				close(get_pipefd()[0]);
			}

			pipe(get_pipefd());
			command = task_queue.front();
			task_queue.pop();
			divideCommand(Dcommand, command);
			if((pid = fork()) == 0)
			{
				close(get_pipefd()[0]);
				if(!task_queue.empty())
				{
					if(get_pipefd()[1] != STDOUT_FILENO)
					{
						dup2(get_pipefd()[1], STDOUT_FILENO);
						close(get_pipefd()[1]);
					}
				}
				else
					close(get_pipefd()[1]);
				execute(Dcommand);
				exit(0);
			}
			else
			{
				get_pidQueue().push(pid);
			}
		}

		dup2(get_stdin_fd(), STDIN_FILENO);
		while(!get_pidQueue().empty())
		{
			waitpid(get_pidQueue().front(), nullptr, 0);
			get_pidQueue().pop();
		}
	}
}
