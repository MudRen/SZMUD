// Code of ShenZhou
// sangucha ���ɲ�

#include <weapon.h>

inherit PIKE;

void create()
{
        set_name("���ɲ�", ({ "san gu cha", "cha" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ɲ棬��������Ĳ��������ĺ���\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n������һ��������һ��������\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_pike(30);
        setup();
}

