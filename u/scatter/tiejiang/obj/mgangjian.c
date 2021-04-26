// Code by Scatter
// bgangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("剑", ({ "sword", "jian" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄中上等级的剑，这种剑在一般武学之人间非常流行。\n");
                set("value", 350);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(30);
        setup();
}