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
                return notify_fail("һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������") )
	          return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ������һ����\n");

        if( !target->query_temp("huagong") )
                return notify_fail("��������û�б���ȥ����Ҫ���������\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���ֲ���ʩչ����һ����\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua" )
                return notify_fail("�����õĲ����������צ������ʩչ����һ����\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua" )
                return notify_fail("�������Ĳ����������צ������ʩչ����һ����\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("�����õĲ����������צ��ʩչ��������һ����\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("�㻯������Ϊ̫�������������һ����\n");

        if( me->query_skill("sanyin-zhua",1) < 120 )
                return notify_fail("���������צ��Ϊ̫�������������һ����\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������ʹ������һ����\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ�������ʹ������һ����\n");     
        if( me->query("jing") <= 200 )
                return notify_fail("��ľ�����ʹ������һ����\n");

        message_vision(HIR"\n$N��ɫһ������$n��������֮������ָ���ţ����һ�������У���\n"NOR,me,target);		

	skill=me->query_skill("sanyin-zhua",1);

	skill=random(skill+random(200))*2;
	
	if (skill>400) skill=400;
	
	if (skill<120) skill=120;
	
	//please at least test it before updating, the skill is at maximum 500
	//therefore applied damage is quite small by dividing a factor over 10
	//apply attack increase the chance of hit not damage. and, please notify
	//me for the change. thanks

	if( me->query_skill_prepared("strike") == "chousui-zhang" ) {
                me->set_temp("restore", 1);
                me->prepare_skill("strike");
        }
	
	
	me->add_temp("apply/attack", skill);         
                               
        me->add("jiali", (skill/10)*2);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -250);
        me->add("jingli", -150);
        
        me->add("jiali", -((skill/10)*2));
        
        me->add_temp("apply/attack", -(skill));

        if( me->query_temp("restore") ) me->prepare_skill("strike", "chousui-zhang");
	        	
	message_vision(HIY"\n$Nһ��֮������һ�Σ��ƺ�����ƣ����\n"NOR,me,target);		

	me->start_busy(1+random(2));

	return 1;
}        
