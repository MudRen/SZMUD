#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIM "Ǿޱ֮��" NOR, ({ "qiangwei zhilei", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIM"����Ǿ����ı�ʯ----Ǿޱ֮�ᡣ\n"NOR);
                set("value", 10000);
                set("material", "leather");
        }
        setup();
}
