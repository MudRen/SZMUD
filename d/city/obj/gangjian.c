// Code by Scatter
// 12/01/2001
// V 1.0
// gangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("�ֽ�", ({ "gangjian", "jian", "sword" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ƴɵĸֽ������ֽ��ڽ���֮��ǳ����С�\n");
                set("value", 300);
                set("material", "steel");
                                
                                set("wtype", "gangjian");
                                set("wposition", "/clone/weapon/gangjian.c");


                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(25);
        setup();
}

