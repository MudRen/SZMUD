//Code by Scatter
// bblade.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("刀", ({ "blade", "dao" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一把上等的刀子。\n");
                set("value", 180);
                set("material", "steel");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n收了起来。\n");
        }
        init_blade(25);
        setup();
}