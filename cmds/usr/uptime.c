// uptime.c
// From ES2
// Modified by server(7/23/2001)

#include <mudlib.h>

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��\n";

	write(INTERMUD_MUD_CNAME + "�Ѿ�ִ����" + time + "\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ���������Ϸ�Ѿ�����ִ���˶��.
 
HELP
    );
    return 1;
}
