// Code of ShenZhou
// weapon: heiqi.c
// long Apirl 13, 97

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("С����", ({ "hong qi", "qi" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����˲������ߵĺ�ɫС�죬�������Ÿ����̵Ļ��׼Ǻ�\n");
                set("value", 0);
                set("material", "");
                set("wield_msg", "$N�ó�һ��$n��\n");
                set("unwield_msg", "$N��$n��ر��ᡣ\n");
        }
        init_halberd(20);
        setup();
}
