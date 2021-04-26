// Code of ShenZhou
// jianzhi.c ��ָ���乥��
// maco 8/25/1999
// �������(20)�����｣���뵯ָ������Թ���Ѩ��Ϊ������ָ���䣬��΢����
// FunBoo @sz 6/28/2002 auto dianxue with xiao

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int speed, int damage);

// Use to determind auto dianxue success or not, if no xiao, no auto dianxue
// s_Attack_Type mean it is a finger attack or sword attack, since return message is not the same
void Auto_Dianxue_Success_Or_Not(object me, string s_Attack_Type);

// Function usage:
// 1 arg: the skill level/exp of the performer you want to compare
// 2 arg: the skill level/exp of the target you want to compare
// 3 arg: basic success rate if arg1 == arg2, 50%, put 0.5, 75%, put 0.75
// 4 arg: arg1 >= arg2 or arg1 < arg2, + or - how many percent on success rate, if you want 10%, put 0.1, 20% put 0.2 and so on
// 5 arg: in how many % different in skills level/exp, success rate start to take effect
// if you want 10%, put 0.1, if you want 20%, put 0.2 and so on
// Example:
// Get_Success_Rate(100, 100, 0.75, 0.1, 0.1);
// example above is my skill is 100, target skill is 100, and my perform have 75% to success when we have equal skill level
// if I have 10% skill level higher than target, i get 10% more on perform success rate
// if I have 10% skill level less than target, i get 10% less on perform sucess rate
int Get_Success_Rate(float f_My_Level, float f_Target_Level, float f_Basic_Success_Rate, float f_Add_Success_Rate, float f_Skill_Level_Diff);

// Ѩ�� array
string* xuedao = ({
	"�޹�Ѩ",
	"�ز�Ѩ",
	"�羮Ѩ",
	"�ճ�Ѩ",
	"����Ѩ",
	"���Ѩ",
	"����Ѩ",
	"�縮Ѩ",
	"����Ѩ",
	"�յ�Ѩ",
	"ǿ��Ѩ",
	"�ٺ�Ѩ",
	"����Ѩ",
	"����Ѩ",
	"����Ѩ",
	"��׵Ѩ",
	"��βѨ",
	"����Ѩ",
	"�͹�Ѩ",
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"������",
	"����Ѩ"
});

