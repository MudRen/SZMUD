// Code of ShenZhou
//tongbang.c ͭ��
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("ͭ��", ({ "tong bang", "bang", "tongbang", "stick" "bonze stick" }));
        set_color("$YEL$");
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���̵ֶ�ͭ�����������Ƴγεģ�����ȴ���ᡣ\n");
                set("rigidity", 1000);
                set("value", 5000);
                set("material", "bonze");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(65+ random(10));
        setup();
}

