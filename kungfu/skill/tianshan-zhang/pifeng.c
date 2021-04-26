// Code of ShenZhou
//pifeng ������
//by wsky, 20/08/00

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int second_hit(object me, object target);

int perform(object me, object target)
{
        string weapon, str;
        int skill, bonus, damage;
	mapping myfam;

        if( !target ) target = offensive_target(me);

	if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������") && me->query("id")!="wsky")
	          return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ�������ȷ���\n");

	if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ȷ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ( me->query_temp("sucked") )
                return notify_fail("��ո���ȡ���������޷�ʩչ�����ȷ���\n");

        if( me->query_temp("pifeng",1))
                return notify_fail("������ʹ�������ȷ���\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("�����õĲ��ǻ����󷨣��޷�ʩչ�����ȷ���\n");

        if( me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("��Ļ����󷨻��δ�����޷�ʩչ�����ȷ���\n");

	if( me->query_skill_mapped("parry") != "tianshan-zhang" )
                return notify_fail("��û�н���ɽ�ȷ��������м��У��޷�ʩչ�����ȷ���\n");

        if( me->query_skill("tianshan-zhang",1) < 150 )
                return notify_fail("�����ɽ�ȷ���Ϊ���㣬������ʹ�������ȷ���\n");

        skill =  ( me->query_skill("tianshan-zhang")
                + me->query_skill("force") ) / 5;

        if( me->query("neili") <= skill*3 )
                return notify_fail("�����������ʹ�������ȷ���\n");
        if( me->query("jingli") <= skill )
                return notify_fail("��ľ�������ʹ�������ȷ���\n");
        if( me->query("jing") <= skill )
                return notify_fail("��ľ�����ʹ�������ȷ���\n");

        weapon = me->query_temp("weapon");

        skill = me->query_skill("parry",1)+random(me->query_skill("tianshan-zhang",1));
        
        if(skill>450) skill=450;

	me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill);
        me->set_temp("apply/parry", skill);
	me->set_temp("apply/dodge", skill);
	me->set_temp("apply/defence", skill);
	me->set_temp("apply/attack",  skill);
	
	if (wizardp(me)) {
		printf("------------>my skill=%d", skill);
	}
	
        message_vision(HIW "\n\n$Nս������������һ�ڣ����һ������"+(me->query_temp("weapon"))->query("name")+HIW"�߸߾���ʹ����$n����һ�С�\n\n"NOR, me, target);
        
        me->add_temp("apply/attack", skill/2);       
        me->add_temp("apply/damage", skill/2);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -150);
        me->add("jingli", -50);
        
        me->add_temp("apply/attack", -(skill/2));
        me->add_temp("apply/damage", -(skill/2));
        
        if (me->query("tianshan")==1) {
        
        	me->add("neili", -350);
        	me->add("jingli", -250);
                
		message_vision(HIW "\n\n$Nһ�в��أ�����������"+(me->query_temp("weapon"))->query("name")+HIW"�������߶����ֳ�ҫ�۹�â��\n\n"NOR, me, target);
        	message_vision(HIB "$N��$n��������֮�ʣ�һ����������������$n���ؿڰ�ȥ��\n"NOR,me,target);
        	if((me->query("combat_exp")/3)>random(target->query("combat_exp"))){
        		message_vision(HIR "\n$nһ���ƺߣ��ؿ����ƣ�ͬʱ������й������\n"NOR,me,target);        			
        		damage=random(-me->query("shen"));
        		if (damage>1000) damage=1000;
       				if (damage<500) damage=500;        		
        		target->add("qi", -damage);
        		target->add("eff_qi", -random(damage));
        		target->add("neili", -me->query_skill("force",1)*(3+random(2)));
        		me->add("neili", random(me->query_skill("force",1)*(3+random(2))));
        		if (wizardp(me)) {
				printf("------------>my damage=%d\n", damage);
			}	
			
			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
        
        	} else {
        		message_vision(HIY "\n$n����������թ��æ���Ծ����\n"NOR,me,target);        			
        	}
        
        	remove_call_out("second_hit");
        	call_out("second_hit", 3+random(5), me, target);
        	//me->start_call_out( (: call_other, __FILE__, "second_hit", me, target :), 3+random(3) );
        }
             
        message_vision(HIY "\n\n$N�������˺�һ������"+(me->query_temp("weapon"))->query("name")+HIY"ʹ�û������磬�����ػ�סȫ�����¸���Ҫ����\n\n" NOR, me, target);
        
        me->set_temp("pifeng",1);
        
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), me->query_skill("tianshan-zhang",1)/10 );
        return 1;
}

int second_hit(object me, object target){
	int damage;
	string str;
	
	if (me->query_temp("pifeng")==1 && me->is_fighting()){
	
		me->add("neili", -100);
       		me->add("jingli", -50);
                
		message_vision(HIY "\n\n$Nǳ�����������������дʣ�ͻȻ���Ƚ����֣���������$n��ȥ��\n"NOR, me, target);
     
        	
       		if((me->query("combat_exp")/3*2)>random(target->query("combat_exp"))){
       			message_vision(HIR "\n$nһ���ƺߣ��ؿ����ƣ�ͬʱ������й������\n"NOR,me,target);        			
       			damage=random(-me->query("shen"));
       			if (damage>500) damage=500;
       				if (damage<500) damage=500;       			
       			target->add("qi", -damage);
       			target->add("eff_qi", -random(damage));
       			target->add("neili", -me->query_skill("force",1)*(2+random(2)));
       			me->add("neili", random(me->query_skill("force",1)*(3+random(2))));
       			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
       			if (wizardp(me)) {
				printf("------------>my damage=%d", damage);
			}	
       		} else {
       			message_vision(HIY "\n$n����������թ��æ���Ծ����\n"NOR,me,target);        			
       		}
       		
       		if (wizardp(me)){
       			printf("again.............\n");
       		}

       		remove_call_out("second_hit");
       		call_out("second_hit", 5+random(5), me, target);
       		//me->start_call_out( (: call_other, __FILE__, "second_hit", me, target :), 3+random(3) );	
       	
	}

       	return 1;
        
}

int remove_effect(object me)
{
        me->set_temp("apply/parry", 0);
	me->set_temp("apply/attack", 0);
	me->set_temp("apply/dodge", 0);
	me->set_temp("apply/damage",  0);
	me->set_temp("apply/speed", 0);
	me->set_temp("apply/defence", 0);
	me->delete_temp("pifeng");
	if(me->query_temp("fresh")==1) me->add_temp("apply/armor", -500);
	if(me->is_fighting()){
        	message_vision(HIY "\n$N΢��ƣ����ֻ�ý��������е��ȷ�����������\n"NOR, me);
	} else message_vision(HIY "\n$N����������һ�������������ջء�\n"NOR, me);
        return 0;
}


