 // Code of ShenZhou
// xuedao.c  血刀

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIC"雪饮狂刀"NOR, ({ "scatter blade", "dao", "blade" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIC"一眼看上去就知道这把刀并非一般人能使用。\n" NOR);
                set("value", 7000000);
                set("material", "steel");
                set("rigidity", 1000);
                set("wield_msg", HIC "只听「唰」的一声，顿时间周围被强光给拢罩住了。\n" NOR);
                set("unwield_msg", HIC "周围顿时间恢复平静。\n" NOR);
                set("clone_ob", "/u/scatter/myown/kdao");
        }
        ::create();
        init_blade(300);
        setup();
}
