// Code of ShenZhou
//01-01-01 wsky

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int second_hit(object me, object target);
int duo(object me, object target);
int duo2(object me, object target);
int end_att(object me);


int perform(object me, object target)
{
        object weapon;
        mapping myfam;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����ơ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	        
        if( me->query_skill_mapped("strike") != "sanhua-juding" )
                return notify_fail("�����õĲ��������۶��ƣ�\n");
        
        if( (int)me->query_skill("xiantian-gong",1) < 150 )
                return notify_fail("�����칦��Ϊ���㣡\n");
                
        if( (int)me->query_skill("taoism",1) < 150 )
                return notify_fail("���ѧ��Ϊ��Ϊ���㣡\n");

	//if(me->query_temp("weapon")->query("name")!="����")
	//	return notify_fail("��ֻ�����÷�������ʩչ����\n");;

        if( me->query_skill("duanyun-bian",1) < 150 )
                return notify_fail("��ġ����Ʊ޷�����Ϊ���㣡\n");

	if( me->query_skill("whip",1) < 150 )
                return notify_fail("��ı޷��Ļ���������ʵ��\n");
        
        if( me->query_con() < 40 )
                return notify_fail("��ĸ���̫�\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������ʹ�á����ơ���\n");
        if( me->query("jingli") <= 200 )
                return notify_fail("��ľ�������ʹ�á����ơ���\n");     
        
        if(me->query("combat_exp")/2>me->query("shen"))
        	return notify_fail("�����������̫�ͣ��޷���ס���е�а�ʹ������������\n");
        
        if(me->query("class")!="taoist" && me->query_skill("taoism",1)<300)
        	return notify_fail("���á����ơ���Ҫ����Ͼ�����������\n");
        
        if(me->query_temp("duanyun"))
        	return notify_fail("������ʹ�á����ơ����С�\n");
        
        message_vision(HIW"\n$N����ƽ�ͣ����������Ʊ޷�ʹ��Բת���⣬����"+(me->query_temp("weapon")->query("name"))+HIW"�������ݶ�������������⣬�����Ʋʽ�$n�𽥰�Χ�����С�\n\n"NOR,me,target);
        
        me->set_temp("duanyun",1);
        
        me->add("neili",-me->query_skill("whip")/2);
        me->add("jingli",-me->query_skill("whip")/3);
        
        remove_call_out("second_hit");
        call_out("second_hit", 3, me, target);        
 
 	return 1;       
}

