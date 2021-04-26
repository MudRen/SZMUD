// Code of ShenZhou
//yun xixia
//by xiaojian on Oct8,2000
//Modify by Scatter

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect1(object me, int amount,int amount1);
void remove_effect2(object me, int amount);
void remove_effect_weapon1(object me, object weapon, int amount);
void remove_effect_weapon2(object me, object weapon, int amount);
void check(object me, object weapon, int amount, int amount1);
string data, data2;
int exert(object me, object target)
{
        int skill, str;
	object weapon = me->query_temp("weapon");

	if (!wizardp(me)) return notify_fail("����ϼ�񹦡����ڵ��ԣ���ʱ�޷�ʹ�á�\n");

        if( me->query_temp("hssf-yanhui"))
                return notify_fail("���Ѿ�ʩչ�����໲���������޷���ʹ�á���ϼ�񹦡���\n");

	if( objectp(target) && target != me ) 
        	return notify_fail("��ֻ������ϼ���������Լ���ս����\n");

        if(me->query_skill("zixia-gong",1) <300)
                return notify_fail("�����ϼ����Ϊ������\n");

        if(me->query_skill("zhengqi-jue",1)<210)
                return notify_fail("�����������򲻵����޷�ʩչ��ϼ�񹦡�\n");

        if(me->query_skill("ziyin-yin",1)<210)
                return notify_fail("����������򲻵����޷�ʩչ��ϼ�񹦡�\n");

        if( me->query_skill_mapped("force") != "zixia-gong" )
        	return notify_fail("�����õĲ�����ϼ����ʩչ������ϼ�񹦣�\n");

        if( (int)me->query("max_neili") <1000)
                return notify_fail("���������Ϊ���㣬�޷�ʩչ��ϼ�񹦣�\n");

        if( (int)me->query("neili") < 800  )
        	return notify_fail("�������������\n");

        if( (int)me->query("max_jingli") <1000)
                return notify_fail("��ľ�����Ϊ���㣬�޷�ʩչ��ϼ�񹦣�\n");

        if( (int)me->query("jingli") < 800  )
        	return notify_fail("��ľ���������\n");
        
        if( me->query("family/master_id") == "feng qingyang" && me->query_skill("zixia-gong",1) < 400)
                return notify_fail("���ǽ��ڸ��֣�ʩչ�������ڵĸ����\n");

	if( me->query_temp("leidong") )
        	return notify_fail("���Ѿ���ʹ���׶������ˣ��޷�ͬʱ������ϼ�񹦣�\n");

        if( me->query_skill("zixia-gong",1) > 350 && me->query_temp("zixia/lvl") == 2 )
                return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
	else if( me->query_skill("zixia-gong",1) < 350 && me->query_temp("zixia/lvl") == 1 )
                return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
	else if( (!stringp(me->query_skill_mapped("sword")) || me->query_skill_mapped("sword") != "huashan-jianfa")
		 && me->query_temp("zixia/lvl") == 3 && (weapon && weapon->query("skill_type") == "sword"))
                return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
	else if( (!stringp(me->query_skill_mapped("blade")) || me->query_skill_mapped("blade") != "lianyi-dao")
		 && me->query_temp("zixia/lvl") == 3 && (weapon && weapon->query("skill_type") == "blade"))
		return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");
	else if( (weapon && (weapon->query("skill_type") == "sword" || weapon->query("skill_type") == "blade"))
		 && me->query_temp("zixia/lvl") == 4 )
		return notify_fail("���Ѿ�ʩչ����ϼ���ˡ�\n");                                            
	me->set_temp("zixia/weapon",weapon);
        skill = (int)me->query_skill("zixia-gong",1);
        str = me->query_str();
    
	/**************************************************************************************************
	yun zixia
	1.
	ͻȻ֮�䣬$N��������������ֻ��������һ�ּ�������̼��ֻظ���ԭ����ɫ��
	2.
	$N�������������ϼ�񹦣�����������ʢ��
	3.
	��ϼ������ȫ������˿�����͡�
	******************************************|Modify yun zixia by more mode|Modify by Karlopex@sz ****/
	if( !weapon ){
		if( !me->query_temp("zixia/lvl",1) ){
			data = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			message_vision(MAG"\n\n$N΢һ����������ϼ�񹦣�����ͻȻ������ʢ��ֻ��������һ�ּ�����$N�����ֻظ��糣��\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill*2/3,"����͸֧��������");
			me->set_temp( "zixia/data1", data );
		    	me->add_temp( "apply/attack", skill / 4  );
		    	me->add_temp( "apply/dodge", skill / 8 );
		    	me->add_temp( "apply/strength", str / 2 );
			me->start_call_out((:call_other,__FILE__,"remove_effect1",me,skill,str:),skill/3);
		}else{
			data = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			message_vision(MAG"\n\n$N��������ٴ�������ϼ�񹦣���ϼ������ȫ������˿�����͡�\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",2);
	        	me->set_temp("zixia/kongshou",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill/3,"����͸֧��������");
			me->set_temp( "zixia/data2", data );
		    	me->add_temp( "apply/attack", skill / 5 );
		    	me->add_temp( "apply/dodge", skill / 10 );
			me->start_call_out((:call_other,__FILE__,"remove_effect2",me,skill:),skill/5);
		}
	}else{
		me->set_temp("zixia/weapon_name",weapon->name());
		if( !me->query_temp("zixia/lvl",1)){
			data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			message_vision(MAG"\n\n$N΢һ����������ϼ�񹦣�����ͻȻ������ʢ��\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",3);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill*2/3,"����͸֧��������");
			me->set_temp( "zixia/data1", data );
		    	me->add_temp( "apply/attack", skill / 4 );
		    	me->add_temp( "apply/dodge", skill / 4 );
		    	me->add_temp( "apply/damage", skill / 6 );
		    	weapon->add("weapon_prop/damage", skill / 6);
			me->start_call_out((:call_other,__FILE__,"remove_effect_weapon1",me ,weapon ,skill:),skill/3);
		}else if ( weapon->query("skill_type") == "sword" ){
			/**************************************************************************************************
			�ý���
			��ϼ��ʩչ������$W����ĩ������������â��������ϼ�񹦣�����ɽ�������ӵ����쾡�¡�
			**************************************************|add yun zixia by sword|Modify by Karlopex@sz ***/
			data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			message_vision(MAG"\n\n$N��ϼ��ʩչ������"+weapon->name()+NOR+MAG"����ĩ������������â��������ϼ�񹦣�����ɽ�������ӵ����쾡�¡�\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",4);
	        	me->set_temp("zixia/wuqi",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill/3,"����͸֧��������");
			me->set_temp( "zixia/data2", data );
		    	me->add_temp( "apply/attack", skill / 5 );
		    	me->add_temp( "apply/dodge", skill / 5 );
		    	me->add_temp( "apply/damage", skill / 5 );
		    	weapon->add("weapon_prop/damage", skill / 5 );
			me->start_call_out((:call_other,__FILE__,"remove_effect_weapon2",me ,weapon ,skill:),skill/5);
		}else if ( weapon->query("skill_type") == "blade" ){
			/**************************************************************************************************
			�õ���
			$N������ϼ�񹦣���ʱ�ӵ��ɷ磬��������������ʩ�������������еļ��£�����ԴԴ�����ĵݳ���
			**************************************************|add yun zixia by blade|Modify by Karlopex@sz ***/
			data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			message_vision(MAG"\n\n$N�ٴ�������ϼ�񹦣���ʱ�ӵ��ɷ磬"+weapon->name()+NOR+MAG"��������������ʩ�������������еļ��£�����ԴԴ�����ĵݳ���\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",4);
	        	me->set_temp("zixia/wuqi",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill/3,"����͸֧��������");
			me->set_temp( "zixia/data2", data );
		    	me->add_temp( "apply/attack", skill/5 );
		    	me->add_temp( "apply/dodge", skill/5 );
		    	me->add_temp( "apply/damage", skill / 5 );		    	
		    	weapon->add("weapon_prop/damage", skill / 5 );
			me->start_call_out((:call_other,__FILE__,"remove_effect_weapon2",me ,weapon ,skill:),skill/5);
		}
	}
	call_out("check", 1, me, weapon, skill, str);
	if( me->is_fighting() )
	        me->start_busy(1+ random(1));
	return 1;
}

