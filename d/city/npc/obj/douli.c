// Code of ShenZhou
// douli.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "�����ձ����" , ({ "dou li", "li" }) );
        set_color("$HIR$");
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�������ձ���ҡ�\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 4);
	}
	setup();
}
