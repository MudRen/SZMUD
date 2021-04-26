// Code of ShenZhou
// longxiang ����֮��
//#��Ϊѩɽ���������˴���֮�� ����Ҳ��������֮�� ���Զ�����������Щ����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, org, extra,busy;
        string num;

        if( target != me ) 
                return notify_fail("��ֻ���������������������֮����\n");

        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("�������������\n");

        if( (int)me->query("max_neili") < 2000  )
                return notify_fail("�������������\n");

        if( (int)me->query_temp("shielded") ) 
                return notify_fail("���Ѿ����˻������ˡ�\n");

        if( (int)me->query_temp("longxiang") )
                return notify_fail("���Ѿ���������֮���ˡ�\n");

        if( (int)me->query_skill("longxiang-banruo", 1) < 120)
                return notify_fail("������������������\n");

        skill = me->query_skill("longxiang-banruo", 1);
        org = me->query_str();
        extra = skill/18;
        num = chinese_number(extra);
        me->add("neili", -300);
		if( me->query("gender") == "����")
		{
			if(extra>18)
			{
				extra=18;
			}
			else
			{
				extra=extra-random(3);
			}
			busy=6;
			message_vision("��������Ҫ����֮��������������̫�أ��޷���ȫ���������񹦡�\n");
		}
		else
		{
			busy=3;
		}

        message_vision(
        HIR"$N����Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ������"+num+"��"+num+"��֮����\n" +
        HIW"$N����ɰʯ���ݣ���Ȼ������һ����ӣ�\n"
        NOR, me);

        me->add_temp("apply/armor_vs_force", extra*6);
		me->add_temp("apply/attack", extra*6);
        me->add_temp("apply/strength",  extra*4);
        me->add_temp("apply/speed", extra);
        me->add_temp("apply/defense",  -extra);
        me->add_temp("apply/armor", -extra);

        me->set_temp("longxiang", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, extra :), skill/3);

        if( me->is_fighting() ) me->start_busy(busy);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor_vs_force", -amount*6);
		me->add_temp("apply/attack", -amount*6);
        me->add_temp("apply/strength", -amount*4);
        me->add_temp("apply/speed", -amount);
        me->add_temp("apply/defense",  amount);
        me->add_temp("apply/armor", amount);
        me->delete_temp("longxiang");
        tell_object(me, MAG"�������֮��������ϣ��������ջص��\n"NOR);
}

