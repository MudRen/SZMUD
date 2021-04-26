// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW "凤尾鸳鸯钗" NOR, ({ "yuanyang chai", "chai" }));
        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("value", 7000);
                set("long", "一支以白金打造做成的发钗，让你的心中涌起一阵幸福的感觉。\n");
                set("material", "jade");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}
