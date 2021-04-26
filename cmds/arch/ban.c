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
			write("���ܽ��� *, +, ? ��β�ĵ�ַ��\n");
		else{
			BAN_D->add(site);
			log_file("static/BAN", sprintf("[%s] IP %s ����Ϊ %s �� %s(%s) �رա�\n",
		                ctime(time())[0..15], site, reason, me->name(), geteuid(me)));
			}
		}
	else if (sscanf(arg, "- %s %s", site, reason) == 2){
                log_file("static/BAN", sprintf("[%s] IP %s ����Ϊ %s �� %s(%s) ������\n",
	                ctime(time())[0..15], site, reason, me->name(), geteuid(me)));
		BAN_D->remove(site);
		}
	else write("ָ���ʽ��ban [+|- site] <ԭ��>\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��ban [+|- site] <ԭ��>

����������������ֹ�������⵷�ҡ�
HELP
	);
	return 1;
}