int second_hit(object me, object target){

	int ap, dp, damage;
	string str;

	me->delete_temp("duanyun",1);
	
	if(me->is_fighting()){
	
		message_vision(HIY"\n$N�����ĵ���һ���������У���$n�͵ط������У�˲ʱ��������ⶸɢ������������\n"NOR, me, target);

		me->add("jiali", me->query_skill("whip",1)/5);
		//me->add_temp("apply/strength", me->query_str());
		me->add_temp("apply/attack",me->query_skill("whip",1));
		me->add_temp("apply/damage",me->query_skill("whip",1));
		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
		me->add("jiali", -me->query_skill("whip",1)/5);
		me->add_temp("apply/attack",-me->query_skill("whip",1));
		me->add_temp("apply/damage",-me->query_skill("whip",1));
		
		//printf("\n");
		me->add("jiali", me->query_skill("whip",1)/5);
		//me->add_temp("apply/strength", me->query_str());
		me->add_temp("apply/attack",me->query_skill("whip",1));
		me->add_temp("apply/damage",me->query_skill("whip",1));
		
		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		
		me->add("jiali", -me->query_skill("whip",1)/5);
		me->add_temp("apply/attack",-me->query_skill("whip",1));
		me->add_temp("apply/damage",-me->query_skill("whip",1));
		//me->add_temp("apply/strength", -me->query_str());
		
		ap=me->query("combat_exp")/100+me->query_skill("whip",1)+me->query("neili");
		dp=target->query("combat_exp")/100+target->query_skill("whip",1)+target->query("neili");
		
		message_vision(HIY"\n���й���$N����һ�䣬����"+me->query_temp("weapon")->query("name")+HIY"�ڿ��л���һ�����ߣ���$n���䡣\n"NOR,me,target);
		
		if(random(ap)>dp/2){
		
			message_vision(HIR"\nֻ����$nһ���ҽУ�"+me->query_temp("weapon")->query("name")+HIR"�Ѿ�����$n��ͷ����Ѫ����һ�ء�\n\n"NOR, me, target);
			
			damage=me->query_skill("duanyun-bian",1)*(random(6)+3);
			
			if (damage<500) damage=500;
				if (damage>2000) damage=2000;
			
			if(wizardp(me))
				printf("damage======%d", damage);
			
			target->add("qi", -damage);
       			target->add("eff_qi", -random(damage));				
		
			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("($N"+str+")\n", target);
			
		} else if(random(ap)>dp/3 && objectp(target->query_temp("weapon")) && me->is_fighting() && random(4)==1){
			
			message_vision(HIG"\n$n�������������ͣ�æ��������"+target->query_temp("weapon")->query("name")+HIG"�мܡ�\n", me, target);
			message_vision(HIW"\n$N����΢��Ѿ���$n���е�"+target->query_temp("weapon")->query("name")+HIW"��ס������ͬʱ�����ضᡣ\n"NOR, me, target);
			
			me->start_busy(3);
			target->start_busy(3);
		
			remove_call_out("duo");
 		        call_out("duo", 3, me, target);        
 		        
 		        return 1;
 			
		} else if(random(ap)>dp/3 && !objectp(target->query_temp("weapon")) && me->is_fighting() && random(4)==1){
		
			message_vision(HIG"\n$n������ת��΢΢һ���Ѿ�������ץס������ͬʱ�����ضᡣ\n"NOR,me,target);
			
			me->start_busy(3);
			target->start_busy(3);
		
			remove_call_out("duo2");
 		        call_out("duo2", 3, me, target);        
 		        
 		        return 1;
		
		} else if(random(ap)>random(dp)) {
		
			message_vision(HIY"\n$n�������������ͣ���֮�����������\n"NOR, me, target);		
		
			message_vision(HIG"\n$Nһ�����У�����һת����������һ�У��͵���$n��ȥ��\n"NOR,me,target);
		
			//me->add_temp("apply/strength", me->query_str());
			me->add_temp("apply/attack",me->query_skill("whip",1));
			me->add_temp("apply/damage",me->query_skill("whip",1));
						
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		
			me->add_temp("apply/attack",-me->query_skill("whip",1));
			me->add_temp("apply/damage",-me->query_skill("whip",1));
			//me->add_temp("apply/strength", -me->query_str());
		
		} else
			message_vision(HIY "\n$n�������������ͣ�æ���Ծ����\n"NOR,me,target);        			
		
		me->start_busy(2+random(2));
	} else 
		message_vision(HIY "\n$N��ս���ѱأ�����������һ�������������ջء�\n"NOR, me);
		
		remove_call_out("second_hit");
		remove_call_out("end_att");
		call_out("end_att", 2, me);
				
		return 1;
}


int end_att(object me){
	
	if (!me->is_fighting()){
		me->set_temp("apply/attack",0);
		me->set_temp("apply/damage",0);
		
	}

	return;

}


