// Code of ShenZhou
// qiankun  һָǬ��

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"�ٻ�Ѩ",
	"��Ѩ",
	"ǿ��Ѩ",
	"�Ի�Ѩ",
	"�縮Ѩ"
});

string* xuedao2 = ({
	"��׶Ѩ",
	"�յ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"��̨Ѩ",
	"������"
});

string* xuedao3 = ({
	"�и�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��ȱѨ",
	"̫ԨѨ",
	"����Ѩ"
});

string* xuedao4 = ({
	"����Ѩ",
	"�Ϲ�Ѩ",
	"������",
	"����Ѩ",
	"ӭ��Ѩ"
});

string* xuedao5 = ({
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"����Ѩ"
});


int perform(object me, object target)
{
	int sp, dp, time;

	if (!me->is_fighting())
		return notify_fail("�������ս���в���ʹ��һָǬ����\n");

	if (!target && me->is_fighting()) target = offensive_target(me);

	if (!target || !target->is_character() || target->query("race") != "����")
		return notify_fail("��Ҫ��˭��Ѩ��\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	if (me->query_str() < 28)
		return notify_fail("���ڱ����������������㣬��Ѩ�����亦��\n");
	
	if (me->query_skill("yiyang-zhi", 1) < 100)
		return notify_fail("����һ��ָ���µĹ��򻹲���������һָǬ����\n");

	if (me->query_skill("kurong-changong", 1) < 80)
		return notify_fail("����ڹ���Ϊ���δ�����޷���Ѩ��\n");

	if (me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("�����õ��ڹ��롸һָǬ������·��㣣�\n");

	if (me->query("neili") <= 200)
		return notify_fail("����������㣬���޷�ʹһָǬ����\n");

	if (me->query("jingli") <= 50)
		return notify_fail("��ľ������㣬���޷�ʹһָǬ����\n");

	if (me->query("max_neili") <= 1000)
		return notify_fail("���������Ϊ���㣬�������ܹ�͸���޷�ʹһָǬ����\n");

	sp = (me->query_skill("finger")*2
		+ me->query("int")*40
		+ me->query("combat_exp")/3000);

	dp = (target->query_skill("dodge")
		+ target->query_skill("parry")
		+ me->query("int")*30
		+ target->query("combat_exp")/3000);

	if (target->query("family/family_name")=="����ɽ"
		&& target->query_skill_mapped("force")=="hamagong")
		dp = dp-dp/3;

	time = me->query_skill("yiyang-zhi",1)/30+random(3);
	if ( time > 15 ) time = 15;
		
	if (random(sp) > dp/2 ) {
		
		if( me->query_skill("finger") >=  80 && me->query_skill("finger") < 120)
			message_vision(HIR "\n$N��ǰ����һ�����������һ�У�����˫ֱָ����������$n��" + xuedao1[random(5)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 120 && me->query_skill("finger") < 180)
			message_vision(HIR "\n$N���л��������о���֮ɫ�����ֵ�ȥ��һָ������$n��" + xuedao2[random(6)] + "��\n\n" NOR, me, target);


		if( me->query_skill("finger") >= 180) 
			message_vision(HIR "\n$N��ɫ���أ����ᵤ���ָ����������һ�������ƿն���������$n��" + xuedao4[random(5)] + "��\n\n" NOR, me, target);

		me->add("neili",-150);
		me->add("jingli",-30);
		target->start_busy(time);
		target->add("neili",- time*30);
		target->apply_condition("yyz_damage", me->query_skill("yiyang-zhi", 1)+random(me->query_skill("yiyang-zhi", 1))
			+ target->query_condition("yyz_damage"));
		target->set_temp("yyzenemy", me->query("id"));
        }
	else
	{	
		if (random(sp)>dp/3 && me->query_skill("yiyang-zhi",1)>180)
		{
			message_vision(HIW "\n$N��ճ�ָ��һ����������$n��" + xuedao2[random(6)] + "��$n��æ������$N���ھ��Կ�����Ȼ�����������������û�б�����Ѩ����\n" NOR, me, target);
			me->add("neili",-150);
			me->add("jingli",-30);
			if (target->query("neili")>time*200)
				target->add("neili", - time*200);
			else target->set("neili",10);
			me->start_busy(1+random(3));
			target->start_busy(1+random(2));
			target->set_temp("yyzenemy", me->query("id"));
		}
		else
		{
		message_vision(HIW "\n$Nһָ��ȥ��ͼ��$n��Ѩ��������$n�ۼ���죬����һƮ���㿪��$N�Ĺ�����$N��ʱ���Ŵ�¶ ... \n" NOR, me, target);
		me->start_busy(1+random(3));
		}
	}

	return 1;
}
