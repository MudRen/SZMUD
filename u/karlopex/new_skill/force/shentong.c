// Code of ShenZhou
// shentong.c 
// snowyu update
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
		  int skill, value;

	//me = this_object();

	if( target == me)target=offensive_target(me);

	if( !target )target = offensive_target(me);
	if( !target )target = me->select_opponent();

        if( !target || !target->is_character() || !me->is_fighting(target) )
               return notify_fail("�������񹦡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");


       if( (int)me->query("neili") < 100  )
	{
		 return notify_fail("�������������\n");
	}

	if( (int)me->query_temp("shentong") )
					 return notify_fail("���Ѿ����˹�\���ˡ�\n");
/*
	if( !target	||	!me->is_fighting() )
                return notify_fail("������ֻ����ս���в���ʹ�á�\n");
*/



		  message_vision(
                HIW "$N�����񹦣�����֮��˫Ŀ�������䣬ͷ��ð��˿˿���������ѽ��ڹ�����������\n" NOR, me);
                 message_vision(
           HIG
            "һ˲��$N���ж�Ȼ���Ʈ������,�����羪���İ�����ӿ������\n" NOR, me);

                 skill = (me->query_skill("force")+(me->query("neili")/5)+(me->query("jingli")/10))*4;
                  me->add("neili", -100);

//                   value = skill * random(me->query("shentong")*5); �ܶ������û����������ͨ��
                  value = skill * random((me->query("jiali")+me->query("jiajin"))/2+300);
		  if( value > 90000 ) value = 90000;
		  if( value < 30000 ) value = 30000;
              if(wizardp(me))
              printf("amount=====%d", value);
//	disabled adding jingli since player exploiting this to add max jingli
		  me->add( "jingli",value  );
                  me->add_temp( "apply/attack",value/400  );
                  me->add_temp( "apply/damage",value/400 );
		  me->set_temp("shentong", 1);


		  if( me->is_fighting() ){
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->start_busy(1+random(3));
		  }

		  me->add( "jingli", -value );
                  me->add_temp( "apply/attack",-value/400  );
                  me->add_temp( "apply/damage",-value/400  );
		  me->delete_temp("shentong", 1);

		  return 1;
}
