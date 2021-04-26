// Code of ShenZhou
// huaying.c ���е�֮���λ�Ӱ

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, fakeme, fakeweapon;
	object *enemy;
	string master;
	int i, serial;

	weapon = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !objectp(weapon) || weapon->query("skill_type") != "blade") 
		return notify_fail("�������޵����������á����λ�Ӱ������\n");

	if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("�����λ�Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("yanxing/huanying") )
		return notify_fail("����������ġ����λ�Ӱ���Ի�\n");

	if( me->query_skill("yanxing-dao",1) < 60 )
		return notify_fail("�����е�����Ϊ����������δ�������λ�Ӱ����\n");

	if( me->query_skill("linji-zhuang", 1) < 60 )
		return notify_fail("����ڹ���Ϊ���δ����������ʩչ�����λ�Ӱ����\n");

	if( me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("�����õ��ڹ��롸���е�����·��㣣�\n");

	if( me->query_skill("dodge") < 60 )
		return notify_fail("����Ṧ��򲻹���������ʩչ�����λ�Ӱ����\n");

	if( me->query("max_neili") <= 400 )
		return notify_fail("���������Ϊ���㣬����������ʩչ�����λ�Ӱ����\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������������������ʩչ�����λ�Ӱ����\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ������ޣ�������ʩչ�����λ�Ӱ����\n");

	if ( userp(me) ) {
		me->add("neili", -100);
		me->add("jingli", -50);
	}

	seteuid(getuid());
	if ( userp(me) ) {
	    fakeme = new(__DIR__"copy/user.c");
	    fakeme->set("id", me->query("id")+" shadow");
	    fakeme->set("master_id", me->query("id"));
	    me->save();
	    if (!fakeme->restore())
		return notify_fail("����㿴�������Ϣ��˵��ϵͳ�����⣬������ʦ���档\n");

	    fakeme->setup();
	    fakeweapon = weapon->clone();
	    fakeweapon->move(fakeme);
	    fakeweapon->wield();
	} else {	// npc
	    fakeme = new(base_name(me));
	    if ((me->query("family/family_name") == "���־�") &&
		(master=me->query("master")) &&
		(serial=me->query("serial"))) {	// this is a ��� npc
		
		me->save();
		fakeme->set("master", master);
		fakeme->set("serial", serial);
		if (!fakeme->restore())
		    return notify_fail("�뱨����ʦ�����ϵͳ�����⡣\n");
		fakeme->drop_all_weapon();
		fakeweapon = weapon->clone();
		fakeweapon->move(fakeme);
		fakeweapon->wield();
	    }
	}
	fakeme->set_name(me->name()+"��Ӱ", ({fakeme->query("id"), me->query("id")}));
	fakeme->move(environment(me));
	fakeme->add_temp("apply/dexerity", me->query_temp("apply/dexerity"));
	fakeme->add_temp("apply/strength", me->query_temp("apply/strength"));
	fakeme->set_temp("apply/speed", 0);
	fakeme->set("env/wimpy", 0);
	fakeme->set("env/invisibility", 10);

	message_vision(HIY "\n\n$Nǰ�����ߣ���������������"+weapon->name()+"ԽʹԽ�죬�����������⻯���������Ρ�\n"
			+"$n�������е���֮�����λ�Ӱ�����Ի������޴룬��֪�ĸ�$N���棬�ĸ��Ǽ١�\n" NOR, me, target);

	enemy = me->query_enemy();
	for (i=0; i<sizeof(enemy); i++)
		if(environment(enemy[i]) == environment(me))
		{
			if (me->is_killing(enemy[i]->query("id")))
				fakeme->kill_ob(enemy[i]);
			else
				fakeme->fight_ob(enemy[i]);

			if (enemy[i]->is_killing(me))
				enemy[i]->kill_ob(fakeme);
			else
				enemy[i]->fight_ob(fakeme);
		}

	fakeme->set_temp("yanxing/huanying", me);
	me->set_temp("yanxing/huanying", fakeme);

        call_out("checking", 1, me, target, fakeme, random(10)+me->query_skill("blade")/15);
        return 1;
}

private void stop_huanying(object me, object victim, object fakeme)
{
	me->delete_temp("yanxing/huanying");
	destruct(fakeme);
	if (victim && victim->is_fighting(me)) {
	    message_vision(HIY "\n\n$N����ʶ����$n�ġ����λ�Ӱ������Ϊ$n���Ի�\n" NOR, 
		victim, me);
	}
}

int checking(object me, object target, object fakeme, int delay)
{
	if ( !objectp(fakeme) ) return 1;
	if ( !objectp(me) ) {destruct(fakeme); return 1;}
        if ( !objectp(target) ) {destruct(fakeme); return 1;}
	if (!me->is_fighting(target) || !living(fakeme) || delay < 1) {
		stop_huanying(me, target, fakeme);
		return 1;
	} 
	if (me->is_fighting(target) && !fakeme->is_fighting(target) )
		fakeme->fight_ob(target);
	call_out("checking", 1, me, target, fakeme, delay-1);
	return 1;
}
