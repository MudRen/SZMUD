// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name(HIG"��������"NOR, ({ "jade bracelet", "bracelet", "zhuo" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ٴ����������ɫ��������䡣\n");
		set("unit", "��");
		set("value", 6000);
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	setup();
}       
