#ifndef _TLSH_H_
#define _TLSH_H_
#include<vector>
#include<sstream>
#include<string>
#include<iostream>
#include<queue>
#include<sys/wait.h>
#include<unistd.h>
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)
using namespace std;

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

#endif
