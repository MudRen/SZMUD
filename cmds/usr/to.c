// Code of ShenZhou
// to.c

// inherit F_CLEAN_UP;
// Don't want this command be cleaned up while typing long string.

object gme;
string garg;

int main(object me, string arg)
{
	gme = me; garg = arg;
	me->edit( (: call_other, this_object(), ({ "do_to", gme, garg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@HELP
ָ���ʽ : to <ָ��>

����һ������������ϵ�����, <ָ��>ͨ�������ѶϢ��ָ����
say , tell , describe , chat , reple ........�ȡ�
HELP
    );
    return 1;
}