int perform(object me, object target)
{
	object weapon;
	int speed, damage, sword,jianyi;

	weapon = me->query_temp("weapon");
	jianyi = me->query("th_jianyi");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("��ָ���乥��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

 //       if (!me->query("th_jianyi"))
 //	       return notify_fail("��û�������⣬�����｣���İ���������ޣ���Ҳ�޷�ʩչ��ָ����Ĺ��ơ�\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������̸���ϡ���ָ���䡹��\n");

	if( me->query_temp("th_jianmang"))
		return notify_fail("��������ʹ������â���������ٷ����ˣ�\n");

	if( me->query_temp("th_jianzhi") >= 1)
		return notify_fail("���������ý�ָ����Ĺ��ƣ�\n");
	
	if( me->query_skill("yuxiao-jian",1) < 100 )
		return notify_fail("������｣����Ϊδ�������ܽ�ָ���乥�У�\n");

	if( me->query_skill("tanzhi-shentong",1) < 100 )
		return notify_fail("��ĵ�ָ��ͨ��Ϊδ�������ܽ�ָ���乥�У�\n");

	if( me->query_skill("bitao-xuangong", 1) < 100 )
		return notify_fail("��ı���������Ϊ���㣬ǿʹ��ָ���䣬ͽȻ��ɢ������\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("������ʹ���ڹ��޷��뽣ָ����֮�ķ�Э����\n");
	if( me->query_skill_mapped("finger") != "tanzhi-shentong")
		return notify_fail("����ʩչ��ָ�����ǵ�ָ��ͨ��\n");

	if( me->query_skill_prepared("finger") != "tanzhi-shentong")
		return notify_fail("�㻹û��׼����ʩչ��ָ��ͨ��\n");

	if( me->query("max_neili") <= 1200 )
		return notify_fail("���������Ϊ���㣬����ʩչ��ָ���䣬���������������������գ�\n");

	if( me->query("neili") <= 400 )
		return notify_fail("����������㣬������ʩչ��ָ���䣡\n");

	if( me->query("jingli") <= 400 )
		return notify_fail("��ľ������㣬������ʩչ��ָ���䣡\n");

	damage = me->query_skill("yuxiao-jian") + me->query_skill("tanzhi-shentong",1);
	damage = damage/4;
	sword = (me->query_skill("sword")*jianyi + me->query_skill("finger") )/6;
	speed = (me->query_skill("sword")+me->query_skill("finger") )/200;
	me->add("neili", -250);
	me->add("jingli", -100);

	//����������
	me->add_temp("apply/speed", speed);
	me->add_temp("apply/attack", damage);
	me->add_temp("apply/damage", damage/2);
	// Check if user wielded xiao

	if(objectp(weapon) && (string)weapon->query("shape")=="flute")
	{
		// if wield xiao, set var, if this var is present, user can dianxue while jianzhi is performed
		me->set_temp("n_th_Jianzhi_Auto_Dian_Xue", 1);
	}
	else
	
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	message_vision(HIG"$N����"+weapon->name()+HIG"һ�ڣ�������ȥ���������磬���ж��ǹ��ƣ�һ�в���$n���⿪ȥ���ڶ��е����������������\n"NOR, me,target);

	//�ڶ����Կ�
	me->add_temp("apply/attack", damage/3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -damage/3);

	if(me->is_fighting(target) ){
	message_vision(HIG"$N����δֹ������ָ�����̾�����������$n��·Ѩ����"+HIW"�����｣����"NOR+HIG"��"+HIW"����ָ��ͨ��"NOR+HIG"����Ϊ�ã�Խ����΢����仯���\n"NOR, me,target);

	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
	weapon->wield();
	}
	me->set_temp("th_jianzhi", sword);

	if(me->query_temp("th_jianzhi") > 70)
	me->set_temp("th_jianzhi", 70);

	call_out("checking", 1, me, weapon,speed,damage);

	return 1;
}

void checking(object me, object weapon,int speed, int damage)
{
	if(!me)
	{
		return;
	}

	if(!living(me) || me->is_ghost())
	{
		remove_effect(me, weapon, speed, damage);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		return ;
	}
	if( objectp(me) && !me->is_fighting())
	{
		message_vision("\n$N��ս���ѱϣ��㼴�����˽�ָ����Ĺ�����\n", me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		remove_effect(me, weapon, speed, damage);
		return ;
	}

	else if(environment(weapon) != me || weapon != me->query_temp("weapon"))
	{
		message_vision("\n$N���б�����ʧ�������ջ��˽�ָ����Ĺ��ơ�\n"NOR, me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("sword") != "yuxiao-jian"
	 || me->query_skill_mapped("finger") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong" )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$Nһ��"+weapon->name()+HIG"����Ȼ�任���������������｣���뵯ָ��ͨ�Ĵ��������\n"NOR, me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		return ;
	}
	else if(  (int)me->query("neili") < 500 ||(int)me->query("jingli") < 500 )
	{
		tell_object(me, HIR "\n�㾪����Ϣ����������˿칥������̷��������²�����ɫ�������������֡���ָ��ͨ�����ơ�\n" NOR);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_temp("th_jianzhi") <= 20 )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$Nһ��"+weapon->name()+HIG"������ʳ�ж�ָ���𽣾������������ʹ�������｣������\n"NOR, me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		return; 
	}

		else call_out("checking", 1, me, weapon,speed,damage);
		return;
}

void remove_effect(object me, object weapon, int speed, int damage) 
{
	if (!me) return;
	me->add_temp("apply/speed", -speed);
	me->add_temp("apply/attack", -damage);  
	me->add_temp("apply/damage", -damage/2);

	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	me->delete_temp("th_jianzhi");
	me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
}
