// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"��ɫ�Խ���"NOR, ({ "bai guazi", "guazi", "cloth"}) );
        set_weight(850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������ϸ�İ�ɫ�Խ��¡�\n");
                set("unit", "��");
                set("value", 350);
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("armor_prop/personality", 3);
        }
        setup();
}











