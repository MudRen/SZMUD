//Code of ShenZhou (5/25/2001)
// locate.c
// created by xuy 09/25/97 

#include <net/dns.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg)
{
    int i;
    string str;
    object *target;

    if( !stringp(arg) || arg == "" ) return notify_fail("��Ҫ��˭��\n");
    LOCATE_Q->send_locate_q(arg);
    write("������Ѱ�����Ժ�\n");
    target = LOCATE_Q->find_users(arg);
    if(pointerp(target) && sizeof(target)) 
	for(i=0; i<sizeof(target); i++) 
	    write(target[i]->short(1)+"���������С�\n");
    else
	write("û�з���"+arg+"�ڱ�վ���ߣ�������Ѱ����վ���С�\n");
    return 1;
}

    
int help(object me)
{
write(@HELP
ָ���ʽ : locate ʹ��������

���ָ���������Ϸ��������Ѱĳһ��ҡ�

���ָ� finger, who
HELP
    );
    return 1;
}
