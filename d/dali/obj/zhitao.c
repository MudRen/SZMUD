// Code of ShenZhou
// shoutao.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( CYN "��ָ��" NOR , ({ "zhitao", "zhi tao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ָ�ף�������ָ�ϣ����Ա���ָ�ؽڣ�����ָ�����˺����á�\n");
		set("value", 0);
		set("material", "finger");
		set("armor_prop/armor", 5);
	}
	setup();
}
