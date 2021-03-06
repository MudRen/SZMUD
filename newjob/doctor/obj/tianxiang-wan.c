#include <ansi.h>

inherit PILL;

void create()
{
        set_name(MAG "天香丸" NOR, ({"tianxiang wan", "wan"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这是一粒天香丸，味道好像怪怪的，但外表很吸引。\n");
                set("value", 10000);
                set("medicine", 1);
        }

        setup();
}

int cure_ob(object me)
{
        if (me->query_condition("cool_drug") > 0){
        me->add("max_neili", -1);
        message_vision(HIR "$N吃下一粒天香丸，只觉得头重脚轻，欲仙欲死，原来服食太急太多，药效适得其反！\n" NOR, me);
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
"$N吃下一粒天香丸，一股清香之气直透丹田，只觉得精神健旺，气血充盈，将疲乏一扫而空! \n" NOR, me);

        me->apply_condition("cool_drug", 30);
        destruct(this_object());
        return 1;
}

