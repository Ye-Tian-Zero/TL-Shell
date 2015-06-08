#include"tlsh.h"

void init()
{
	get_stdin_fd() = dup(STDIN_FILENO);
	getPrefix() = updatePrefix();
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
