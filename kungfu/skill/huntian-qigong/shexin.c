// Code of ShenZhou
// shehun.c
// mantian not allow player use shexin on banker ,dealer and wizard may/11/2001
#include <ansi.h>

#define SLEEP_CMD "/cmds/std/oldsleep.c"

string *msgs = ({
	HIY"$N���õض�$n˵�����������ҵ��۾���ǧ�򲻿ɷ���������е���Ƥ���أ�ͷ�Է��Σ�\n"
	   "ȫ��ƣ���������Ǿͱ����۾�˯�ա���$NԽ˵����Խ�����������\n"
	   "$n΢�����ף�Ҫ��תͷ�ܿ�$N���۹⣬����һ˫�۾����Ʊ�$N��Ŀ����ס�ˣ���������\n"
	   "��������$N����Ȼ��֪�����Ĺ�Ƿ������\n"NOR,
	 
	HIW"ֻ��$NЦ���������$n�������Ʒ���â��$nһ��������������ô�ط��ʹ��˻����\n"
	   "�־���$N��ɫ�Ƶ��Լ��������������תͷ�ܿ���������Ƭ�̣��̲�ס��ȥ����$Nһ��\n"
	   "$NЦ�������µúô��ѩ�����ǲ��ǣ���$n�������ǣ��ô��ѩ����$N����\n"
	   "����������ȥ����ѩ������$N˵�����Ǻ��ö���������һ����������֮�⣬$n��ʱ \n"
	   "�������������ȫ��������\n"NOR,

	HIM"ͻȻ$n��$NĿ����ӣ���������΢΢һ��ֻ��$N˫Ŀ�о�����䣬�������ǡ�\n"
	   "$N΢Ц����������������ЪЪ�գ���������ͣ������ö�������$n����ȫ��뵡��\n"
	   "������������ҹ��Ҳ���ЪЪ�ˣ�������ôһ��������Ŀ���ɬ����ƣ������\n"NOR,
	});

	string *laughMsg = ({
	    HIW"$NԽЦԽ������ֱЦ������ֱ��������չ���ȥ��\n"NOR,
	    HIG"$N��ס���ӣ�����������ֱЦ�����۷��ף�������������\n"NOR,
	    HIY"$N����������Ц��ǰ����ϣ��������������Ц������Ц����\n"NOR,
	    HIM"����$nЦ��Խ��Խ��������֪���أ�$Nֻ��ȫ����ƮƮ�Ŀ����쳣������������\n"
	       "������Ц������\n"NOR,
	    HIC"$N��$n��Ŀ���ã�ֻ���������Լ��������󣬻��˯ȥ��������ϲ������\n"
	       "��ʩ�Ƽƣ�ͻ��$n����˫�ۣ������Լ�΢΢��Ц����Ҳ����΢΢һЦ��\n"NOR,
	});
    
private void delay(object, object);
private void fail(object, object, int);
private void wait_kill(object me, object target);
private void start_kill(object target, object me);

void create()
{
  seteuid(getuid());
}

