// Code of ShenZhou
// guanfu.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIC"�ٷ�"NOR, ({ "guanfu", "cloth", "guan fu" }));
        set("long", "����һ�������󳼴��Ĺٷ����ϱ߻��л��ᡣ\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
                set("value", 800);
                set("armor_prop/armor", 20);
	}
	setup();
}
