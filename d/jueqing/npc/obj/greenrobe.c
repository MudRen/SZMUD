// Filename: /d/u/jiuer/obj/greenrobe.c
// Jiuer--Aug 11.2001


#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	    set_name(GRN"����"NOR, ({ "green robe", "cloth", "pao", "robe"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ɫ���ۡ�\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 0);
        }
        setup();
}