int exert(object me, object target)
{
	object env;
	
	env = environment(me);
	
	if( !me->query("GB_SheXin_OK")) return notify_fail("�ף����ʹ����������\n");
	
	if( env->query("no_fight") || env->query("no_sleep_room") 
		|| env->query("sleep_room") || env->query("hotel"))
		return notify_fail("�㲻����������ʹ����������\n");

	if( !target )
		return notify_fail("��Ҫ��˭ʹ����������\n");

	if( target->query("race") != "����")
		return notify_fail("���ܹ����߶����𣿲����ðɣ�\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 120 )
		return notify_fail("��Ļ���������Ϊ������\n");

	if( target->query("id") == me->query("id") )
		return notify_fail("�㲻�����Լ����ģ�\n");
	//////////////not allow player use shexin on wizard////////////////////
	if( !wizardp(me) && wizardp(target) )
	{
		message_vision(RED"�󵨣��Ҷ���ʦʹ������������\n"NOR, me); 
		this_player()->unconcious();
		this_player()->announce();
		return 1;
	}
	/////////////not allow player use shexin on banker or dealer///////////
	if(target->query("id")=="tang nan" 
		|| target->query("id")=="lao chaofeng"
		|| target->query("id")=="huang zhen"
		|| target->query("id")=="he hongyao"
		|| target->query("dealer"))
		return notify_fail("�޷��Դ���ʹ����������\n");
	//////////////////mantian may/08/2001/////////////////////////////////

	if (target->query("no_shexin"))
		return notify_fail("�޷��Դ���ʹ����������\n");

	if( !living(target) )
		return notify_fail("�㲻�����������ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷�ʹ����������\n");
	
	if(target->is_busy()) return notify_fail("������æ���أ�\n");
	
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	message_vision(CYN"$N����һ����Ц��\n"NOR, me); 
	// let players prepare: this guy is dangerous!!!
	me->start_busy(2);
	if(member_array(me->query("id"), target->query_killer()) != -1)
		call_out("delay", 2, me, target);
	else call_out("delay", 1, me, target);

	return 1;
}

private void delay(object me, object target)
{
	string fam;
	int myLev, tarLev, ok;
	
	if( !present(target, environment(me)))
	{
		tell_object(me, "�ܿ�ϧ�����Ŀ���Ѿ������ˡ�\n");
		return;
	}  
	
	if( me->is_fighting() || target->is_fighting()) {
		tell_object(me,"ս�����޷�ʹ����������\n");
		return;
	}
	
	message_vision( msgs[random(3)], me, target );
	
	myLev = (me->query("combat_exp")/10000) * (me->query("neili")/100) * (me->query_skill("force")/10);
	tarLev = (target->query("combat_exp")/10000) * (target->query("neili")/100) * (target->query_skill("force")/10);

	if(myLev/2 > tarLev) ok = 1;
	else if(tarLev/2 >= myLev) ok = 0;
	else if(random(myLev) > random(tarLev) ) ok = 1;
	else ok = 0;
	
	me->add("neili", -500);
	me->add("qi", -300);
	me->set("jiali", 0);
	
	if(ok == 0)
	{
		me->start_busy(15);
		call_out("fail", 1, me, target, 4);
		return;
	}
	  
	tell_object(target, HIR"\n��ֻ���û����˯�������½���һ�ɣ���ʼ˯����\n"NOR);
	tell_object(target, HIR"��һ�������ͽ��������硣\n"NOR);
	tell_object(me, "\n"HIY + target->query("name") + "�����½�������һ�ɣ���һ�����������������������\n"NOR);

	me->start_busy(1);
	me->set_temp("block_msg/all",1);

	fam = target->query("family/family_name");
	if(fam != "ؤ��") target->set("family/family_name", "ؤ��");
		
	SLEEP_CMD->main(target);
	
	if(fam != "ؤ��") target->set("family/family_name", fam);
	
	me->delete_temp("block_msg/all");
	return;
	
}

private void fail(object me, object target, int times)
{
	if(times != -1)
	{
		message_vision( "\n" + laughMsg[times], me, target);
		call_out("fail", 2, me, target, times-1);
	}
	
	else
	{
		message_vision( HIR"\n$NЦ�ú�Ȼ��������\n"NOR, me);
		me->unconcious();

		if( !userp(target) ) call_out("wait_kill", 3, me, target);
		return;
	}
}

private void wait_kill(object me, object target)
{
	if(!living(target) || !target) return;
	if( environment(me) != environment(target) )
	{
		target->kill_ob(me);
		return;
	}
	
	if(!living(me) ) call_out("wait_kill", 2, me,  target);

	else
	{
		message_vision(HIR"$N����$n����һ������" + RANK_D->query_self_rude(target)+ "���˲������£����������ˣ�������������\n"NOR, target, me);
		call_out("start_kill", 1, target, me);
	}
	return;
}

private void start_kill(object target, object me)
{
	target->kill_ob(me);
	return;
}
