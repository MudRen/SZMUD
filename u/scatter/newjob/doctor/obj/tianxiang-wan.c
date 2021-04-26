#include <ansi.h>

inherit PILL;

void create()
{
        set_name(MAG "������" NOR, ({"tianxiang wan", "wan"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������裬ζ������ֵֹģ�������������\n");
                set("value", 10000);
                set("medicine", 1);
        }

        setup();
}

int cure_ob(object me)
{
        if (me->query_condition("cool_drug") > 0){
        me->add("max_neili", -1);
        message_vision(HIR "$N����һ�������裬ֻ����ͷ�ؽ��ᣬ����������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
        }

        me->set("eff_jing", (int)me->query("max_jing"));
        me->add("jing", 200);
        me->add("jingli", 200);
        me->set("eff_qi", (int)me->query("max_qi"));
        me->add("qi", 200);
//      if (random(3)==1) me->add("max_neili", 3);
//      me->set("neili", (int)me->query("max_neili"));
        
        message_vision(HIG 
"$N����һ�������裬һ������֮��ֱ͸���ֻ���þ���������Ѫ��ӯ����ƣ��һɨ����! \n" NOR, me);

        me->apply_condition("cool_drug", 30);
        destruct(this_object());
        return 1;
}

