// Code of ShenZhou
// color.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
//int i;
	string cn;

        if( me->query("combat_exp") < 2000000)
		return notify_fail("你的名声还不够响亮，没有资格上色。\n");
	cn = me->query("colorname");
	if( cn &&  cn[7..strlen(cn)-8] == me->query("name"))
		return notify_fail("你的名字已经有颜色了。\n");

	if( !arg ) return notify_fail("你要给自己的名字上什么色？\n");

	if( arg == "RED") me->set_color("$RED$");
	if( arg == "GRN") me->set_color("$GRN$");
	if( arg == "YEL") me->set_color("$YEL$");
	if( arg == "BLU") me->set_color("$BLU$");
	if( arg == "MAG") me->set_color("$MAG$");
	if( arg == "CYN") me->set_color("$CYN$");
	if( arg == "WHT") me->set_color("$WHT$");
	if( arg == "HIR") me->set_color("$HIR$");
	if( arg == "HIG") me->set_color("$HIG$");
	if( arg == "HIY") me->set_color("$HIY$");
	if( arg == "HIB") me->set_color("$HIB$");
	if( arg == "HIM") me->set_color("$HIM$");
	if( arg == "HIC") me->set_color("$HIC$");
	if( arg == "HIW") me->set_color("$HIW$");

	else if(!me->query("colorname"))
	return notify_fail("你要给自己的名字上什么色？\n");

	write("现在你的名字漂亮多了。\n");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : color <颜色>
 
如果你有二百万经验，那么你可以给你自己响亮的名字加上一个颜色。
请选择以下颜色：
（注意！！！颜色一旦加上就不能更改，除非你更换了名字！！！）

RED - [31m红色[37;0m		HIR - [1;31m亮红色[37;0m
GRN - [32m绿色[37;0m		HIG - [1;32m亮绿色[37;0m
YEL - [33m土黄色[37;0m		HIY - [1;33m黄色[37;0m
BLU - [34m深蓝色[37;0m		HIB - [1;34m蓝色[37;0m
MAG - [35m浅紫色[37;0m		HIM - [1;35m粉红色[37;0m
CYN - [36m蓝绿色[37;0m		HIC - [1;36m天青色[37;0m
WHT - [37m浅灰色[37;0m		HIW - [1;37m白色[37;0m

HELP
        );
        return 1;
}
