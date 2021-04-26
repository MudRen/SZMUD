// Code of ShenZhou
// weapon: ���̲���¶���� (Xianglu dao)
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;

inherit BLADE;

void create()
{
        set_name(HIG "�̲���¶��" NOR, ({ "xianglu dao", "xianglu", "dao", "blade" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIG"����һ���񱳱��У������쳣�Ĺ�ͷ�����������⡣\n�������������΢����ȴ�ǳ���Ѭ�졣\n"NOR);
                set("value", 10000);
                set("material", "steel");
                set("rigidity", 2000);
                set("wield_msg", HIG"$Nһ����Ц����������һ�����ᵶ���أ���ǰ�̹�������\n�������ű����ʵ�һ���ȳ���������Ż��֪���⵶��ι�о綾��а���ն�֮����\n"NOR);
                set("unwield_msg", "��������Ѫ�ȳ�ζ��ʧ���٣����̲���¶���� ���ջص��ʡ�\n");
        }
        init_blade(88);
        setup();
        ::create();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        
        if(random(me->query("combat_exp"))>random(victim->query("combat_exp"))){
                victim->apply_condition("xianglu-du", 250);   
                return HIG "$n�����ʵ�һ���ȳ������ž����˿���һ�飡\n" NOR;
        } else {
                return HIM "$n�����ʵ�һ���ȳ��������ڹ��Ͷ����࿹��" NOR;
        }
        
}
