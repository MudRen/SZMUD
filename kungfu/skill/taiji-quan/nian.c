// Code of ShenZhou
// nian.c ̫��ȭ��ճ���־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object ob;
        string msg;
        int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ճ��ճ��ֻ�ܴ���ս���еĶ��֡�\n");

        if( me->query_temp("yield") )
                return notify_fail("�㲻��ȭ������ʹ��ճ���־���\n");

        if( objectp(ob = me->query_temp("nian")) )
	{
                if( ob->is_fighting(me) )
                	return notify_fail("���Ѿ���ճ��ճ������ˡ�\n");
        }

	if( (string)target->query("race") != "����" )
 		return notify_fail("�������Ҫô��\n");

        if( (skill = (int)me->query_skill("cuff")) < 100 )
                return notify_fail("���̫��ȭ��������죬����ʹ�á�ճ���־���\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 80 )
                return notify_fail("���̫������Ϊ����������ʹ�á�ճ���־���\n");

        if( !me->query_temp("taiji") && ((int)me->query("jiali") || (int)me->query("jiajin") > 1) )
                return notify_fail("̫��ȭ�������У�����������������ʹ������ճ���־���\n");

        //msg = HIY "$N˫�ֱ��˸�̫��ʽ��ԲȦ����ʱһ��һʽ�ڽڹᴮ����Ȧ��ȦԲת���ϣ��糤����ӣ����ϲ�����\n";
	msg = HIY "\n$N���ִ���$n�����֣�ת��һ����Ȧ��һ�ɼ�ǿ������������$p���֣�����̫�����֡�\n";

        me->add("jing", -50);
        me->add("jingli", -50);

        if( random(me->query("combat_exp") * me->query_int() / 100) 
                > (int)target->query("combat_exp") * target->query_int() / 200 )
	{
                //msg += "���$p��$Pճ���õ���ײײ�������������㲻�ȣ������оƻ��ԡ�\n" NOR;
		msg += "���������಻�ϣ�һȦ��������һȦ��$n��˫���ƺ�ȫ��$Pճס�ˡ�\n"NOR;
                me->set_temp("nian", target);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/6);      
        }
	else
	{
		switch( random(3) )
		{
			case 0: msg += "$p��æʹ����ǧ��׹��֮����ס���Ρ�\n" NOR; break;
			case 1: msg += "$p���ұ�ӣ�б��������\n" NOR; break;
			case 2: msg += "$nȫ������һ��$P˫�ְ�����ס����$pԾ��Ȧ�⣡\n" NOR; break;
		}
                me->start_busy(1 + random(2));
        }
        message_vision(msg, me, target);
        return 1;
}

void remove_effect(object me)
{
        if( objectp(me->query_temp("nian")) )
	{
        	me->delete_temp("nian");
        	if( me->is_fighting() )
        		message_vision("\n$N����һ�ɣ�ճ��жȥ��\n", me);
        }
}
/*
�뵽�������һ������Ҳ���Լ����˳��������ɵú������¡�����һ�ɣ�ճ��жȥ��
�ϵþ�ƣ���������Ѷ�����
*/

