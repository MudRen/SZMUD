// Code of ShenZhou
// zhuan.c �򹷰�ת�־�
// fear@xkx 2001.7

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

private int error_checking(object me, object target);
int effect_one(object me, object target, object weapon, int succeed);
int effect_two(object me, object target, object weapon, int succeed);
int effect_three(object me, object target, object weapon, int succeed);
int jump_around(object me, object target);
private int remove_effect(object me, object target, int zhuan_busy);

int perform(object me, object target)
{
  string* msghit, msg;
  object weapon;
  int ranNum, succeed;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  string *limb, type, limb_hurt;

  
  if( !target ) target = offensive_target(me);

  if(error_checking(me, target) == -1) return -1;
 
  if( !objectp(weapon = me->query_temp("weapon")) )
    return notify_fail("�������ʹ��ת�־�����\n");
  

  if (random(me->query("combat_exp")) * me->query_skill("stick") > 
      random(target->query("combat_exp")) * (target->query_skill("dodge")+ 
      target->query_skill("parry"))/3)
      succeed = 1;
  
  effect_one(me, target, weapon, succeed);
  //effect_two(me, target, weapon, succeed);
  //effect_three(me, target, weapon, succeed);
  
  /*ranNum == random(3);
  
  if( ranNum == 1) effect_one(me, target, weapon, succeed);
  else if( ranNum == 2 ) effect_two(me, target, weapon, succeed);
  else effect_three(me, target, weapon, succeed);*/

  return 1;
}

private int error_checking(object me, object target)
{
  string msg;
  
  if( !wizardp(me) )
    msg = "�㲻�ǻ��أ�����ʹ�á�ת�־�����\n";

  else if( !target || !target->is_character()
      || !me->is_fighting(target)
      || !living (target) )
    msg = "ת�־�ֻ�ܶ�ս���еĶ���ʹ�á�\n";

  else if( target->is_busy() ) {
    me->add("neili", -10);
    me->add("jingli", -5);
    msg = target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n";
  }

  else if( me->query_temp("ban",1) )
    msg = "������ʹ��ת�־���\n";

  else if( me->query_temp("pfmfeng",1) )
    msg = "������ʹ��ת�־���\n";

  else if( me->query_temp("zhuan",1) )
    msg = "������ʹ��ת�־���\n";

  else if( me->query_skill_mapped("force") != "huntian-qigong" )
     msg = "�����õĲ��ǻ����������޷�ʩչת�־���\n";

  else if( me->query_skill("huntian-qigong") < 100 )
    msg = "��Ļ����������δ�����޷�ʩչת�־���\n";

  else if( me->query_skill("dagou-bang") < 100 )
    msg = "��Ĵ򹷰�����Ϊ���㣬������ʹ��ת�־���\n";

  else if( me->query("neili") <= 1000 )
    msg = "�������������\n";

  else if( me->query("jingli") <= 600 )
    msg = "��ľ���������\n";
    
  else return 0;
  
  tell_object(me, msg);
  return -1;  
}

/*******************************************************************************
effect 1 (dianxue):
------------------
perform:
$N����һ�䣬+ weapon->name()+������һ�ű�Ӱ���͵�$n���ġ�ǿ�䡱�����縮��������׵��������̨���������ࡱ����ҪѨ��

fail:
(1)$nʶ��������������ǰ��Ծ���ܡ�
// this looks like succeed.(2)$n�޷���ʩ��ֻ����ǰ���ݣ�ȴ�Ǳܿ�ǰ�������������

success (hurt without dianxue):
(1)$n�����������Լ����񣬾���$P��+limb_hurt+�ϴ���һ�£�����δ�����Ѩ����ȴҲ����ʹ���á�
// this one looks like fail (2)$n������һ�£�����Σ���м���Ѩ������δ�����ˡ�

success (dianxue):
(1)$nһ�������������˵���+xuedao name
(2)ֻ�������۵ش���$n��+xuedao name

xuedao name ="ǿ��","�縮","��׵","��̨","����"
*******************************************************************************/

