                   //太极绵掌 (防守性)

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{       
        string msg;
        int skill, intActTime, intParry, intOther;

                if(!me->query("can/mian-zhang"))
                        return notify_fail("测试完毕暂时停止这个 PERFORM, 请把你的感想 POST 到武当留言版\n");
        
        if( !target ) target = offensive_target(me);
                
                //if( me->query_temp("mian-zhang/yunhuakai") )
        //              return notify_fail("你现在不能使出「太极绵掌」。\n");

        if( me->query_temp("mian-zhang/tjmz"))
                return notify_fail("你已经在出「太极绵掌」了。\n");
        
        if( objectp(me->query_temp("weapon")) ) 
                return notify_fail("空手才能施展太极绵掌！\n");
        
        if( me->query_skill_mapped("strike") != "mian-zhang" )
                return notify_fail("你所用的并非花开并蒂，不能施展花开并蒂！\n");

        if( me->query_skill_prepared("strike") != "mian-zhang" )
        return notify_fail("你所备的并非绵掌，不能施展太极绵掌！\n");

                if( me->query_skill_prepared("cuff") != "taiji-quan" )
        return notify_fail("你所备的并非太极拳，不能施展太极绵掌！\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("你所用的并非太极神功，使不出太极绵掌！\n");

        if( me->query_skill("mian-zhang", 1) < 99)
                return notify_fail("你的绵掌不够纯熟，尚未能出此绝招。\n");
        
        if( me->query_skill("taiji-shengong", 1) < 79)
                return notify_fail("你的太极神功修为不够，不能出「太极绵掌」。\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不足,无法使用「太极绵掌」\n");

        if (me->query("neili") < 500)
                return notify_fail("你的内力不够,无法使用「太极绵掌」\n");

        if( (int)me->query("jiali") > 2 || (int)me->query("jiajin") > 2)
                return notify_fail("你发现加力后无法把绵掌中若有若无，借力打力的要决发挥出来。\n");
                
                
      msg = HIY"\n$N双掌一翻，装做若无其事的样子，左手阴，右手阳，此乃是武当精髓借力打力的架式。\n\n"NOR;

        message_vision(msg, me, target); 

        me->add("neili", -500);
        me->add("jingli", -40);
                me->set_temp("mian-zhang/tjmz", 1);

                intActTime = me->query_skill("taiji-shengong", 1) / 3 * 2;
                intParry = me->query_skill("mian-zhang", 1) + me->query_skill("taiji-quan", 1) + me->query_skill("taiji-shengong", 1);
                intParry = intParry / 2;
                intOther = intParry / 3;
                        
                me->set_temp("apply/parry", intParry);
                me->set_temp("apply/damage", intOther);
                me->set_temp("apply/attack", intOther);
                me->set_temp("apply/defense", intOther);
                me->set_temp("apply/speed", intOther);
                me->set_temp("apply/dodge", -1000);
                
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), intActTime);
                
        return 1;
}

void remove_effect(object me)
{
        me->delete_temp("apply/parry");
        me->delete_temp("apply/damage");
        me->delete_temp("apply/attack");
        me->delete_temp("apply/defense");
        me->delete_temp("apply/speed");
        me->delete_temp("mian-zhang/tjmz");
        me->delete_temp("apply/dodge");

        message_vision(HIW"$N将借力打力的架式收回，$N将内力收回丹田。\n", me); 
        return;
}
