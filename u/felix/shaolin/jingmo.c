// Code of ShenZhou
// jingmo.c ��ħһָ
// Modified by Felix 5/2002

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

string* xuedao1 = ({
	"�羮Ѩ",
	"�Ϲ�Ѩ",
	"��ͥѨ",
	"��ԪѨ",
	"���Ѩ"
});

string* xuedao2 = ({
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"ԨҺѨ",
	"����Ѩ",
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

	if( !me->is_fighting() ) 
		return notify_fail("�������ս���в���ʹ�þ�ħһָ��\n");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target || !target->is_character() || target->query("race") != "����" )
		return notify_fail("��Ҫ��˭��Ѩ��\n");

	if( environment(target)->query("no_fight") )
		return notify_fail("�������㲻��͵Ϯ��Ѩ��\n");

	if( me->query_str() < 30 )
		return notify_fail("���ڱ����������������㣬��Ѩ�����亦��\n");
	
	if( me->query_skill("yizhi-chan", 1) < 90 )
		return notify_fail("����һָ�����µĹ��򻹲��������ᾪħһָ��\n");

	if( me->query_skill("hunyuan-yiqi", 1) < 60 )
		return notify_fail("����ڹ���Ϊ���δ�����޷���Ѩ��\n");

	if( me->query("max_neili") <= 500 )
		return notify_fail("���������Ϊ���㣬�������ܹ�͸���޷�ʹ��ħһָ��\n");

	if( me->query_skill("buddhism") < 300)
		sp = me->query_skill("dodge") + me->query_skill("parry") ;

	if( me->query_skill("buddhism") >=  300 && me->query_skill("buddhism") < 310)
		sp = ((me->query_skill("dodge") + me->query_skill("parry"))*105/100;

	if( me->query_skill("buddhism") >=  310 && me->query_skill("buddhism") < 320)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*110/100;

	if( me->query_skill("buddhism") >=  320 && me->query_skill("buddhism") < 330)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*115/100;

	if( me->query_skill("buddhism") >=  330 && me->query_skill("buddhism") < 340)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*120/100;

	if( me->query_skill("buddhism") >=  340 && me->query_skill("buddhism") < 350)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*125/100;

	if( me->query_skill("buddhism") >=  360 && me->query_skill("buddhism") < 370)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*130/100;

	if( me->query_skill("buddhism") >=  370 && me->query_skill("buddhism") < 380)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*135/100;

	if( me->query_skill("buddhism") >=  380 && me->query_skill("buddhism") < 390)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*140/100;

	if( me->query_skill("buddhism") >=  390 && me->query_skill("buddhism") < 400)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*145/100;

	if( me->query_skill("buddhism") >=  400)
		sp = (me->query_skill("dodge") + me->query_skill("parry"))*150/100;
	
	dp = target->query_skill("dodge") + target->query_skill("parry");
		
	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("finger"))/10;
	if (time > 10) time = 10;

	if( me->query("neili") <= time )
		return notify_fail("��������������������ܹᴩѨ����\n");

	if( random(sp) > dp/2 && time >= 0 )
	{
		if( me->query_skill("finger") >=  90 && me->query_skill("finger") < 115)
		message_vision(HIR "\n$N��ָ��£�����������䣬�ѵ�����$n��" + xuedao1[random(5)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 115 && me->query_skill("finger") < 140)
		message_vision(HIR "\n$N���������ָ��һ���ֵ�����$n��" + xuedao2[random(6)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 140 && me->query_skill("finger") < 165)
		message_vision(HIR "\n$N˫ָ�絶��ꪣ����Ž��ƣ�৵�һ�����Ѵ�����$n��" + xuedao3[random(6)] + "�ϣ�\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 165 && me->query_skill("finger") < 190)
		message_vision(HIR "\n$N���һ����ָ��һ�������ƿն������͵�������$n��" + xuedao4[random(5)] + "��\n\n" NOR, me, target);

		if( me->query_skill("finger") >= 190 )
		message_vision(HIR "\n$Nָ��΢�죬������Ӱ���ٵط�����$n��ʱȫ�����飬�ѱ�������" + xuedao5[random(7)] + "��\n\n" NOR, me, target);

		me->add("neili", (-50)*time);
		target->start_busy(time);
        }
	else
	{	
		message_vision(HIW "\n$Nһָ��ȥ������$n�����ϵл��ȣ�һ������˿�ȥ�� \n\n$N��ǰ��ʱ���Ŵ�¶���Ǳ����м��� .... \n" NOR, me, target);
                // if( !target->is_killing(me) ) target->kill_ob(me);
                me->start_busy(time/5);
        }
        return 1;
}
