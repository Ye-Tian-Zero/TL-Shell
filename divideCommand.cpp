#include"tlsh.h"

void divideCommand(vector<string>& Dcommand, const string& command)
{
	string temp;
	Dcommand.clear();
	if(command.empty())
		return;
	stringstream strm(command);
	int i(0);
	while(strm >> temp)
	{
		if(i == 0)
		{
			if(get_alias().count(temp) != 0)
			{
				temp = get_alias()[temp];
				stringstream strm2(temp);
				string temp2;
				while(strm2 >> temp2)
					Dcommand.push_back(temp2);
			}
			else
			{
				Dcommand.push_back(temp);
			}
		}
		else
			Dcommand.push_back(temp);
		++ i;
	}
}
