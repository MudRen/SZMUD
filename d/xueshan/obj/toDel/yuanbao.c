// Code of ShenZhou
// necklace.c ������
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"��Ԫ��"NOR, ({ "jin yuanbao", "jin", "yuanbao" }));
	set("weight", 9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 400000);
		set("material", "gold");
	}
	setup();
}	
