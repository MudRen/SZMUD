#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIY "����֮��" NOR, ({ "feizhou zhixing", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"�������亱�������ʯ��\n"NOR);
                set("value", 10000);
                set("material", "leather");
        }
        setup();
}
