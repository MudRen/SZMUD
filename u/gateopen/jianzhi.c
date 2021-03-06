// Code of ShenZhou
// jianzhi.c 剑指相配攻击
// maco 8/25/1999
// 神雕侠侣(20)：玉箫剑法与弹指功夫均以攻敌穴道为主，剑指相配，精微奥妙
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

// 穴道 array
string* xuedao = ({
	"巨骨穴",
	"地仓穴",
	"肩井穴",
	"颊车穴",
	"承泣穴",
	"风池穴",
	"章门穴",
	"风府穴",
	"精促穴",
	"陶道穴",
	"强间穴",
	"少海穴",
	"犊鼻穴",
	"神门穴",
	"华盖穴",
	"大椎穴",
	"凤尾穴",
	"至阳穴",
	"劳宫穴",
	"百会穴",
	"灵台穴",
	"太阳穴",
	"膻中穴",
	"命门穴",
	"鸠尾穴",
	"三阴交",
	"天柱穴"
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
		return notify_fail("剑指相配攻击只能对战斗中的对手使用。\n");

 //       if (!me->query("th_jianyi"))
 //	       return notify_fail("你没有领悟剑意，对玉箫剑法的奥妙体会有限，自也无法施展剑指相配的攻势。\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，如何谈得上「剑指相配」？\n");

	if( me->query_temp("th_jianmang"))
		return notify_fail("你正凝神使动「剑芒」，不能再分心了！\n");

	if( me->query_temp("th_jianzhi") >= 1)
		return notify_fail("你正在运用剑指相配的攻势！\n");
	
	if( me->query_skill("yuxiao-jian",1) < 100 )
		return notify_fail("你的玉箫剑法修为未到，不能剑指相配攻敌！\n");

	if( me->query_skill("tanzhi-shentong",1) < 100 )
		return notify_fail("你的弹指神通修为未到，不能剑指相配攻敌！\n");

	if( me->query_skill("bitao-xuangong", 1) < 100 )
		return notify_fail("你的碧涛玄功修为不足，强使剑指相配，徒然分散功力！\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("你所运使的内功无法与剑指相配之心法协调！\n");
	if( me->query_skill_mapped("finger") != "tanzhi-shentong")
		return notify_fail("你所施展的指法并非弹指神通！\n");

	if( me->query_skill_prepared("finger") != "tanzhi-shentong")
		return notify_fail("你还没有准备好施展弹指神通！\n");

	if( me->query("max_neili") <= 1200 )
		return notify_fail("你的内力修为不足，倘若施展剑指相配，反而会有力分则弱的凶险！\n");

	if( me->query("neili") <= 400 )
		return notify_fail("你的内力不足，不足以施展剑指相配！\n");

	if( me->query("jingli") <= 400 )
		return notify_fail("你的精力不足，不足以施展剑指相配！\n");

	damage = me->query_skill("yuxiao-jian") + me->query_skill("tanzhi-shentong",1);
	damage = damage/4;
	sword = (me->query_skill("sword")*jianyi + me->query_skill("finger") )/6;
	speed = (me->query_skill("sword")+me->query_skill("finger") )/200;
	me->add("neili", -250);
	me->add("jingli", -100);

	//命中率增加
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

	message_vision(HIG"$N手中"+weapon->name()+HIG"一腾，飞舞来去，潇洒自如，招招都是攻势，一招不待$n化解开去，第二招第三招已连绵而至！\n"NOR, me,target);

	//第二剑稍快
	me->add_temp("apply/attack", damage/3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -damage/3);

	if(me->is_fighting(target) ){
	message_vision(HIG"$N剑势未止，左手指力已蕴劲弹出，点向$n各路穴道，"+HIW"「玉箫剑法」"NOR+HIG"与"+HIW"「弹指神通」"NOR+HIG"互相为用，越发精微奥妙，变化无穷！\n"NOR, me,target);

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
		message_vision("\n$N见战局已毕，便即收起了剑指相配的功法。\n", me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		remove_effect(me, weapon, speed, damage);
		return ;
	}

	else if(environment(weapon) != me || weapon != me->query_temp("weapon"))
	{
		message_vision("\n$N手中兵器已失，当下收回了剑指相配的攻势。\n"NOR, me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("sword") != "yuxiao-jian"
	 || me->query_skill_mapped("finger") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong" )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$N一挥"+weapon->name()+HIG"，骤然变换招数，不再是玉箫剑法与弹指神通的搭配进击！\n"NOR, me);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		return ;
	}
	else if(  (int)me->query("neili") < 500 ||(int)me->query("jingli") < 500 )
	{
		tell_object(me, HIR "\n你惊觉内息渐弱，再如此快攻恐怕後继乏力，当下不动声色，暗暗收了左手「弹指神通」攻势。\n" NOR);
		me->delete_temp("n_th_Jianzhi_Auto_Dian_Xue");
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_temp("th_jianzhi") <= 20 )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$N一挥"+weapon->name()+HIG"，左手食中二指捏起剑诀，心无旁骛地使动「玉箫剑法」！\n"NOR, me);
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
