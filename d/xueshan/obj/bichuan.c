// Code of ShenZhou

#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
	set_name( HIY "����" NOR, ({ "bi chuan", "chuan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
                set("long", "����һ���Ƶı��ˣ���������һ��С�ߡ�\n");
		set("value", 150);
		set("material", "hands");
		set("armor_prop/armor", 4);
	}
	setup();
}
