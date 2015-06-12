#include"tlsh.h"

void divideCommand(vector<string>& Dcommand, const string& command)
{
	string temp;
	Dcommand.clear();
	if(command.empty())
		return;
	stringstream strm(command);
	while(strm >> temp)
	{
		Dcommand.push_back(temp);
	}
}
