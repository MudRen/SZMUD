#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIB "�̱�ʯ" NOR, ({ "lv baoshi", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�źܴ���̱�ʯ��\n");
                set("value", 5000);
                set("material", "leather");
        }
        setup();
}
