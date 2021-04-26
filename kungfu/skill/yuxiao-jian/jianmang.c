// Code of ShenZhou
// jianmang.c

/*
׿�����ڶ������У���־���֮�⣬��������־��£����ӵ�����Ĵ��˰��Ȧ�ӣ�����һͦ��������ͻȻ����������²�������â��Ⱥ������ʮ������������������â����â�����ǽ�â���Ƴ��߰�����������׿������¶��Ц����������һ����������âͻʢ���������ؿڴ�����
�����δ�������˵ı�������������â������Ⱥ�����ȣ�������һ�������书���Լ���Ȼ�Ը����ˣ��Ų�һ�����˿�ȥ��׿������һ������ȫ������;�޷����У�ˢ��һ���죬���������˴�ʯ���У�����������ʯ���˼���Ӳ�Ļ���ʯ���ƣ�����ĳ�����Ȼ����һ�����࣬�ɼ������ڽ����ϵ�����ʵ�Ƿ�ͬС�ɣ�

Maco��ע��
��â��һperform���������������һ�����Ȼ��Kane�����code����������Ҳ
���϶�Ϊ���｣����׼perform��Maco�ڴ˱㽫��ʹ�����ǰ�˽Ų��Լ���
չcode�仯�ԣ�����Щ��Ȥζ��

˫�ؽ�â���ã���춽�ʣ��Ľ�â��Чʱ��һ���ù⣬��Ϊһ�������������
�ߣ�Ȼ����âЧ�����̽�������ͨ��Ҳ�����̶��ѣ����Ǻ�ƽ����ͬ�ġ�ʣ��
ʱ��Խ��������Խ�󣬿�˵��ʹ����â������һ����

�֣������⡱�ߵͣ�Ӱ��˫�ؽ�â�������ҡ�
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void checking(object me, object weapon,int speed, int damage);
void remove_effect1(object me, object weapon, int speed, int damage) ;

int perform(object me, object target)
{
	object weapon;
	int speed, damage, sword, jianyi;

	weapon = me->query_temp("weapon");
		
	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("��âֻ�ܶ�ս���еĶ���ʹ�á�\n");

	jianyi = me->query("th_jianyi");

	if (!jianyi)
		return notify_fail("��û�������⣬��֪��β������á���â����\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽����������á���â������\n");

	if( me->query_temp("th_jianmang") )
	{
		if( jianyi < 5 )
			return notify_fail("����Խ�������򣬽�âʩչ���������������Ǽ��ޣ�\n");

		if( me->query_skill("bitao-xuangong", 1) + (me->query("int")-15)*10 < 400 )
			return notify_fail("��������Ժ�������Ϊ����âʩչ���������������Ǽ��ޣ�\n");
	}

	if( me->query_temp("th_wait_jianmang") && !me->query_temp("th_jianmang") )
		return notify_fail("����Ѫ��ӿ���޷����á���â����\n");

	if( me->query_temp("th_jianzhi") )
		return notify_fail("���������ý�ָ����Ĺ��ƣ����ܷ������á���â����\n");

	if( me->query_skill("yuxiao-jian",1) < 150 )
		return notify_fail("����Ϊ����������δ���򡸽�â����\n");

	if( me->query_skill("bitao-xuangong", 1) < 120 )
		return notify_fail("����ڹ���Ϊ���δ����ʩչ��âֻ���˼�����\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("�����õ��ڹ��롸��â���ķ���㣣�\n");

	if( me->query("max_neili") <= 1200 )
		return notify_fail("���������Ϊ���㣬����������ʩչ��â��\n");

	if( me->query("neili") <= 600 )
		return notify_fail("�����������������������ʩչ��â��\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ������ޣ�������ʩչ��â��\n");

	damage = me->query_skill("force") + me->query_skill("qimen-dunjia",1);
	damage = damage/5;
	sword = me->query_skill("sword")/3;
	speed = me->query_skill("sword")/100 + jianyi;
	if ( damage > 400)
		damage = 400;
	if(wizardp(me))
	tell_object(me,sprintf("damage : %d , speed : %d , sword : %d \n", damage, speed, sword));


/*	if ( userp(me) ) {
		me->add("neili", -300);
		me->add("jingli", -50);
		if ( damage > weapon->query("weapon_prop/damage") * 3)
			damage = weapon->query("weapon_prop/damage") * 3;
		else weapon->add("rigidity", damage*100);
	}
*/

	if(me->query_temp("th_jianmang")) {
	me->add("neili", -150);
	me->add("jingli", -50);
	me->set_temp("final_jianmang", 1); 
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("final_jianmang"); 
	me->delete_temp("th_jianmang"); 
	me->start_busy(1);
	checking(me, weapon, speed, damage);
	}

	else {
	me->add("neili", -300);
	me->add("jingli", -50);
	me->add_temp("th_jianmang", sword/4+jianyi*10); 
	me->set_temp("th_wait_jianmang", 1); 
	me->add_temp("apply/speed", speed);
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);
	me->start_busy(1);

	message_vision(HIC
"$N����һ������������"+weapon->name()+HIC"�������죬"+weapon->name()+HIG"������ɲұ̰�͸��ɫ��\n"+
"һ�����ɫ��â�ӽ�����ֱ�������� ......\n"+
weapon->name()+HIC"ǰ������������"+HIG"��â"NOR+HIC"��������������²���������ȥ������ף�����\n"NOR, 
me);
	call_out("checking", 1, me, weapon, speed, damage);
	call_out("remove_effect1", sword/2, me, weapon, speed, damage);
	call_out("remove_effect2", sword*2/3, me);
	}
	return 1;
}

