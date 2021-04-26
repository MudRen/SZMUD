// Code of ShenZhou
// tongshou.c ���ͬ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	mapping skill_status;
	string msg, *sname;
	object weapon;
	int exp, shen, mine, count;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ͬ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !me->query("wudang/tongshou") )
		 return notify_fail("��δ������ͤ���ڣ�����ʹ�����ͬ�١�\n");

	weapon = me->query_temp("weapon");
        if( weapon->query("skill_type") != "sword" )
                return notify_fail("�������޽������ʹ�����ͬ�٣�\n");
		
	if( (int)me->query_skill("sword") < 150 )
		return notify_fail("���̫��������������죬����ʹ�����ͬ�١�\n");

	if( (int)me->query_skill("taiji-shengong", 1) < 120 )
		return notify_fail("���̫������Ϊ����������ʹ�����ͬ�١�\n");

	if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("�����õ��ڹ���̫��������·��㣣�\n");

        if( me->query("combat_exp") < 300000)
                return notify_fail("��ʵս���鲻�㣬����ʹ�����ͬ�١�\n");
	
	if (target->query("shen") < -10000)
		shen = (int)me->query("shen")/50;
	else shen = -(int)me->query("shen")/50;

	exp = (int)me->query("combat_exp")/100;
//	if (exp > 6000) exp = 5000 + random(1000);

	msg = HIW"$Nһ����Х�����Ŀ��Ŵ󿪣���ײ��$n"+HIW"���У���ת�������Լ�С��ֱ����£�����\n"NOR;

	mine = random(me->query("combat_exp") + me->query("shen"));
	if( mine > (int)target->query("combat_exp")/3*2 ) {
		msg += HIR"$n"+HIR"⧲�����֮�£���$Nײ�뻳�У�ֻ��С��һ����"NOR+weapon->name()+HIR"����$N��͸����룡����\n" NOR;
		message_vision(msg, me, target);		
        	me->add("max_neili", -(30+random(30)) );
        	me->add("combat_exp", -exp);
		me->add("shen", shen);

/*
		if ( mapp(skill_status = me->query_skills()) ) {
                	skill_status = me->query_skills();
	                sname = keys(skill_status);
                	count = sizeof(skill_status);
                	for(i=0; i<sizeof(skill_status); i++) {
                        point = (skill_status[sname[i]]+1)*(skill_status[sname[i]]+1)/2+1;
                        while ( (point /= 2) > 0 )
                                me->improve_skill(sname[i], -point+1);
                	}
        	}
*/

		me->receive_wound("qi", me->query("max_qi")+200,
		"ʹ�����ͬ����"+target->name()+"ͬ���ھ��ˣ�");
                target->receive_wound("qi", target->query("max_qi")+200,
                "��"+me->name()+"ͬ���ھ��ˣ�");
	} else {
		msg += HIC"$n����$N�ô���������æ���ң��Ǳ���״�Ķ�����ȥ�������ŵ������������һ�󶯵����á�\n" NOR;
		message_vision(msg, me, target);
                me->receive_wound("qi", me->query("max_qi")+200,
                "ʹ�����ͬ��׳�ҳ��ʣ�");
		target->start_busy(3 + random(3));
	}

	return 1;
}

