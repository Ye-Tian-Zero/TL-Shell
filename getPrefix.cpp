#include"tlsh.h"
#include<pwd.h>
#include<sys/types.h>
#include<sys/utsname.h>
#include<unistd.h>
#include<algorithm>

string updatePrefix()
{
	char buffer[4096];
	uid_t user_id = getuid();
	struct utsname uname_info;
	uname(&uname_info);
	getcwd(buffer, 4096);

	string user_name = getpwuid(user_id)->pw_name;
	string temp(buffer);
	string homeUser = "/home/" + user_name;
	string computer_name(uname_info.nodename);

	user_name = "\033[1;37m" + user_name;
	if(temp.size() >= homeUser.size())
	{
		if(string(temp.begin(), temp.begin() + homeUser.size()) == homeUser)
			temp.replace(0, homeUser.size(), "~");
	}
	return user_name + "@ " + temp + "> " + "\033[0m";
}
