#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIG "���Ǥ���" NOR, ({ "qiangwei zhilei", "jewel" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"��˵�����ǵ������������!��\n"NOR);
                set("value", 20000);
                set("material", "leather");
        }
        setup();
}