int effect_one(object me, object target, object weapon, int succeed)
{
  string* msghit;
  string msg, color;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  string *xuedaoName = ({"ǿ��","�縮","��׵","��̨","����"});
  
  msg = HIG "\n" + "$N����һ�䣬" + weapon->name()+ 
    "������һ�ű�Ӱ���͵�$n���ġ�ǿ�䡱�����縮��������׵��������̨���������ࡱ����ҪѨ��\n"NOR;

  message_vision(msg, me, target);
  
  if(succeed) {
    msghit = ({ "\n$n�����������Լ����񣬾���$P��+limb_hurt+�ϴ���һ�£�����δ�����Ѩ����ȴҲ����ʹ���á�\n",
                "\n$nһ�������������˵���"+ xuedaoName[random(5)] + "\n",
                "\nֻ�������۵ش���$n��" + xuedaoName[random(5)] + "\n" });

    msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;

    zhuan_busy= me->query_skill("stick")/15;

    target->add("qi",-me->query_skill("stick")/5);
    target->add("jing",-me->query_skill("stick")/10);
    target->add("jingli",-me->query_skill("stick")/10);
    target->start_busy(zhuan_duration);
    me->set_temp("zhuan",1);

    //me->start_busy( 1 + random(2));
    zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);

    //call_out("jump_around", 1, me, target);

    if(me->is_fighting() && target->is_fighting()) 
      call_out("effect_two", 1, me, target, weapon, succeed);
    
    else me->start_call_out( (: call_other, __FILE__, "remove_effect", 
      me,target, zhuan_busy :), zhuan_duration);

  }
  
  else {
    msg = CYN"\n$nʶ��������������ǰ��Ծ���ܡ�\n" NOR;
    me->start_busy( 1 + random(3));
    me->add("qi", -me->query_skill("stick")/5);
    message_vision(msg, me, target);
    me->delete_temp("zhuan");
  }

  zhuan_cost = me->query_skill("stick") / 2;
  me->add("neili", -zhuan_cost );
  me->add("jingli", -zhuan_cost/2 );  
}

/*******************************************************************************
effect 2 (drop jingli/qi):
------------------------
perform:
(1)$N΢΢һЦ��ʹ���ˡ�ת���־����Ӱ���$n���Ϻ�ɨ��ȥ����Ю���磬���Ǿ����� 
(2)$N��$n�������������ˣ�+ weapon->name()+�ش���ʹ����ת���־�����$n������ȥ�� 

fail:
$næ������ܣ������ܿ���$n��һ�С� 

success:
(1)$n���ܲ��������ϱ�ɨ�У������������ң�ί���ڵء� 
(2)$n���㲻�ȣ���ʱ�˵ص����� 
*******************************************************************************/

int effect_two(object me, object target, object weapon, int succeed)
{
  string* msghit;
  string msg, color;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  
  msghit = ({ "\n$N΢΢һЦ��ʹ���ˡ�ת���־����Ӱ���$n���Ϻ�ɨ��ȥ����Ю���磬���Ǿ�����\n",
         "\n$N��$n�������������ˣ�" + weapon->name()+ "�ش���ʹ����ת���־�����$n������ȥ��\n" });
  msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
  message_vision(msg, me, target);

  if(succeed) {
    msghit = ({ "\n$n���ܲ��������ϱ�ɨ�У������������ң�ί���ڵء�\n",
                "\n$n���㲻�ȣ���ʱ�˵ص�����\n" });

    msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;

    zhuan_busy= me->query_skill("stick")/15;

    target->add("qi",-me->query_skill("stick")/5);
    target->add("jing",-me->query_skill("stick")/10);
    target->add("jingli",-me->query_skill("stick")/10);
    me->set_temp("zhuan",1);

    //me->start_busy( 1 + random(2));
    zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);

    call_out("jump_around", 1, me, target);

    if(me->is_fighting() && target->is_fighting()) 
      call_out("effect_three", 1, me, target, weapon, succeed);
    
    else me->start_call_out( (: call_other, __FILE__, "remove_effect", 
      me,target, zhuan_busy :), zhuan_duration-1);

  }
  
  else {
    msg = CYN"\n$næ������ܣ������ܿ���$N��һ�С� \n" NOR;
    me->start_busy( 1 + random(3));
    me->add("qi", -me->query_skill("stick")/5);
    message_vision(msg, me, target);
    me->delete_temp("zhuan");
  }

  zhuan_cost = me->query_skill("stick") / 2;
  me->add("neili", -zhuan_cost );
  me->add("jingli", -zhuan_cost/2 );
}

