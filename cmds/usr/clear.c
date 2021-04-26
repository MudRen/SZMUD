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
指令格式: clear || clear off
 
这个命令将关闭和开启屏幕上的信息。
 
HELP
    );
	return 1;
}
 
