// Code of ShenZhou
// jingang.c ��շ�ħ��ͨ
// Converted to exert from perform by xQin on 6/99
// Modified by Apache 9 / 99

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int original, skill;
        int temp1, temp2;

        if( objectp(target) && target != me ) 
                return notify_fail("��ֻ���ý�շ�ħ��ͨ�������Լ���ս����\n");
/*
		  if( !me->is_fighting() )
					 return notify_fail("�������ս���в���ʹ�ý�շ�ħ��ͨ��\n");
*/
        if( me->query_temp("weapon") )
                return notify_fail("��ֻ���ڿ���ʱʹ�ý����ͨ��\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 60 )
                return notify_fail("��Ļ�Ԫһ�������δ�����޷�ʩչ��շ�ħ��ͨ��\n");

        if( me->query_skill("jingang-quan", 1) < 90 )
					 return notify_fail("��Ľ��ȭ���δ�����޷�ʩչ��շ�ħ��ͨ��\n");

		  if( me->query("max_neili") <= 600 )
					 return notify_fail("���������Ϊ���㣬���������˷����޷�ʩչ��շ�ħ��ͨ��\n");

		  if( (int)me->query("neili") < 600  )
					 return notify_fail("�������������\n");

		  if( (int)me->query_temp("jingang") )
					 return notify_fail("���Ѿ������˽�շ�ħ��ͨ��\n");

		  if( me->query_temp("jinzhongzhao") )
					 return notify_fail("���������ý�ղ������񹦣�����δ�����޷�ͬʱ���ý�շ�ħ�������ͨ��\n");

		  skill = me->query_skill("hunyuan-yiqi", 1);

		  me->add("neili", -skill*2);
		  me->receive_damage("jingli", skill);

		  message_vision(HIR
	"\n$N������Ϣ������Ϣ����ת������������������ģ�����������΢�ı���֮����\n"
	"���Ƿ������ڵ������书��������ڣ��������а�������ǡ�"HIY"��շ�ħ��ͨ"HIR"����\n"NOR, me);

		  // The higher the hunyuan-yiqi, the higher the temp strength
		  if (skill < 100) {
		  	temp1 = 1;
		  } else if (skill < 200) {
		  	temp1 = 2;
		  } else {
		  	temp1 = 3;
		  }
		  original = me->query_str();
		  me->add_temp("apply/strength", original*temp1);
		  me->set_temp("jingang", 1);

		  me->start_call_out( (: call_other, __FILE__, "remove_effect", me, original*temp1 :), skill/6);
		  //if( me->is_fighting() )
		  //me->start_busy( 1+random(3) );

		  return 1;
}

void remove_effect(object me, int amount)
{
		  me->add_temp("apply/strength", - amount);
		  me->delete_temp("jingang");
		  // me->receive_damage("qi", 500, "��Ϣ���ң�����ʧ�ض���");

		  message_vision(HIR"$Nȫ�����������죬������Ϣ������"HIY"��շ�ħ��ͨ"HIR"������ɢȥ��\n"NOR, me);
}

