// Code of ShenZhou
// weapon: qiang.c
// qfy August 23, 96

#include <weapon.h>

inherit PIKE; 

void create()
{
        set_name("��ǹ", ({ "chang qiang", "qiang" }) );
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ǹ��ǹͷ����һ����ӧ��\n");
                set("value", 200);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n�����˸�ǹ������ӧ������\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_pike(20);
        setup();
}

