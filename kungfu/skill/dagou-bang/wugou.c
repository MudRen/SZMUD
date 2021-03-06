// Code of ShenZhou
//wugou.c 打狗棒法「天下无狗」
//code by slow

#include <ansi.h>
#include <armor.h> 
#include <combat.h> 

inherit F_DBASE;
inherit F_SSERVER;
string *wugou_msg=({
HIY"$N冷笑一声，将棒端一沉由下向上撩起，一式“拨狗朝天”此时使出来，却有无尽妙用。\n"NOR,
HIY"$N内力外吐，那棒竟然弯曲过来，棒端如毒蛇出洞般以迅雷不及掩耳之势窜向$n面门。\n"NOR,
HIY"$N一招未毕次招又至，变点为刺。手中棒如银枪般,棒头乱晃舞成一圈光影向着$n当胸扎来。\n"NOR,
HIY"$N运足内力，刚刚还是变化无穷的招式，此时竟毫无花哨，直取眉心，令$n大出意外。\n"NOR,
HIY"$N手中棒忽然变得灵巧无比，象是粘在$n身上一样，无论$n焛转腾挪那棒总是如影随至般攻到，实在是令人匪夷所思。\n"NOR,
HIY"$N一气呵成「天下无狗」最后一式,刹那间漫天棒影罩住$n，把打狗棒法发挥到极致 !\n"NOR});

int perform(object me, object target)
{
        int ap,dp,pp;
        int i,enfor;
        int num;
        string msg;
        int damage,skill;

        if( !target ) target = offensive_target(me);

        if( me->query("wugou") < 60)
                return notify_fail("你还没学会「天下无狗」。\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「天下无狗」只能对战斗中的对手使用。\n");

        if( target->is_busy() ) {
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("你已在使用绊字诀！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("你所用的并非混天气功，无法施展「天下无狗」！\n");

          if( me->query_skill("force") <450 )
                return notify_fail("你的混天气功火候未到，无法施展「天下无狗」。n");


	if ( me->query_skill("stick") < 500 )
                return notify_fail("你的打狗棒法修为不足，还不会使用「天下无狗」！\n");

        if( me->query("max_neili") < 8000 || me->query("neili") <3000 )
                return notify_fail("你的内力修为不够，无法使用「天下无狗」！\n");
        if( me->query("max_jingli") < 5000 || me->query("jingli") < 2000)
                return notify_fail("你的精力不足，无法使用「天下无狗」！\n");
        if( !me->query("rank") || me->query("rank") < 9)
                return notify_fail("你在丐帮级别太低了吧 ！\n");
        message_vision(HIW"$N竹棒抖动，将一路“打狗棒法”使得变法无方，棒法精义渐渐显现出来,随手一招，妙绝天下！\n",me,target);
        message_vision(HIG"这正是打狗棒法的绝招「天下无狗」,据说共六种变化，这一招仗将出来，四面八方是棒,劲力所至，\n",me,target);
        message_vision(HIG"便有几十条恶犬也一齐打死了，所谓“天下无狗”便是此义，棒法之精妙绝伦，已臻武学中的绝诣!\n"NOR,me,target);
        ap = COMBAT_D->skill_power(me,"stick", SKILL_USAGE_ATTACK)/1000 + 1; 
        pp = COMBAT_D->skill_power(target,"parry", SKILL_USAGE_ATTACK)/1000 + 1; 
        dp = COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_ATTACK)/1000 + 1; 
        num = me->query("wugou");
        if (wizardp(me) ) printf("ap = %d ,dp =%d ,pp =%d \n",ap,dp,pp);
        skill = me->query_skill("stick") + me->query_skill("huntian-qigong",1);
        if ( skill >1200 ) skill = 1200;
        if (num < 100) num = 3;
        else if (num <200) num =4;
        else if (num <500) num =5;
        else num = 6;
        enfor = (me->query("jiali") + me->query("jiajin") )/2;
        for (i=0;i<num;i++)
        {
        if (i == 5) break;
        damage = skill/10 + skill*(10-i)/100 + random(enfor/2);
        damage = damage /2 + random(damage);   
        if (damage > 400) damage = 400;
        if (damage < 180) damage = 180;
        if (wizardp(me)) printf("i = %d,damage = %d\n",i,damage);
        me->add_temp("apply/damage",damage);
        me->add_temp("apply/attack",damage);
        msg = wugou_msg[i];
        message_vision(msg,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->add_temp("apply/damage",-damage);
        me->add_temp("apply/attack",-damage);
        }
        if (num==6 && ap > random((pp+dp)/2) )
        {
            call_out("last_hit",1,me,target);
        }
           me->add("neili",-250);
        me->start_busy(2+random(num/2));
        return 1;
}
void last_hit(object me,object target) 
{
        object weapon;
          if( !objectp(weapon = me->query_temp("weapon")) ||(!target) )   return;
              message_vision(wugou_msg[5],me,target);
              target->receive_damage("qi", 1000 + random(2000),  me);
                 target->receive_wound("qi",500+random(500), me);
                  COMBAT_D->report_status(target);  
}
