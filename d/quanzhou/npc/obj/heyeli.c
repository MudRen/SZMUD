// Code of ShenZhou
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "��ߺ�Ҷ��" , ({ "heye li", "li" }) );
        set_color("$HIG$");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����ߺ�Ҷ�ҡ�\n");
		set("value", 150);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("female_only",1);
	}
	setup();
}
