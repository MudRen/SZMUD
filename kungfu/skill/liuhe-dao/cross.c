// Code of ShenZhou
// cross.c  // ʮ�ֿ�

#include <ansi.h>
inherit F_SSERVER;

void AddFight(int, object, object, object);

int perform(object me, object target)
{
  int WorkTime;
  object SecWeapon, *inv;
  string str;
  
  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() || !me->is_fighting(target) )
     return notify_fail("ʮ�ֿ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

  if( (int)me->query_skill("huntian-qigong", 1) < 150 )
    return notify_fail("��Ļ���������Ϊ������\n");

  if( (int)me->query_skill("liuhe-dao", 1) < 150 )
    return notify_fail("������ϵ�������������.\n");
    
  if( (int)me->query("max_neili") < 500 )
    return notify_fail("���������Ϊ������\n");

  if( (int)me->query("neili") < 150 )
    return notify_fail("�������������\n");

  inv = all_inventory(me);
  
  for(int i = 0; i < sizeof(inv); i++) {
    if(!inv[i]->query("equipped") && inv[i]->query("skill_type") == "blade" ) {
      SecWeapon = inv[i];
      break;
    }
  }
  
  if(!SecWeapon) return notify_fail("������û�ж���ĵ���\n");
  
  if(!stringp(str = SecWeapon->query("wield_msg")) )
    str = "$N��ৡ���һ�����һ��$n�������С�\n";

        message_vision(str, me, SecWeapon);

  if(random(2))
    message_vision( HIG
      "�����ߵ��������죬$N˫�����������Ʈ����ǰ����$n����������\n"
      "������$N����������ʮ�ֿ�������֪�ж��ٽ����ú���ɥ���ⶾ��֮�¡�\n"NOR, me, target);
  else 
    message_vision( HIG
      "$N���һ����ͻȻͦ��$n"+HIG"������˫�����·��ɣ����һ�Ű׹⣬ʹ����ʮ�ֿ������������ơ�\n"NOR, me, SecWeapon);

  me->add("neili", -80);
  me->add("jingli", -20);

  SecWeapon->set("equipped", 1);
  if(SecWeapon->query("no_drop") ) SecWeapon->set("no_drop", 10);
  
  me->set_temp("cannot_perform", 1);
  WorkTime = (int)me->query_skill("liuhe-dao") / 20;
  call_out("AddFight", 1, WorkTime, target, SecWeapon, me);

  return 1;
}


void AddFight(int WorkTime, object target, object SecWeapon, object attacker)
{
  object weapon;
  string str;
  
  if(WorkTime == 0 || !attacker->is_fighting() || !target 
     || !target->is_character() || !attacker->is_fighting(target)
     || attacker->query_skill_mapped("blade") != "liuhe-dao" 
     || !objectp(weapon = attacker->query_temp("weapon")) 
     || (string)weapon->query("skill_type") != "blade" )
  {
    message_vision( HIY
    "ͻȻ��$N˫��������ʮ�ֿ�����Ȼ�бϣ��һ���죬������$n"+HIY"��\n" NOR, attacker, SecWeapon);

    attacker->delete_temp("cannot_perform");
          
                if( !stringp(str = SecWeapon->query("unwield_msg")) )
      str = "$N�����е�$n��ص��ʡ�\n";
        message_vision(str, attacker, SecWeapon);
    
    SecWeapon->delete("equipped");
    if(SecWeapon->query("no_drop") == 10) SecWeapon->set("no_drop", 1);
    else SecWeapon->delete("no_drop");
    return;
  }

  else {
    if( !attacker->is_busy()) {
//      weapon = attacker->query_temp("weapon");
//      attacker->set_temp("weapon", SecWeapon
//      COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"), 1);
      COMBAT_D->do_attack(attacker, target, SecWeapon, 1);
    }
    
    call_out("AddFight", 1, WorkTime-1, target, SecWeapon, attacker);
  }
  
  
  
  return;
}