int duo(object me, object target){

	int amount1, amount2;
	
	if( !target || !me->is_fighting(target) ) return;

        if( !living(me) || me->is_ghost() ) return;

        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	if((me->query("neili")<(me->query_skill("force",1)*15) || target->query("neili")<(target->query_skill("force",1)*15))){
	
		if(me->query("neili")>target->query("neili")){
		
			message_vision(HIG"\n$N�������������͵ؽ�"+me->query_temp("weapon")->query("name")+HIG"���һ������$n���е�"+target->query_temp("weapon")->query("name")+HIG"�������ֶ����������˵��ϡ�\n"NOR,me,target);

			message_vision(HIG"\n$N˳�־���һ�У���$n��ȥ��"NOR,me,target);

			me->add("jiali", me->query_skill("whip",1));
			me->add_temp("apply/attack",me->query_skill("whip",1));
			me->add_temp("apply/damage",me->query_skill("whip",1));
		
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
			//printf("\n");
					
			me->add("jiali", -me->query_skill("whip",1));
			me->add_temp("apply/attack",-me->query_skill("whip",1));
			me->add_temp("apply/damage",-me->query_skill("whip",1));
					
			target->query_temp("weapon")->move(environment(me));
		
			target->start_busy(2+random(3));
		} else {
	
			message_vision(HIG"\n$n�������������͵ؽ�"+target->query_temp("weapon")->query("name")+HIG"���һ������$N���е�"+me->query_temp("weapon")->query("name")+HIG"�������ֶ����������˵��ϡ�\n"NOR,me,target);
			
			me->query_temp("weapon")->move(environment(me));
		
			me->start_busy(2+random(3));
		}
	
	} else {
	
		message_vision(WHT"\nֻ��$N��$n���������������ض��Լ��ı��У����˵��·��������ĵ���������硣\n"NOR, me, target);
		
		amount1=me->query_skill("force",1);
		amount2=target->query_skill("force",1);
		
		if(random(amount1)>random(amount2)){
			message_vision(YEL"\nֻ��$n����һ�Σ��ƺ���Щ֧�ֲ�ס��\n"NOR, me, target);
			target->add("neili",-amount1);
		} else {
		
			message_vision(YEL"\nֻ��$N����һ�Σ��ƺ���Щ֧�ֲ�ס��\n"NOR, me, target);
			me->add("neili",-amount2);
		}
		me->add("neili", -50);
		target->add("neili", -50);
		
		me->start_busy(4);
		target->start_busy(4);
		
		remove_call_out("duo");
 		call_out("duo", 3, me, target);        
 		        
 		return 1;
	}
	remove_call_out("duo");
	return 1;
}

int duo2(object me, object target){
	
	int amount1, amount2;

	if( !target || !me->is_fighting(target) ) return;

        if( !living(me) || me->is_ghost() ) return;

        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

	if((me->query("neili")<(me->query_skill("force",1)*15) || target->query("neili")<(target->query_skill("force",1)*15))){

		if(me->query("neili")>target->query("neili")){
		
			message_vision(HIG"\n$N�������������͵ؽ�"+me->query_temp("weapon")->query("name")+HIG"��أ�˳�־���һ�У���$n��ȥ��"NOR,me,target);

			me->add("jiali", me->query_skill("whip",1));
			me->add_temp("apply/attack",me->query_skill("whip",1));
			me->add_temp("apply/damage",me->query_skill("whip",1));
		
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
			//printf("\n");
					
			me->add("jiali", -me->query_skill("whip",1));
			me->add_temp("apply/attack",-me->query_skill("whip",1));
			me->add_temp("apply/damage",-me->query_skill("whip",1));
		
			target->start_busy(random(3));
		
		} else {
	
			message_vision(HIG"\n$n�������������͵ؽ�$N���е�"+me->query_temp("weapon")->query("name")+HIG"�������ֶ����������˵��ϡ�\n"NOR,me,target);

			me->query_temp("weapon")->move(environment(me));
		
			me->start_busy(2+random(3));
		}
	
	} else {
		
		message_vision(WHT"\nֻ��$N��$n���������������ضᣬ���˵��·��������ĵ���������硣\n"NOR, me, target);
		
		amount1=me->query_skill("force",1);
		amount2=target->query_skill("force",1);
		
		if(random(amount1)>random(amount2)){
			message_vision(YEL"\nֻ��$n����һ�Σ��ƺ���Щ֧�ֲ�ס��\n"NOR, me, target);
			target->add("neili",-amount1);
		} else {
		
			message_vision(YEL"\nֻ��$N����һ�Σ��ƺ���Щ֧�ֲ�ס��\n"NOR, me, target);
			me->add("neili",-amount2);
		}
		me->add("neili", -50);
		target->add("neili", -50);
		
		me->start_busy(4);
		target->start_busy(4);
		
		remove_call_out("duo2");
 		call_out("duo2", 3, me, target);        
 		        
 		return 1;
	}

	remove_call_out("duo2");
	return 1;
}