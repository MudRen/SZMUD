// Code of ShenZhou
// qufu.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	int sp, dp, i;

	if( !target ) target = offensive_target(me);

       	if(me->query("lingjiu/shengsi")!=1)
			    return notify_fail("�������������������֣����ǲ�������δ߶����������\n");

	if( !objectp(target) || target == me 
	|| target->query("id") == "mu ren" 
	|| target->query("id") == "shangshan" 
	|| target->query("id") == "mengzhu" 
	|| target->query("id") == "fae" )
                return notify_fail("��Ҫ��˭���ϵ���������\n");

//	if( !userp(target) )
//		return notify_fail("��ֻ����˭������ϵ���������\n");

	if ((int)me->query_skill("xiaowu-xiang", 1)<150
		&& (int)me->query_skill("bahuang-gong", 1)<150
		&& (int)me->query_skill("beiming-shengong", 1)<150)
		return notify_fail("�����ң���ڹ�������������������������\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	

        if( (int)me->query_skill("liuyang-zhang",1) < 150 )
                return notify_fail("�����ɽ�����ƹ������������������������\n");
                
        if ( me->query_skill_mapped("strike") != "liuyang-zhang")
                return notify_fail("��û�б���ɽ�����ƣ�\n"); 

	if( me->is_fighting() || target->is_fighting() )

		return notify_fail("ս���в�������������\n");

	if( !target->query("zf")) 
		return notify_fail("����û�б�������������\n");

	if( (int)me->query("neili",1) < 1000 )
		return notify_fail("���������������������������\n");

	if( target->query("zf_lv") > me->query_skill("bahuang-gong",1) )
		return notify_fail("��İ˻�����Ψ�Ҷ����񹦵����ַ�֮�ˣ���������������\n");

	message_vision(
		HIR "$N˫�ƽ���$n�ĺ󱳣������˹�����һ�������ͷ����ð��һ�ɰ�����\n\n" NOR,
		me, target );
                tell_object(target, HIR "��ֻ���ؿ��泩��࣬һ������ֱ��θ�������Ҳ�崿�˺ܶ࣡\n" NOR);
		tell_object(me, HIG "������Ƽ����������" + target->name() + "�ĺ��ģ������������ȫ�������İ������������ˡ�\n" NOR);
	
		target->delete("zf");
                target->apply_condition("zf_poison",0);
		target->delete("zf_lv");
		
		me->add("max_neili",-30);

		me->start_busy(random(10));
//		target->add("jingli", -random(50));
		target->start_busy(random(3));
		me->add("neili", -200);
		me->add("jingli", -50);

		return 1;
}


