// Code of ShenZhou
// color.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
//int i;
	string cn;

        if( me->query("combat_exp") < 2000000)
		return notify_fail("�������������������û���ʸ���ɫ��\n");
	cn = me->query("colorname");
	if( cn &&  cn[7..strlen(cn)-8] == me->query("name"))
		return notify_fail("��������Ѿ�����ɫ�ˡ�\n");

	if( !arg ) return notify_fail("��Ҫ���Լ���������ʲôɫ��\n");

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
	return notify_fail("��Ҫ���Լ���������ʲôɫ��\n");

	write("�����������Ư�����ˡ�\n");
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : color <��ɫ>
 
������ж������飬��ô����Ը����Լ����������ּ���һ����ɫ��
��ѡ��������ɫ��
��ע�⣡������ɫһ�����ϾͲ��ܸ��ģ���������������֣�������

RED - [31m��ɫ[37;0m		HIR - [1;31m����ɫ[37;0m
GRN - [32m��ɫ[37;0m		HIG - [1;32m����ɫ[37;0m
YEL - [33m����ɫ[37;0m		HIY - [1;33m��ɫ[37;0m
BLU - [34m����ɫ[37;0m		HIB - [1;34m��ɫ[37;0m
MAG - [35mǳ��ɫ[37;0m		HIM - [1;35m�ۺ�ɫ[37;0m
CYN - [36m����ɫ[37;0m		HIC - [1;36m����ɫ[37;0m
WHT - [37mǳ��ɫ[37;0m		HIW - [1;37m��ɫ[37;0m

HELP
        );
        return 1;
}
