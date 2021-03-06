// Code of ShenZhou
// san.c 一拍两散
/*
玄寂适才所出那一掌，实是毕生功力之所聚，叫作“一拍两散”，
所谓“两散”，是指拍在石上，石屑四“散”、拍在人身，魂飞
魄“散”。这路掌法就只这么一招，只因掌力太过雄浑，临敌时
用不着使第二招，敌人便已毙命，而这一掌以如此排山倒海般的
内力为根基，要想变招换式，亦非人力之所能。
*/
// Modified by Felix 5/2002

inherit F_SSERVER;
#include <ansi.h>
#include <armor.h>
#include <combat.h>

int perform(object me, object target)
{
        int org_enfor, enfor, hit1, hit2;
        int ap,dp;
        int damage;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("一拍两散只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") )
                return notify_fail("你只能在空手时使用一拍两散！\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi" )
                return notify_fail("你所用的并非混元一气功，无法施展一拍两散！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 180)
                return notify_fail("你的混元一气功火候未到，无法施展一拍两散！\n");

        if( me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("你的般若掌火候未到，无法施展一拍两散！\n");

        if( me->query_skill("buddhism", 1) < 180 )
                return notify_fail("你的佛学修为不够，无法施展一拍两散！\n");

        if( me->query("max_neili") <= 1000 )
                return notify_fail("你的内力修为不足，劲力不能运发，无法施展一拍两散！\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query("jingli") < 500  )
                return notify_fail("你的精力不够。\n");

         ap = me->query("combat_exp");
         dp = target->query("combat_exp");
         ap = (ap + random(ap*2))/ 2;
        
         org_enfor = me->query("jiali");

         if (!target->query_temp("sl/san"))
			damage = 1000 + me->query("max_qi") + me->query("max_qi")*org_enfor/700;
         else if (target->query_temp("sl/san") == 1)
			damage = 100 + me->query("max_qi") * org_enfor / 3000;
         else damage = 100;
message_vision(HIW"$N双掌自外向里转了个圆圈，缓缓向$n推了过来。$N掌力未到，$n已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至！\n"NOR,me,target);
         if (ap > dp)
         {
			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", damage/3+random(damage/2), me);
            target->add_temp("sl/san",1);
            COMBAT_D->report_status(target);
         }
         else
         {
message_vision(HIW"$n感到$N掌力浑厚异常，知道厉害，不敢硬接，只有十分狼狈的避开！\n"NOR,me,target);
         }
         if (me->query("neili")>2500)
			me->add("neili",-(2000+org_enfor));
         else me->set("neili",10);
            me->start_busy(4+random(4));
         return 1;
}
