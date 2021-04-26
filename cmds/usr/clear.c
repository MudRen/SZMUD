// Code of ShenZhou
// clear.c 
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
	if (str != "off") {
		me->set_temp("block_msg/all", 1);
    		printf(CLR);
    		return 1;
	}
	me->set_temp("block_msg/all", 0);
	return 1;
}
 
int help(object me)
{
    write(@HELP
ָ���ʽ: clear || clear off
 
�������رպͿ�����Ļ�ϵ���Ϣ��
 
HELP
    );
	return 1;
}
 
