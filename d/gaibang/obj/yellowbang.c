// Code of ShenZhou
//yellowbang.c �����
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("�����", ({ "huang zhubang", "bang", "zhu bang", "zhubang", "stick", "yellow stick" }));
        set_color("$YEL$");
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�������䲻��򹷰����ͣ���������ȴ��һ�����죬ֻ��ɫ�����ƣ���ʾ��򹷰��б�\n");
                set("rigidity", 2000);
                set("value", 1000);
                set("material", "bamboo");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(50);
        setup();
}

