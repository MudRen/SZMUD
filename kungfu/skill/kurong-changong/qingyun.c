/*
[1] dali fix report                          灵儿(lnere)(Mon May 20)
----------------------------------------------------------------------
         大理
        基本轻功--段氏身法
           原有功能：无
           修改功能：perform qingyun （青云直上）
                 条件：段氏身法有效等级100、枯荣禅功有效等级100。
                        功能：提高临时jifa dodge 10%。
                        限制：时长：5-10tick。
                        内功所需：100/次。
***********************************************************************
snowyu by 2002/5
*/

#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string msg;
        int i, extra;

        if( me->query_temp("qingyun") )
                return notify_fail("你正在运用「青云直上」心法！\n");

        if( me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("你所用的内功与「青云直上」心法相悖！\n");

        if( me->query_skill("kurong-changong", 1) < 100 )
                return notify_fail("你的内功修为火候未到，还未领悟「青云直上」！\n");

        if( me->query("neili") < 1000 )
                return notify_fail("你的内力不够，劲力不足以施展「青云直上」！\n");
        
        if( me->query_skill("duanshi-shenfa", 1) < 100 )
                return notify_fail("你的段氏身法修为不够，还未领悟「青云直上」！\n");

        msg= HIW"$N忽然脸色一变，双目一闭,运起枯荣心法，全身真气运转三个周天，身行骤然加快, 有如御风而行。\n" NOR;
     
        me->add("neili", -100);
        me->add("jingli", -100);
        
        extra = ((int)me->query_skill("kurong-changong",1)+(int)me->query_skill("duanshi-shenfa",1))/2;
		
		me->add_temp("apply/dodge", extra/5);


        me->set_temp("qingyun", 1);
        call_out("remove_effect", extra/5, me, extra);
		message_vision(msg, me);
     
		return 1;
}

 

void remove_effect(object me, int extra)
{
        if (!me) return;
        me->add_temp("apply/dodge", -extra/5);
        me->delete_temp("qingyun");
		message_vision(HIW"$N只觉枯荣心法渐渐散去,身法渐渐慢了下来。\n"NOR,me);
}
