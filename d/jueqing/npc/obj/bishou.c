// jiuer 09.15.2001

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("匕首", ({ "bishou", "dagger" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", 
"这是一柄小小匕首，柄上镶有龙眼核般大小的一颗珠子，发出柔和莹光。\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回怀里。\n");
        }
        init_sword(5);
        setup();
}










