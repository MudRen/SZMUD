// Code of ShenZhou
//xiaoyao
//by wsky, 20/09/00

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
        string weapon;
        int skill, bonus;
	mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ң����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("xiaoyao",1) )
                return notify_fail("������ʹ����ң������\n");

        if( me->query_skill_mapped("force") != "shenghuo-xuanming" && me->query("id")!="wsky")
                return notify_fail("�����õĲ���ʥ����ڤ�����޷�ʩչ��ң������\n");

        if( me->query_skill("shenghuo-xuanming", 1) < 120 )
                return notify_fail("���ʥ����ڤ�����δ�����޷�ʩչ��ң������\n");

	if( me->query_skill_mapped("parry") != "xiaoyao-jianfa" )
                return notify_fail("��û�н���ң�����������м��У��޷�ʩչ��ң������\n");

        if( me->query_skill("xiaoyao-jianfa",1) < 150 )
                return notify_fail("�����ң������Ϊ���㣬������ʹ����ң������\n");

        skill =  ( me->query_skill("xiaoyao-jianfa")
                + me->query_skill("force") ) / 5;

        if( me->query("neili") <= skill*3 )
                return notify_fail("�����������ʹ����ң������\n");
        if( me->query("jingli") <= skill )
                return notify_fail("��ľ�������ʹ����ң������\n");
        if( me->query("jing") <= skill )
                return notify_fail("��ľ�����ʹ����ң������\n");

        weapon = me->query_temp("weapon");
        
        me->add("neili",-225);
        me->add("jingli",-100);
        
        if(skill>550) skill=550;

	me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill/3);
        me->set_temp("apply/parry", skill/2);
	me->set_temp("apply/dodge", skill/2);
	me->set_temp("apply/defence", skill/2);
	me->set_temp("apply/attack",  skill/2);

        message_vision(HIY "\n\n$N΢΢һЦ��������ת��������ӯ����ৣ�ৣ�ৡ�����$n�̳�������\n\n"NOR, me, target);
        
              
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        
        me->add_temp("apply/attack", skill/2);       
        me->add_temp("apply/damage", skill);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->add_temp("apply/attack", -(skill/2));
        me->add_temp("apply/damage", -(skill));
             
        message_vision(HIY "\n\n��������$N���⻮��һ��ԲȦ���������ֳֽ����������ֳֽ���Ŀ��������Ѱ����$n��������\n" NOR, me, target);
        
        me->set_temp("xiaoyao",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/15 );
        return 1;
}

int remove_effect(object me)
{
        me->set_temp("apply/parry", 0);
	me->set_temp("apply/attack", 0);
	me->set_temp("apply/dodge", 0);
	me->set_temp("apply/speed", 0);
	me->set_temp("apply/defence", 0);
	me->delete_temp("xiaoyao");

	if(me->is_fighting()){
        	message_vision(HIY "\n$Nһ������������һ�ӣ������е�����������\n"NOR, me);
	} else message_vision(HIY "\n$N����������һ�������������ջء�\n"NOR, me);
        return 0;
}


