#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIB "����ʯ" NOR, ({ "lan baoshi", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ϡ�е�����ʯ��\n");
                set("value", 3000);
                set("material", "leather");
        }
        setup();
}
