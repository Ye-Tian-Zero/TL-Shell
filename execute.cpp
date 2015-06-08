#include"tlsh.h"
#include<unistd.h>
#include<fcntl.h>
void execute(vector<string>& Dcommand)
{
	for(vector<string>::size_type i(0); i != Dcommand.size();)
	{
		if(Dcommand[i] == ">")
		{
			if(i != Dcommand.size() - 1)
			{
				int fd_redirection = open(Dcommand[i + 1].c_str(), O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
				if(fd_redirection != STDOUT_FILENO)
				{
					dup2(fd_redirection, STDOUT_FILENO);
				}
				auto to_erase = Dcommand.begin() + i;
				to_erase = Dcommand.erase(to_erase);
				Dcommand.erase(to_erase);
			}
			else
			{
				int fd_redirection = open("/dev/NULL", O_WRONLY | O_CREAT | O_TRUNC);
				if(fd_redirection != STDOUT_FILENO)
				{
					dup2(fd_redirection, STDOUT_FILENO);
				}
				auto to_erase = Dcommand.begin() + i;
				Dcommand.erase(to_erase);
			}
		}
		else if(Dcommand[i] == "<")
		{
			if(i != 0)
			{
				int fd_redirection = open(Dcommand[i + 1].c_str(), O_RDONLY);
				if(fd_redirection != STDIN_FILENO)
				{
					dup2(fd_redirection, STDIN_FILENO);
				}
				auto to_erase = Dcommand.begin() + i;
				to_erase = Dcommand.erase(to_erase);
				Dcommand.erase(to_erase);
			}
			else
			{
				int fd_redirection = open("/dev/NULL", O_RDONLY);
				if(fd_redirection != STDIN_FILENO)
				{
					dup2(fd_redirection, STDIN_FILENO);
				}
				auto to_erase = Dcommand.begin() + i;
				Dcommand.erase(to_erase);
			}

		}
		else
		{
			++ i;
		}
	}

	char** args = new char*[Dcommand.size()+1];
	args[Dcommand.size()] = (char*)0; 
	char* to_execute = (char*)Dcommand[0].c_str();

	for(vector<string>::size_type i(0); i != Dcommand.size(); ++ i)
	{
		args[i] = (char*)Dcommand[i].c_str();
	}
	if(execvp(args[0], args) < 0) 
	{
		if (errno == ENOENT)
		{
			if(Dcommand[0].size() > 2 && Dcommand[0][0] == '.' && Dcommand[0][1] == '/')
				cerr << "\033[31m" << Dcommand[0] << ": No such file" << "\033[0m" << endl;
			else
				cerr << "\033[31m" << Dcommand[0] << ": No such command" << "\033[0m" << endl;
		}
		if (errno == EACCES)
			cout << "\033[31m" << "Permission denied" << "\033[0m" << endl;
	}
}