void checking(object me, object weapon,int speed, int damage)
{
	me->add_temp("th_jianmang", -1);
	 
	if( !living(me) || me->is_ghost() )
	{
		remove_effect1(me, weapon, speed, damage);
		return ;
	}
	if( !me->is_fighting() )
	{
		message_vision("\n$N��ս���ѱϣ��㼴�����˴߶���â��������\n", me);
		remove_effect1(me, weapon, speed, damage);
		return ;
	}
	else if( !weapon || environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		message_vision("\n$N���б�����ʧ����â������֮�߽⡣\n"NOR, me);
		remove_effect1(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("sword") != "yuxiao-jian"
	 || me->query_skill_mapped("force") != "bitao-xuangong" )
	{
		remove_effect1(me, weapon, speed, damage);
		message_vision(HIG"\n$N�书·�����䣬"+weapon->name()+HIG"����â���š�\n"NOR, me);
		return ;
	}
	else if( me->query_temp("th_jianmang") <= 0 )
	{
		tell_object(me,HIG"\n��â�����ѵ����ޣ�\n"NOR);
		remove_effect1(me, weapon, speed, damage);
		return; 
	}
		else call_out("checking", 1, me, weapon,speed,damage);
		return;
}

void remove_effect1(object me, object weapon, int speed, int damage) 
{
	if (!me) return;
	me->add_temp("apply/speed", -speed);
	me->add_temp("apply/attack", -damage);  
	me->delete_temp("th_jianmang");

	if (!weapon) {
		me->set_temp("apply/damage", 0);
		return;
	}
	if( environment(weapon) != me || weapon != me->query_temp("weapon") )
		return;
	else if (weapon->query("weapon_prop/damage") < 40) {
		message_vision(HIW"\nֻ����һ�����죬$N����"+weapon->name()+HIW"����ס������������ѳ���Ƭ����\n"NOR,me);
		destruct(weapon);
		me->set_temp("apply/damage", 0);
	}
	else {
		me->add_temp("apply/damage", -damage);
		message_vision(HIY"\n$N����"+weapon->name()+HIY"��������һ�����죬���ڽ��ϵ���â����ʧ����Ӱ���١�\n"NOR, me);
	}
	remove_call_out("remove_effect1");
	remove_call_out("checking");
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("th_jianmang");
	me->delete_temp("th_wait_jianmang");
	tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ��������Ѫ����ת�糣��\n"NOR); 
}
