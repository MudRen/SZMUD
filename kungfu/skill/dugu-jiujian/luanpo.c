//chchong 02/02/04
// luanpo.c 「乱破」
 
#include <ansi.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
 
     object weapon;
    int cost;
     int i, level, attack, damage, m; 
     weapon = me->query_temp("weapon");
     if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
          weapon = me->query_temp("secondary_weapon");
 
     if( !target && me->is_fighting() ) target = offensive_target(me);
 
     if( me->query_skill("dugu-jiujian", 1) < 150 )
          return notify_fail("你的独孤九剑还不够纯熟，无法领悟「乱破」。\n");
 
     if( me->query_skill("zixia-gong", 1) > me->query_skill("dugu-jiujian",1)  )
          return notify_fail("你的内功修为过多，剑法修为不够无法领悟「乱破」。\n");
 
     if( !target || !target->is_character() || !me->is_fighting(target) )
          return notify_fail("「乱破」只能对战斗中的对手使用。\n");
 
     if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
          return notify_fail("你手中无剑，怎能运用独孤九剑？\n");
 
     if( me->query_skill_mapped("force") != "zixia-gong" )
          return notify_fail("你所用的内功与「乱破」心法相悖！\n");
 
     level = (me->query_skill("dugu-jiujian") + me->query_skill("sword")) / 75;
     if( me->query("max_neili") <= level*300 )
          return notify_fail("你的内力修为不足，劲力不足以施展「乱破」！\n");
 
    if ( me->query("neili") < 1000 )
          return notify_fail("你的内力不够，劲力不足以施展「乱破」！\n");
 
    if( me->query("jingli") < 1500 )
          return notify_fail("你的精力有限，不足以施展「乱破」！\n");
 
     if( me->query_temp("perform/po") )
          return notify_fail("你正在运用独孤九剑「总诀式」心法！\n");
     // Jingli is the most important in a perform? are you kidding?
     //damage = ( me->query_skill("parry") + me->query("neili")/20 + me->query("max_neili")/4 )/20;
     //attack = ( me->query_skill("sword") + me->query("jingli")/20 + me->query("max_jingli")/5 )/20
     //      + me->query_dex()/5 + weapon->query("apply/damage")/2;
     damage = (me->query_skill( "sword" ) + me->query_skill( "dugu-jiujian" ))/3;
     attack = (me->query_skill( "sword" ) + me->query_skill( "dugu-jiujian" ))/3+
                me->query_dex()/5 + weapon->query("apply/damage")/2;
    if ( attack < 400 ) attack = 400;
    attack = attack*8/5;
    damage = damage*5/4;
     me->add_temp("apply/damage", damage/2);
     me->add_temp("apply/attack", attack/2);
     me->add_temp("apply/speed", level*5);
 
     if( wizardp(me) ) tell_object( me,
          sprintf("damage: %d, attack: %d, speed: %d, neili cost: %d, jingli cost: %d",
          me->query_temp("apply/damage"), me->query_temp("apply/attack"),
          me->query_temp("apply/speed"), level*70, level*50) );
     m =(3+random(4));
     message_vision(HIW"\n$N默运独孤九剑「乱破」式要决，手中"+weapon->query("name")+"画出绵绵剑意。\n"NOR, me);
     for( i=0; i < m ; i++ )
     {
          me->add_temp("perform/luanpo", 1);
          if(i==0)
          {
              message_vision(HIR"\n突然间$N将手中"+weapon->query("name")+"指向" + target->name() + "出招破绽挺剑疾出。\n"NOR, me);
          }
          else if (i==1)
          {
              message_vision(HIR"\n只见$N手中"+weapon->query("name")+"突然一转，看似无招确是有招，指向" + target->name() + "就是一剑。\n"NOR, me);
          }
          else if (i==2)
          {
              message_vision(HIR"\n紧跟着$N剑路突变横剑扫向" + target->name()+ "简直不成章法。\n"NOR, me);
          }
          else if (i==3)
          {
              message_vision(HIR"\n$N对独孤九剑有所感悟，剑招源源不断，随手又是一招刺向" + target->name() + "。\n"NOR, me);
          }
          else if (i==4)
          {
              message_vision(HIC"\n$N手中"+weapon->query("name")+"越用越快，登时领悟独孤九剑剑法精义，随意出剑即是一招。\n"NOR, me);
              me->add_temp("apply/attack", attack/4);
              me->add_temp("apply/damage", damage/2);
          }         
          else if(i==5)
          {
              message_vision(HIC"\n$N已经将独孤九剑融会贯通，所谓剑中无招胜有招，独孤九剑有进无退，一剑之后又是一剑。\n"NOR, me);
              me->add_temp("apply/attack", attack/4);
              me->add_temp("apply/damage", damage/2);
          };
          COMBAT_D->do_attack(me, target, weapon);
     }
     message_vision(WHT"\n刹那间$N连攻了"+chinese_number(m)+"下，招招指向$n要害如行云流水一般，将$n逼的只有招架之力。\n"NOR, me, target);
 
     me->add_temp("apply/damage", -damage/2);
     me->add_temp("apply/attack", -attack/2);
     me->add_temp("apply/speed", -level*5);
     if (i==5) 
     {
         me->add_temp("apply/attack", -attack/4);
         me->add_temp("apply/damage", -damage/2);
     }
     else if (i==6)
     {
         me->add_temp("apply/attack", -attack/2);
         me->add_temp("apply/damage", -damage/2);
         me->add_temp("apply/damage", -damage/2);
     };
 
    cost = level*50;
    if ( cost > 500 ) cost = 500;
    me->add("neili", -cost);
    me->add("jingli", -cost/2 );
 
     me->delete_temp("perform/luanpo");
    if ( me->query_temp( "apply/attack")<0 ) me->set_temp( "apply/attack", 0 );
    me->start_busy( 1+random(2) );
     return 1;
}
 
