// seng-cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(CYN"�Ҳ�����"NOR, ({ "jia sha", "cloth" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�������˳����ĻҲ����ġ�\n");
		set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}
