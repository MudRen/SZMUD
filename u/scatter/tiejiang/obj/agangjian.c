// Code by Scatter
// bgangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("��", ({ "sword", "jian" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ϵȵĽ������ֽ����Ǻܶ����еġ�\n");
                set("value", 550);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(45);
        setup();
}