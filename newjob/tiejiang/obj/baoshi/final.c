#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIG "流星の泪" NOR, ({ "qiangwei zhilei", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", HIW"传说中流星的眼泪就是它了!。\n"NOR);
                set("value", 20000);
                set("material", "leather");
        }
        setup();
}
