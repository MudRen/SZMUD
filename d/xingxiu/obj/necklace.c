// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIW"֬������"NOR, ({ "jade necklace", "necklace", "lace" }));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ɺ���֬�񴮳ɵ���������ɫ��������֬�������覡�\n");
		set("unit", "��");
		set("value", 6000);
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);

	}
	setup();
}       