/*******************************************************************************
effect 3 (jump around):
-----------------------
perform:
(1)$Nʹ���ˡ�ת���־���������಻�ϣ�һ�㲻�У��ֵ�һѨ����Ӱֻ��$n�����Ѩ�ϻ�����ȥ�� 
(2)$N�ֱ۶������ѱ�Ϊ��ת���־��������������������󼱻�СȦ�������ݰ㼱����ת�� 

fail:
(1)$n��ȻԾ�ߣ����ڰ�գ�����ץס���ˣ�+weapon->name()+��ʱ�㲻ת�ˣ�$N������ˤ�˳�ȥ�� 
(2)$Nʹ�����أ�ʧ������֮�£���$nһ��ץס���⣬��˳��һ�����������˴���ֱˤ�˳�ȥ�� 

success:
(1)$N���󶶵����죬$nת��Ҳ�����죬����+ weapon->name()+�������ݵĳ�����Ҳ�Ǹ��ŵ��������ת�� 
(2)$n���¼Ӿ��������û�ת����$p��Ծ���죬�������������� 
(3)$n����$N�ɱ���Ծ����תȦ�ӣ��ٰ�����$n���ġ�Ȧ��ԽתԽ�󣬱Ƶ����˲��ò����ܡ� 
******************************************************************************/

int effect_three(object me, object target, object weapon, int succeed)
{
  string* msghit;
  string msg, color;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  
  msghit = ({ "\n$Nʹ���ˡ�ת���־���������಻�ϣ�һ�㲻�У��ֵ�һѨ\n" + 
      "����Ӱֻ��$n�����Ѩ�ϻ�����ȥ��\n",
              "\n$N�ֱ۶������ѱ�Ϊ��ת���־��������������������󼱻�\n" + 
      "СȦ�������ݰ㼱����ת��\n" });
  msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
  message_vision(msg, me, target);

  if(succeed) {
    message_vision(HIY"\n$N���¼Ӿ��������û�ת����$N��Ծ���죬��������������\n", target);

    zhuan_busy= me->query_skill("stick")/15;

    target->add("qi",-me->query_skill("stick")/5);
    target->add("jing",-me->query_skill("stick")/10);
    target->add("jingli",-me->query_skill("stick")/10);
    me->set_temp("zhuan",1);

    me->start_busy( 1 + random(2));
    zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);

    call_out("jump_around", 1, me, target);

    me->start_call_out( (: call_other, __FILE__, "remove_effect", 
      me,target, zhuan_busy :), zhuan_duration-2);

  }
  
  else {
    msghit = ({	"$n��ȻԾ�ߣ����ڰ�գ�����ץס���ˣ�"+(string)weapon->name()+"
��ʱ�㲻ת�ˣ�$N������ˤ�˳�ȥ��\n",
                "$Nʹ�����أ�ʧ������֮�£���$nһ��ץס���⣬��˳��һ����������
�˴���ֱˤ�˳�ȥ��\n" });
    msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
    me->start_busy( 1 + random(3));
    me->add("qi", -me->query_skill("stick")/5);
    message_vision(msg, me, target);
  }

  zhuan_cost = me->query_skill("stick") / 2;
  me->add("neili", -zhuan_cost );
  me->add("jingli", -zhuan_cost/2 );
  me->delete_temp("zhuan");
}

int jump_around(object me, object target)
{
  object env = environment(target);
  
  if(!me->is_living() || !target->is_living()) return -1;
  
  message_vision("$N�޿��κΣ�Ψ�����������������ȥ��\n", target);
  
  // see look.c file.
}

private int remove_effect(object me, object target, int zhuan_busy)
{
  object weapon;
  me->delete_temp("zhuan");
  
//  tell_object(me, HIY"\n�����е�����̫�����أ�����֮���б仯���顣\n"NOR);
//  tell_object(target, HIY"\n��İ��ж��䣬�򹷰��ġ��⡹�־���Ȼ�߽⡣\n"NOR);
  
  if(objectp(me) && objectp(target) && target->is_fighting(me) )
    message_vision(HIG"\n$N����֮����Ѹб仯���顣\n"NOR, me, target);
  
  return 1;
}

