// Code of ShenZhou
// xiupao.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( RED"��������"NOR, ({ "xiu pao", "pao"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������ϸ�Ĵ������ۡ�\n");
                set("unit", "��");
                set("value", 300);
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        setup();
}

