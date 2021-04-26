//Code by Scatter
// bcaidao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("菜刀", ({ "Caidao", "dao" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一把颇为锋利的菜刀。\n");
                set("value", 160);
                set("material", "steel");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
        }
        init_blade(11);
        setup();
}