
//lengyuedao by chchong
//lengyuedao.c 冷月刀
//chchong 2001/08/26

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(WHT"冷月刀"NOR, ({ "lengyue dao", "dao"}));
        set_weight(8000);
        if (clonep())
        set_default_object(__FILE__);
        else 
        {       set("unit", "把");
                set("long", WHT"一把看似普通的长刀，刀刃上泛起淡淡的白色。\n" NOR);
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声清响，手中多了一把$n。\n" NOR);
                set("unwield_msg", "$N将手中的$n插回腰间刀鞘。\n");
        }
init_blade(70+random(11));
        setup(); ::create();
}
