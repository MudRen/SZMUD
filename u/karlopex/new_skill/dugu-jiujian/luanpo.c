//chchong 02/02/04
// luanpo.c �����ơ�
 
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
          return notify_fail("��Ķ��¾Ž����������죬�޷��������ơ���\n");
 
     if( me->query_skill("zixia-gong", 1) > me->query_skill("dugu-jiujian",1)  )
          return notify_fail("����ڹ���Ϊ���࣬������Ϊ�����޷��������ơ���\n");
 
     if( !target || !target->is_character() || !me->is_fighting(target) )
          return notify_fail("�����ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
     if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
          return notify_fail("�������޽����������ö��¾Ž���\n");
 
     if( me->query_skill_mapped("force") != "zixia-gong" )
          return notify_fail("�����õ��ڹ��롸���ơ��ķ���㣣�\n");
 
     level = (me->query_skill("dugu-jiujian") + me->query_skill("sword")) / 75;
     if( me->query("max_neili") <= level*300 )
          return notify_fail("���������Ϊ���㣬����������ʩչ�����ơ���\n");
 
    if ( me->query("neili") < 1000 )
          return notify_fail("�����������������������ʩչ�����ơ���\n");
 
    if( me->query("jingli") < 1500 )
          return notify_fail("��ľ������ޣ�������ʩչ�����ơ���\n");
 
     if( me->query_temp("perform/po") )
          return notify_fail("���������ö��¾Ž����ܾ�ʽ���ķ���\n");
     // Jingli is the most important in a perform? are you kidding?
     //damage = ( me->query_skill("parry") + me->query("neili")/20 + me->query("max_neili")/4 )/20;
     //attack = ( me->query_skill("sword") + me->query("jingli")/20 + me->query("max_jingli")/5 )/20
     //      + me->query_dex()/5 + weapon->query("apply/damage")/2;
     damage = (me->query_skill( "sword" ) + me->query_skill( "dugu-jiujian" ))/3;
     attack = (me->query_skill( "sword" ) + me->query_skill( "dugu-jiujian" ))/3+
                me->query_dex()/5 + weapon->query("apply/damage")/2;
    if ( attack < 400 ) attack = 400;
    attack = attack*3/2;
    damage = damage*5/4;
     me->add_temp("apply/damage", damage/2);
     me->add_temp("apply/attack", attack/4);
     me->add_temp("apply/speed", level*5);
 
     if( wizardp(me) ) tell_object( me,
          sprintf("damage: %d, attack: %d, speed: %d, neili cost: %d, jingli cost: %d",
          me->query_temp("apply/damage"), me->query_temp("apply/attack"),
          me->query_temp("apply/speed"), level*70, level*50) );
     m =(3+random(4));
     message_vision(HIW"\n$NĬ�˶��¾Ž������ơ�ʽҪ��������"+weapon->query("name")+"�������ལ�⡣\n"NOR, me);
     for( i=0; i < m ; i++ )
     {
          me->add_temp("perform/luanpo", 1);
          if(i==0)
          {
              message_vision(HIR"\nͻȻ��$N������"+weapon->query("name")+"ָ��" + target->name() + "��������ͦ��������\n"NOR, me);
          }
          else if (i==1)
          {
              message_vision(HIR"\nֻ��$N����"+weapon->query("name")+"ͻȻһת����������ȷ�����У�ָ��" + target->name() + "����һ����\n"NOR, me);
          }
          else if (i==2)
          {
              message_vision(HIR"\n������$N��·ͻ��ὣɨ��" + target->name()+ "��ֱ�����·���\n"NOR, me);
          }
          else if (i==3)
          {
              message_vision(HIR"\n$N�Զ��¾Ž��������򣬽���ԴԴ���ϣ���������һ�д���" + target->name() + "��\n"NOR, me);
          }
          else if (i==4)
          {
              message_vision(HIC"\n$N����"+weapon->query("name")+"Խ��Խ�죬��ʱ������¾Ž��������壬�����������һ�С�\n"NOR, me);
              me->add_temp("apply/attack", attack/4);
              me->add_temp("apply/damage", damage/2);
          }         
          else if(i==5)
          {
              message_vision(HIC"\n$N�Ѿ������¾Ž��ڻ��ͨ����ν��������ʤ���У����¾Ž��н����ˣ�һ��֮������һ����\n"NOR, me);
              me->add_temp("apply/attack", attack/4);
              me->add_temp("apply/damage", damage/2);
          };
          COMBAT_D->do_attack(me, target, weapon);
     }
     message_vision(WHT"\nɲ�Ǽ�$N������"+chinese_number(m)+"�£�����ָ��$nҪ����������ˮһ�㣬��$n�Ƶ�ֻ���м�֮����\n"NOR, me, target);
 
     me->add_temp("apply/damage", -damage/2);
     me->add_temp("apply/attack", -attack/4);
     me->add_temp("apply/speed", -level*5);
     if (i==5) 
     {
         me->add_temp("apply/attack", -attack/4);
         me->add_temp("apply/damage", -damage/2);
     }
     else if (i==6)
     {
         me->add_temp("apply/attack", -attack/2);
         me->add_temp("apply/damage", -damage);
     };
 
    cost = level*50;
    if ( cost > 500 ) cost = 500;
    me->add("neili", -cost);
    me->add("jingli", -cost/2 );
 
     me->delete_temp("perform/luanpo");
    me->start_busy( 1+random(2) );
     return 1;
}
 