// Code of ShenZhou
// ban.c
// Created by Xiang@XKX
#define BANNED_FILE "/log/static/BAN.c"

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site, reason;

	if (!arg)
		BAN_D->print();
        else if (arg == "-l") me->start_more_file(BANNED_FILE);
	else if (sscanf(arg, "+ %s %s", site, reason) == 2) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else{
			BAN_D->add(site);
			log_file("static/BAN", sprintf("[%s] IP %s 段因为 %s 被 %s(%s) 关闭。\n",
		                ctime(time())[0..15], site, reason, me->name(), geteuid(me)));
			}
		}
	else if (sscanf(arg, "- %s %s", site, reason) == 2){
                log_file("static/BAN", sprintf("[%s] IP %s 段因为 %s 被 %s(%s) 开启。\n",
	                ctime(time())[0..15], site, reason, me->name(), geteuid(me)));
		BAN_D->remove(site);
		}
	else write("指令格式：ban [+|- site] <原因>\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
指令格式：ban [+|- site] <原因>

这条命令是用来防止有人蓄意捣乱。
HELP
	);
	return 1;
}
