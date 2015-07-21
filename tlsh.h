#ifndef _TLSH_H_
#define _TLSH_H_

#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include<queue>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>
#include<map>
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
using namespace std;

void (*signal_(int signo, void(*func)(int))) (int);

sigset_t sigMaskBlock(int sig);

bool& getIsBack();

void sigMaskSet(sigset_t);

void getTaskList(queue<string> & task_stack);

string updatePrefix();

void execute(vector<string>& Dcommand);

void executeTaskList(queue<string>& );

FILE** get_main_inFile();

int* get_pipefd();

void init();

int& get_stdin_fd();

queue<pid_t>& get_pidQueue();

string& getPrefix();

void divideCommand(vector<string>& Dcommand, const string& command);

map<string,string>& get_alias();

static void intHandler(int signo)
{
	cout << endl;
	cout << getPrefix() << flush;
}
#endif
