//Cracked by Roath
// work-letter1.c ��������ù���
// mantian
#include <ansi.h>

inherit ITEM;
string long_desc();

void create()
{
	set_name(RED "������" NOR, ({"gongji biao", "biao", "book"}));
	set_weight(100);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", (: long_desc :));
//		set("long","����һ������������¼�����ӹ����Ĳ��ӣ����Գʱ�ʥ�ϡ�\n");
		set("no_get", "�������������뿪�㡣\n");
		set("material", "paper");
	}
}

string long_desc()
{
	string descrp;
	object me = this_player();

	descrp = RED"����һ������������¼�����ӹ����Ĳ��ӣ����Գʱ�ʥ�ϡ�\n\n"NOR;
	if (me->query_temp("dali/uprank"))
	{
		descrp += "������ϸ�����"+me->query("name");
		descrp += "�����������������ڷܣ��ſ����á�\n\n";
		descrp += "�书�����£�\n";
		descrp += RED"���͵㣺"NOR;
		descrp += chinese_number(me->query_temp("dali/trust"))+"�㡣\n";
		descrp += HIC"��������"NOR;
		descrp += chinese_number(me->query_temp("dali/arrestmade"))+"�㡣\n";
		descrp += MAG"���Ͷȣ�"NOR;
		descrp += chinese_number(me->query_temp("dali/jobdone"))+"�㡣\n\n��������������";
		descrp += me->query_temp("allowtime");
	}
	return descrp;
}
