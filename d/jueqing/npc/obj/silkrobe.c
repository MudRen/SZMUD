// Filename: /d/jueqing/obj/silkrobe.c
// Jiuer--Aug 11.2001


#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	    set_name(BLU"����"NOR, ({ "skillrobe", "cloth", "pao", "robe"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɫ���ӳ��ۡ�\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 0);
        }
        setup();
}
