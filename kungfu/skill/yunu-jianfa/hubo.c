//code by Slow
#include <ansi.h>
inherit F_SSERVER;
		
string	*hubo_msg = ({
HIG"\n$N���������$n�����������ȡ����ȸ����н������һ�������ز���\n"NOR,
HIG"\n$N��ü΢�������ֽ�ٿ�صݳ��������������$n���˹�ȥ��\n"NOR,
HIG"\n$N����б��������������Ѵ���$n����\n"NOR,
HIG"\n$N��һ������һ���������Ľ���$n����ҡ�Σ������н���\n"NOR,
HIG"\n$n��$N�̽��������������ˣ��ȳ���ס���ˣ�����һ������$N�����ȥ,$nһ����\n
�����������¶����϶��$N��������,ֻ��$n����·����Ѵ���һ��С�ף���Ѫ������\n"NOR,
	});

string *dodge_msg = ({
		CYN"\n�����֮�䣬$N˫���Ѵ�����ն��һ��������ʮ���У�$n�صõ�ˮ��©��\n
ÿһ�о�ײ�ڱ���֮��������������ֻ����һ�±��������ĳ������ѡ�\n"NOR,
		CYN"\n$N�������£�Ҳ���$n�صþ�������ܣ�΢΢һ�٣���ƮƮ��������ˡ�\n"NOR,
		CYN"\n$N˫��΢�����ƹ��ǹ������ƴ�����ȴ����������$n�������гڻ���\n"NOR,
CYN"\n$N��$nԽ��Խ����������ȴ������϶�ɳ�,����˫������,������ʮ�������������˻�����\n"NOR,
	});

int perform(object me, object target)
{
	object weapon,weapon2;
 	object *inv;
       int skill;
       int count,i;
       int ap,dp;
	int hubo_skill,num;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���һ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
       
/*
     if( me->query("newhubo") != 1 )
                   return notify_fail("��δ�ո���ָ�㣬�޷�ʩչ���һ�����\n");
*/
       if( me->query_skill_mapped("force") != "yunu-xinjing" )
                   return notify_fail("�����õĲ�����Ů�ľ����޷�ʩչ���һ�����\n");
   
       if( me->query_skill("yunu-xinjing", 1) < 100 )
                   return notify_fail("�����Ů�ľ����δ�����޷�ʩչ���һ�����\n");
       
 	if( (hubo_skill = me->query_skill("zuoyou-hubo", 1)) < 100 )
                return notify_fail("������һ�����δ��ͨ��\n");
   
       if( me->query_skill("yunu-jianfa",1) < 135 )
                   return notify_fail("�����Ů������Ϊ���㣬��ô���һ���? \n");
       
        if( me->query_skill("quanzhen-jian",1) < 135 )
                 return notify_fail("���ȫ�潣����Ϊ���㣬��ô���һ���? \n");
/*
        if (me->query_temp("gm_suxin"))
             return notify_fail("���Ѿ���ʹ�����ľ���\n");
*/
       
	if (me->query_temp("hubo") || me->query_temp("hebi"))
               return notify_fail("�����ڻ����أ�\n");
       
	inv = all_inventory(me); 
       
	for(i=0; i<sizeof(inv); i++)
	{ 
               if( inv[i]->query("equipped") || weapon == inv[i] ) continue; 
               if( inv[i]->query("skill_type") == "sword" )  
               { 
        	        weapon2 = inv[i]; 
              	  break; 
                }
 	} 
       
     
	 if( me->query("neili") < 500 )
                   return notify_fail("�����������ʹ�����һ�����\n");
       
	if( me->query("jingli") < 300 )
                 return notify_fail("��ľ�������ʹ�����һ�����\n");
       
	if (me->query_temp("hubo") || me->query_temp("hebi"))
               return notify_fail("�����ڻ����أ�\n");

	if( !objectp(weapon2) ) 
                    return notify_fail("�������˫�����ܺ�����һ�����\n"); 

       message_vision(HIR "$NͻȻ�����ֳ����һ�ѽ���˫��ʹ����Ȼ��ͬ�Ľ������������һ���������
		\n"+HIC"ֻ��$N˫��һ������������Ů������ȫ�潣����ϵ������޷죬����֮����Ȼ������\n\n" NOR, me); 
         me->add("neili",-(200+random(100)));
       
        num = hubo_skill / 20;
	me->set_temp("hubo",num);
        call_out("hubo_checking", 0, me);
           return 1;
}

void hubo_checking(object me)
{
         object  target;
	int	ap,dp,damage,num;
	string msg1,msg2;
	object weapon = me->query_temp("weapon");
	num = me->query_temp("hubo");
        if( !target ) target = offensive_target(me);
	
         if (!me->query_temp("hubo"))
          {
           message_vision(HIY "\n$N����æ�ţ�ֻ���ջ����һ���������\n\n" NOR, me); 
           me->delete_temp("hubo");
           return;
          }
	if (num<1)
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N����һ���������������صؽ�����ؽ��ʣ��ջ����һ���������\n\n" NOR, me);
		return;

	}
	if( !me ) return;

        if( !me->is_fighting() || !living(me) || me->is_ghost() ||  !living(me) )
	{
                message_vision(HIY "\n$N����һ���������������صؽ�����ؽ��ʣ��ջ����һ���������\n\n" NOR, me);
              me->delete_temp("hubo");
		return;
	}
	else if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N�����޽������ܼ��������ˣ�\n"NOR, me);
		return;
	}
        if( !target || !target->is_character() || !me->is_fighting(target) )
        {
                 me->delete_temp("hubo");
                 message_vision(HIY "\n$N����һ���������������صؽ�����ؽ��ʣ��ջ����һ���������\n\n" NOR, me);
                 return;
        }
/*
	else if( me->query_skill_mapped("sword") != "yunu-jianfa"
	|| me->query_skill_mapped("sword") != "quanzhen-jian" )
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$NͻȻ�����������������ܼ��������ˣ�\n"NOR, me);
		return;

	}
*/
	else if( me->query("neili") <= 500 )
	{
		me->delete_temp("hubo");
		me->start_busy(1);
		message_vision(HIY "\n$N�������㣬���ܼ��������ˣ�\n"NOR, me);
		return;
	}   
	msg1 = hubo_msg[random(sizeof(hubo_msg))];
	msg2 = dodge_msg[random(sizeof(dodge_msg))];

	me->set_temp("hubo",num-1);     
        damage = me->query_skill("yunu-jianfa",1)+me->query_skill("quanzhen-jian",1)+me->query_skill("zuoyou-hubo",1);
	damage = damage * (1+ num /10);   
        if ((me->query("combat_exp")/2+random(me->query("combat_exp")))
        >target->query("combat_exp")/2+random(target->query("combat_exp")/2))
	{	
		target->start_busy(2);
		message_vision(msg1,me,target);
		target->receive_damage("qi", damage,  me); 
		target->receive_wound("qi", random(damage/3)+damage/3, me); 
		COMBAT_D->report_status(target); 
	 }
	else
	{
		message_vision(msg2,me,target);
	}
        call_out("hubo_checking", 1, me, target);
}       
