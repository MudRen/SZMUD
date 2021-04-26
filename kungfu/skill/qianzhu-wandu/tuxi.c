// Code of ShenZhou
// ǧ����ͻϮ
// chu@xkx   3/6/99

// Apache: modified so that player can't perform it continuously.
// Other parts wait for chu for balancing.

inherit F_SSERVER;
#include <ansi.h>

void remove_temp(object me) {
	if (me->query_temp("perform_tuxi"))
		me->delete_temp("perform_tuxi");
}

int perform(object me, object target)
{
  string msg; 
  int finger, ap, dp, dodge, parry, damage, poison;

  if (me->query_temp("perform_tuxi")) {
  	return notify_fail("���ͻϮ�ѱ��Է��������һ�°ɡ�\n");
  }

  if ( !target ) target = offensive_target(me);

  if( !target || !target->is_character())
    return notify_fail("����ͻϮ˭?\n");

  if( environment(target)->query("no_fight"))
    return notify_fail("���ﲻ��͵Ϯ��\n");
    
  if(target->query_temp("surrender/ownder")!=0)
    return notify_fail("�����ڲ���͵Ϯ��!");
    
  if(target->query("combat_exp") < me->query("combat_exp"))
    return notify_fail("û�б�Ҫ��ǧ������ɱ�ɣ�\n");

if( (finger = (int)me->query_skill("qianzhu-wandu", 1)) < 100 )
    return notify_fail("���ǧ�����ֲ�������.\n");

  if (me->query("neili") < 1000)
        return notify_fail("�������������.\n");

  msg = "$N��$n����, ��Ȼ��ת��, �ӱ����ָͻϮ��\n\n";
  dodge = target->query_skill("dodge", 1);
  parry = target->query_skill("parry", 1);
  poison = target->query_skill("qianzhu-wandu", 1);
  ap = me->query("combat_exp")*10+finger*finger*finger;
  dp = target->query("combat_exp")*10+dodge*dodge*dodge+parry*parry*parry+poison*poison*poison;
  dp = dp/3;
  damage = finger + me->query("neili")/20;
  damage += random(damage/2);

  if (random(ap) > dp/2) {
        msg += "ֻ��$n�ƺ���һ��, �����ѱ�$Nָ������.\n";
        target->start_busy(1+random(2));
        target->receive_wound("qi", damage, me);
        target->apply_condition("qianzhu-poison", 
            damage/10+target->query_condition("qianzhu-poison"));
        if(target->query("poisoner") != me) target->set("poisoner", me);
        target->set_temp("last_damage_from", me);
  }else {
        msg += "����$n���з���, ������.\n";
        me->start_busy(1+random(3));
  }
  if (! target->killing_ob(me))  target->kill_ob(me);
  me->add("neili", -damage);

  me->set_temp("perform_tuxi", 1);  
  call_out("remove_temp", 5, me);
  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
