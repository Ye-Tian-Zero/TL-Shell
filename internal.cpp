#include"tlsh.h"


void init()
{
	if(signal_(SIGINT, intHandler) == SIG_ERR)
	{
		cout << "Signal_ Error!" << endl;
		exit(1);
	}
	getIfDetach() = false;
	get_stdin_fd() = dup(STDIN_FILENO);
	getPrefix() = updatePrefix();
	get_alias()["ls"] = "ls --color=auto";
	get_alias()["grep"] = "grep --color=auto";
}

int& get_stdin_fd()
{
	static int stdin_fd;
	return stdin_fd;
}

queue<pid_t>& get_pidQueue()
{
	static queue<pid_t> pidQueue;
	return pidQueue;
}

int* get_pipefd()
{
	static int pipefd[2];
	return pipefd;
}

FILE** get_main_inFile()
{
	static FILE* inFile;
	return &inFile;
}

string& getPrefix()
{
	static string Prefix;
	return Prefix;
}

map<string, string>& get_alias(){
	static map<string, string> alias;
	return alias;
}

bool& getIfDetach()
{
	static bool Detach;
	return Detach;
}
