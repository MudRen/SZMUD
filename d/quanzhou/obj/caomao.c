// Code of ShenZhou
// caomao.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "��ñ" , ({ "cao mao", "mao" }) );
        set_color("$HIG$");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ���±�Ĳ�ñ��\n");
		set("value", 150);
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	setup();
}
