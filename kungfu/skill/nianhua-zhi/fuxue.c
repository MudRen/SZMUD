// Code of ShenZhou
// fuxue.c �黨��Ѩ

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"�İ�Ѩ",
	"�ز�Ѩ",
	"��ӭѨ",
	"Ͽ��Ѩ",
	"ͷάѨ",
	"�¹�Ѩ"
});

string* xuedao2 = ({
	"����Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"�ػ�Ѩ"
});

string* xuedao3 = ({
	"�ٳ�Ѩ",
	"�ٺ�Ѩ",
	"ͨ��Ѩ",
	"����Ѩ"
});

string* xuedao4 = ({
	"ӡ��Ѩ",
	"����Ѩ",
	"��ҺѨ",
	"����Ѩ",
	"����Ѩ"
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

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if ( me->query_temp("weapon") ) 
		return notify_fail("����������ô��Ѩ��\n");

	if( !target || !target->is_character() || target->query("race") != "����" )
		return notify_fail("��Ҫ��˭��Ѩ��\n");

	if( environment(target)->query("no_fight") )
		return notify_fail("�������㲻��͵Ϯ��Ѩ��\n");

	if( me->query_str() < 25 )
		return notify_fail("���ڱ����������������㣬��Ѩ�����亦��\n");
	
	if( me->query_skill("finger") < 90 )
		return notify_fail("����ָ�����µĹ��򻹲����������黨��Ѩ��\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 90 )
		return notify_fail("����ڹ���Ϊ���δ�����޷�ʹ���黨��Ѩ��\n");

	if( me->query("max_neili") <= 300 )
		return notify_fail("���������Ϊ���㣬�������ܹ�͸���޷���Ѩ��\n");

	sp = me->query_skill("dodge") + me->query_skill("parry") + me->query("kar");
	dp = target->query_skill("dodge") + target->query_skill("parry") + target->query("kar");
		
	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("nianhua-zhi",1))/15;

	if( me->query("neili") <= 2*time )
		return notify_fail("��������������������ܹᴩѨ����\n");

	if( random(sp) > dp && time > 0 )
	{
		if( me->query_skill("finger") >=  90 && me->query_skill("finger") < 115)
		message_vision(HIR "\n$N��ָ��£�����������䣬�ѵ�����$n��" + xuedao1[random(6)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 115 && me->query_skill("finger") < 140)
		message_vision(HIR "\n$N���������ָ��һ���ֵ�����$n��" + xuedao2[random(4)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 140 && me->query_skill("finger") < 165)
		message_vision(HIR "\n$N˫ָ�絶��ꪣ����Ž��ƣ�৵�һ�����Ѵ�����$n��" + xuedao3[random(4)] + "�ϣ�\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 165 && me->query_skill("finger") < 190)
		message_vision(HIR "\n$N��������ʳָ��һ������ƿձų�����ֱ����$n��" + xuedao4[random(5)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 190 )
		message_vision(HIR "\n$Nʳָ�ᵯ��һƬ��ɽ�����İ�����ʱӿ��������$n��" + xuedao5[random(7)] + "�ϣ�\n\n" NOR, me, target);

		me->add("neili", (-10)*time);
		if( me->query_temp("jingang") )me->add("neili", (-20)*time); // jingang can make own bili 4 times, too rascal,
																						 // so jingang+fuxue combo should consume more neili
		target->start_busy(time);

		}
	else
	{	
		message_vision(HIW "\n$Nһָ��ȥ������$n�����ϵл��ȣ�һ������˿�ȥ�� \n\n$N��ǰ��ʱ���Ŵ�¶���Ǳ����м��� .... \n" NOR, me, target);
		if( !target->is_fighting(me) ) target->fight_ob(me);
		me->start_busy(5);
	}
        if (random(2) == 1) {
	    if (! target->is_killing(me)) target->kill_ob(me);
 	}

	return 1;
}
