#include <ansi.h> 
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIR"开山大斧"NOR, ({ "kaishan fu", "fu","axe" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long", BLU"这是当年小鹰子使用的一对沾满血腥铁锈的大板斧。\n"NOR);
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N提出一对$n，拿在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_axe(15);
        setup();
}