void remove_effect1(object me, int amount, int amount1)
{
	if(!me || !me->query_temp("zixia/lvl")) return;
	me->add_temp( "apply/attack", -amount / 4 );
	me->add_temp( "apply/dodge", -amount / 8 );
        me->add_temp( "apply/strength", -amount1);
	if(me->query_temp("apply/strength") < 0) me->set_temp( "apply/strength", 0);
	if(me->query_temp("zixia/lvl") == 2){
        	me->set_temp("zixia/remove",1);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ��һ���չ�������ݣ�����"+data2+"\n\n"NOR);
		}
		remove_effect2(me, amount);
	}else{
		message_vision(MAG"$N����ϼ��������ϣ��������ջص��\n"NOR, me);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ�չ�������ݣ�����"+data2+"\n\n"NOR);
		}
		me->delete_temp("zixia");
	}
}
void remove_effect2(object me, int amount)
{
	if(!me || !me->query_temp("zixia/lvl")) return;
	me->add_temp( "apply/attack", -amount / 5 );
	me->add_temp( "apply/dodge", -amount / 10 );
	if( me->query_temp("zixia/remove") != 1){
        	me->set_temp("zixia/lvl",1);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			tell_object(me, HIG"\n\n�˶�����ϼǰ�����ݣ�����"+me->query("zixia/data2")+"\n����ϼ�ڶ��׶ε����չ������ݣ�����"+data2+"\n\n"NOR);
		}
        	if (me->is_fighting())
			message_vision(MAG"$N����һ�������������ջص��\n"NOR, me);
       	}else{
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ�ڶ����չ�������ݣ�����"+data2+"\n\n"NOR);
		}
		message_vision(MAG"$N����ϼ��������ϣ��������ջص��\n"NOR, me);
	        me->delete_temp("zixia");
	}
}
void remove_effect_weapon1(object me, object weapon, int amount)
{
	if(!me || !me->query_temp("zixia/lvl")) return;
	me->add_temp( "apply/attack", -amount / 4 );
	me->add_temp( "apply/dodge", -amount / 4 );
	if ( !me->query_temp("zixia/no_weapon",1) )
		me->add_temp( "apply/damage", -amount / 6 );
	if(!objectp(weapon)) return;
    	else weapon->add("weapon_prop/damage", -amount / 6);
	if(me->query_temp("zixia/lvl") == 4){
        	me->set_temp("zixia/remove",2);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data2")+"\n����ϼ��һ���չ�������ݣ�����"+data2+"\n\n"NOR);
		}
		remove_effect_weapon2(me, weapon, amount);
	}else{
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ�չ�������ݣ�����"+data2+"\n\n"NOR);
		}
		message_vision(MAG"$N����ϼ��������ϣ��������ջص��\n"NOR, me);
		me->delete_temp("zixia");
	}
}
void remove_effect_weapon2(object me, object weapon, int amount)
{
	if(!me || !me->query_temp("zixia/lvl")) return;
	me->add_temp( "apply/attack", -amount / 5 );
	me->add_temp( "apply/dodge", -amount / 5 );
	if ( !me->query_temp("zixia/no_weapon",1) )
		me->add_temp( "apply/damage", -amount / 5 );
	if(!objectp(weapon)) return;
    	else weapon->add("weapon_prop/damage", -amount / 5);
	if( me->query_temp("zixia/remove") != 2){
        	me->set_temp("zixia/lvl",3);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			tell_object(me, HIG"\n\n�˶�����ϼǰ�����ݣ�����"+me->query("zixia/data2")+"\n����ϼ�ڶ��׶ε����չ������ݣ�����"+data2+"\n\n"NOR);
		}
        	if (me->is_fighting())
			message_vision(MAG"\n$N�����ڽ��ϵ������ջأ�����Ҳ�ָ�ƽ����\n"NOR, me);
       	}else{
		message_vision(MAG"\n$N����ϼ��������ϣ��������ջص��\n"NOR, me);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			tell_object(me, HIG"\n\n����ϼǰ�����ݣ�����"+me->query_temp("zixia/data1")+"\n����ϼ�ڶ����չ�������ݣ�����"+data2+"\n\n"NOR);
		}
	        me->delete_temp("zixia");
	}
}
void check(object me, object weapon, int amount, int amount1)
{
	if(!me || !me->query_temp("zixia/lvl")
	  || me->query_temp("zixia/no_neili",1)
	  || me->query_temp("zixia/no_force",1)) return;
        if( me->query_skill_mapped("force") != "zixia-gong" ){
		me->set_temp("zixia/no_force",1);
                       	message_vision(CYN "\n$N��ɫʮ�ֲ԰ף�����$N���ϵ���ϼ�����ڹ��ķ���㣣�$Nֻ��ǿ�н���ϼ�����ջأ�\n"NOR, me);
		if( me->query_temp("zixia/lvl") == 1 || me->query_temp("zixia/lvl") == 2 )
			remove_effect1(me, amount, amount1);
		if( me->query_temp("zixia/lvl") == 3 || me->query_temp("zixia/lvl") == 4 )
			remove_effect_weapon1(me, weapon, amount);
	    	me->receive_wound("qi",amount,"�˹��������߻���ħ����");		
	    	me->receive_damage("qi",amount*3/2,"�˹��������߻���ħ����");
		return;
	}
	if( me->query("neili") < 300 ){
		if( me->query_temp("zixia/lvl"))
			if( me->is_fighting())
                        	message_vision(CYN "\n$N��ͷ�󺹣���ʽ������ǰ������$Nʹ����ϼ���ľ���������$Nֻ���ջ���ϼ����\n"NOR, me);
			else message_vision(CYN "\n$N��ͷ�󺹣��沿��һ����������Ȼ��ʹ����ϼ���ľ���������$N�˹��������ص��\n"NOR, me);
		me->set_temp("zixia/no_neili",1);
		if( me->query_temp("zixia/lvl") == 1 || me->query_temp("zixia/lvl") == 2 )
			remove_effect1(me, amount, amount1);
		if( me->query_temp("zixia/lvl") == 3 || me->query_temp("zixia/lvl") == 4 )
			remove_effect_weapon1(me, weapon, amount);
		return;
	}
	if( !objectp(weapon) && me->query_temp("zixia/lvl") >= 3){
		if (me->is_fighting())
			message_vision(CYN "\n$N��"+me->query_temp("zixia/weapon_name")+NOR+MAG"��ʧ����������ʽ�Ѿ��������ڣ�\n"NOR, me);
		remove_effect_weapon1(me, weapon, amount);
		return;
	}else if ( me->query_temp("weapon") != me->query_temp("zixia/weapon")){
		if( me->query_temp("zixia/lvl") == 1 || me->query_temp("zixia/lvl") == 2 ){
                        tell_object(me, CYN "\n�����ϼ�����ڿ��ֹ����ϣ����ֱֳ��У�ֻ���ջ���ǰ��������ϼ����\n"NOR, me);
			remove_effect1(me, amount, amount1);
		}else if( me->query_temp("zixia/lvl") == 3 || me->query_temp("zixia/lvl") == 4 ){
			if( !objectp(me->query_temp("weapon")))
	                        tell_object(me, CYN "\n��ı����Ѿ��������У�ֻ���ջ�����"+weapon->name()+NOR+CYN"�ϵ���ϼ����\n"NOR, me);
			else tell_object(me, CYN "\n��ı����ѻ���"+(me->query_temp("weapon"))->name()+NOR+CYN"��ֻ���ջ�����"+weapon->name()+NOR+CYN"�ϵ���ϼ����\n"NOR, me);
			me->set_temp("zixia/no_weapon",1);
			remove_effect_weapon1(me, weapon, amount);
		}
		return;
	}else if ( objectp(weapon) && ((me->query_skill_mapped("blade") != "lianyi-dao" && weapon->query("skill_type") == "blade")
		 || (me->query_skill_mapped("sword") != "huashan-jianfa" && weapon->query("skill_type") == "sword")) ){
		if( me->query_temp("zixia/lvl") == 4 ){
			tell_object(me, CYN "\n�����ڵ��书���˹���������ϼ����ͬ��ֻ���ջ�����"+weapon->name()+NOR+CYN"�ϵ���ϼ����\n"NOR, me);
		remove_effect_weapon1(me, weapon, amount);
		}
		return;
	}
	call_out("check", 1, me, weapon, amount, amount1);
}
/*
yun sangong=> ����Ϣ���������鲼ȫ�����ϼ��������ɢȥ��
yun zixia=> ���������������ϼ�񹦣�����������ʢ��

�ǝh���e�������M֪����Ⱥ�@һ���鸽����ϼ�񹦣��������� 
���ǵ���Ȼ���L���ƻأ�һ��һ����ͬ�r�������ұۣ������ұۿ����˃ɽأ��rѪ�ĞR�� 
���˴��һ��ˤ���ڵء� 
*/