// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"����"NOR, ({ "robe", "pao"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�Ļ�ɫ���ۣ����۱�������һ����ɫ�Ļ��ס�\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 100);
        }
        setup();
}

