// Code of ShenZhou
// youlong.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIR"火神剑"NOR, ({ "huoshen sword", "huoshen", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        "这是把浑身发出耀眼红光的宝剑，一股股炎热的气息从剑身从喷射而出，象一条噬人的火龙。\n");
                set("value", 1000);
                set("material", "blacksteel");
		set("rigidity", 100);
                set("wield_msg", 
                        HIR"伴随一道耀眼的红光，火神剑犹如一条威猛的火龙冲出剑鞘来到$N的手中。\n"NOR);
                set("unequip_msg", HIR"红光一闪，火神剑已入剑鞘。\n"NOR);
                set("unwield_msg", HIR"红光一闪，火神剑已入剑鞘。\n"NOR);
        }

        init_sword(100);
        setup();
}
