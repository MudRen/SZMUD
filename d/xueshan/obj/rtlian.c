// Code of ShenZhou

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name( BLU "��ͷ��" NOR, ({ "rentou lian", "lian" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����һ�������ô���������ͷ����\n");
		set("value", 150);
		set("no_sell",1);
		set("material", "neck");
		set("armor_prop/armor", 7);
	}
	setup();
}
