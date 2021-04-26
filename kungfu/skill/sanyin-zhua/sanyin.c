// Code of ShenZhou
//  /k/kungfu/sanyin-zhua/sanyin.c ��������
// wsky 7/3/00

/*
    �����������ȭ��ס��ȭͷ��������ȭ�����ĳ��������ж���ת���飬����
���ܣ�ֻ��ͦ������֡����˵ز������Ǹߺ��ƴ�������������°��������Ҿ���
�ܸ�����ƴ������������ȭ���ϲ�ʹ�������Է�������������ʱ�����อ���ѣ���
֪�����˵�����ȴ���ò��������ֵ�����һ�˾�����������ԴԴ�����������ɢ��
��Ҳ���۲���
*/



#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i;
	string str,*limb,type;
	mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������") && me->query("futou_bang/sacrifice")<30)
	          return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ������������\n");

        if( target->query_temp("huagong") )
                return notify_fail("���������Ѿ�����ȥ������Ҫ�ٻ��ˣ�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���ֲ���ʩչ����������\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua" )
                return notify_fail("�����õĲ����������צ������ʩչ����������\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua" )
                return notify_fail("�������Ĳ����������צ������ʩչ����������\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("�����õĲ����������צ��ʩչ��������������\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("�㻯������Ϊ̫�������������������\n");

        if( me->query_skill("sanyin-zhua",1) < 120 )
                return notify_fail("���������צ��Ϊ̫�������������������\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������ʹ������������\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ�������ʹ������������\n");     
        if( me->query("jing") <= 200 )
                return notify_fail("��ľ�����ʹ������������\n");

        message_vision(HIB"$N����ȭ��ס$nȭͷ��������צ������$nץȥ��\n\n"NOR, me,target);

        myexp = me->query("combat_exp");
        targexp = target->query("combat_exp");
        skill = me->query_skill("huagong-dafa",1);
        
        merand   = random((myexp/1000)*(me->query_skill("force")/10));
        targrand = (myexp/1000)*(target->query_skill("dodge")/10)/3;

        if(merand>targrand) {

                message_vision(HIW"$nת���飬�������ܣ�ֻ��ͦ������֡����˵ز������Ǹ��ֱ�ƴ������\n\n"NOR,me,target);
                tell_object(me, HIG"��Ǳ���ڹ��������ֵ�������ȥ��\n"NOR); 
                tell_object(target, HIR"�����°�������������ԴԴ�����������ɢ����Ҳ���۲���\n\n"NOR);      
                target->set_temp("huagong", 1);
                target->add("neili",-skill*2);
                targneili=target->query("neili");
                if(!userp(target)) {
                        target->set("neili", 0);
                }
                target->add_temp("apply/damage", -skill/10);
                target->add_temp("apply/parry", -skill/20);
		target->add_temp("apply/armor_vs_force", -skill/6);
        	target->add_temp("apply/speed", -skill/6);
	        target->add_temp("apply/defense",  -skill/2);
                target->set("jiali",0);
                target->start_busy(random(2)+1);                
                
        }                      
        else 
        {       
                me->start_busy(random(3)+1);    
                message_vision(HIY "$p�Ͻ�����Ծ�����ɣ��㿪$P�Ĺ�����\n" NOR, me, target);
                tell_object(me, HIY"�����а��룺����⣬��Ȼ����"+RANK_D->query_rude(target)+"�����ˡ���\n\n"NOR);
                me->add("neili",-250);
                return 1;
        }
		
		time=skill/12;
		if(time<5) time=5;
		if(time>20) time=20;
        
                if(userp(target)) call_out("remove_effect", time, me, target, targneili, skill); 
                        else call_out("remove_effect", time, me, target, targneili, skill);

        return 1;
}

private int remove_effect(object me, object target, int neili, int skill)
{
	if ( !objectp( target ) )
		return 1;
        target->delete_temp("huagong");
        if(!userp(target)) {
                target->set("neili",neili);
        }
        target->add_temp("apply/damage", skill/10);
        target->add_temp("apply/parry", skill/20);
	target->add_temp("apply/armor_vs_force", skill/6);
        target->add_temp("apply/speed", skill/6);
	target->add_temp("apply/defense",  skill/2);
        message_vision(HIG"�����ģ�$n������ɢ��������һ˿˿�ؾۻص��\n\n"NOR,me,target);
        return 1;
}
