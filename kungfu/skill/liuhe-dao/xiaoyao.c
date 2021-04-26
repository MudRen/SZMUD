// Code of ShenZhou
// xiaoyao.c ��ң��Ӱ

#include <ansi.h>

#define FAKE_OBJ "/d/gaibang/obj/fobj.c"


void AddFight(int, object, object, object);

void create()
{
  seteuid(getuid());
}

int perform(object me, object target)
{
  int WorkTime, AtkNum, Total;
  object env, fakeobj;
  object *inarray;
  string name;
  
  inarray = ({0, 0 , 0, 0, 0, 0, 0, 0, 0});
  
  if(me->query_temp("AlreadyPfmXiaoyao")) return notify_fail("���Ѿ���ʹ����ң��Ӱ�ˡ�\n");
  
  if( !target )
    return notify_fail("��Ҫ��˭ʹ����ң��Ӱ��\n");

//  if( !target ) target = offensive_target(me);
  if( !target->is_character()
      || !me->is_fighting(target) )
    return notify_fail("��ң��Ӱֻ�ܶ�ս���еĶ���ʹ�á�\n");

  if( (int)me->query_skill("huntian-qigong", 1) < 125 )
    return notify_fail("��Ļ���������Ϊ������\n");

  if( (int)me->query_skill("xiaoyaoyou", 1) < 125 )
    return notify_fail("�����ң����Ϊ������\n");

  if( (int)me->query_skill("liuhe-dao", 1) < 125 )
    return notify_fail("������ϵ�������������.\n");
    
   if( (int)me->query("max_neili") < 500 )
      return notify_fail("���������Ϊ������\n");

   if( (int)me->query("neili") < 150 )
      return notify_fail("�������������\n");

  // Here should change description
  if(random(2))
    message_vision( HIY
     "��Ȼ$Nһ������������һֻ���ࡢһֻ��ӥ�������һ�㣬��̼仯��������Ӱ������$n�ۻ����ҡ�\n"NOR, me, target);
  else 
    message_vision( HIY
      "ֻ��$N˫����㣬������裬������Ծ�����鶯���࣬���Ǻ��߹��ġ���ң��Ӱ������\n"NOR, me);

  me->add("neili", -40);
  me->add("jingli", -20);

  env = environment(me);
  name = "Fake_Image";

  if(!objectp(fakeobj = present(name, env))) {
    fakeobj=new(FAKE_OBJ);
    fakeobj->move(env);
    inarray[0] = me;
    AtkNum = 1;
    Total = 1;
  }
  
  else if(objectp(fakeobj = present(name, env))){
    AtkNum = fakeobj->query("attacker")[1];
    Total = fakeobj->query("attacker")[2];
    inarray = fakeobj->query("attacker")[0];
    for(int i = 0; i< Total+1; i++) {
      if(inarray[i] == 0) {
        inarray[i] = me;
        break;
      }
    }
    AtkNum++;
    Total++;
  }

  fakeobj->set("attacker", ({ inarray, AtkNum, Total }) );
  fakeobj->set("rider", me); // for invisible
  fakeobj->set_leader(me);
  
  me->set_temp("AlreadyPfmXiaoyao", 1);
  me->set_temp("cannot_perform", 1);
  WorkTime = (int)me->query_skill("liuhe-dao") / 20;
  call_out("AddFight", 1, WorkTime, target, fakeobj, me);

  return 1;
}


void AddFight(int WorkTime, object target, object fakeobj, object attacker)
{
  object weapon, *inarray;
  int Total, AtkNum, i;
  
  if(WorkTime == 0 || !attacker->is_fighting()
     || attacker->query_skill_mapped("blade") != "liuhe-dao" 
     || !objectp(weapon = attacker->query_temp("weapon")) 
     || (string)weapon->query("skill_type") != "blade" ) 
  {
    message_vision( HIY
    "��ң��Ӱ����ʹ��ϣ�$N�ѷ�����أ�������Ʈ��֮����\n" NOR, attacker);
    attacker->delete_temp("AlreadyPfmXiaoyao");
    attacker->delete_temp("cannot_perform");
    if(fakeobj->query("attacker")[1] != 0) {
      Total = fakeobj->query("attacker")[2];
      inarray = fakeobj->query("attacker")[0];
      AtkNum = fakeobj->query("attacker")[1];
      for(i = 0; i<Total; i++) {
        if(inarray[i] == attacker) inarray[i] = 0;
        break;
      }
      AtkNum--;
      fakeobj->set("attacker", ({ inarray, AtkNum, Total }) );
    }

    if(fakeobj->query("attacker")[1] == 0) destruct(fakeobj);
    return;
  }

  else {
    if( !attacker->is_busy())
      COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"), 1);
  
    call_out("AddFight", 1, WorkTime-1, target, fakeobj, attacker);
  }
  
  
  
  return;
}

