// Code of ShenZhou
// weapon: qingqi.c
// long Apirl 13, 97

#include <weapon.h>
#include <ansi.h>
inherit HALBERD;

void create()
{
        set_name(HIC"С����"NOR, ({ "qing qi", "qi" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����˲������ߵ���ɫС�죬�������Ÿ����̵Ļ��׼Ǻ�\n");
                set("value", 0);
                set("material", "");
                set("wield_msg", "$N�ó�һ��$n��\n");
                set("unwield_msg", "$N��$n��ر��ᡣ\n");
        }
        init_halberd(20);
        setup();
}
