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

	if (!wizardp(me)) return notify_fail("「紫霞神功」正在调试，暂时无法使用。\n");

        if( me->query_temp("hssf-yanhui"))
                return notify_fail("你已经施展出「燕徊朝阳」，无法再使用「紫霞神功」。\n");

	if( objectp(target) && target != me ) 
        	return notify_fail("你只能用紫霞神功来提升自己的战力。\n");

        if(me->query_skill("zixia-gong",1) <300)
                return notify_fail("你的紫霞功修为不够。\n");

        if(me->query_skill("zhengqi-jue",1)<210)
                return notify_fail("你的正气决火候不到，无法施展紫霞神功。\n");

        if(me->query_skill("ziyin-yin",1)<210)
                return notify_fail("你的紫氤吟火候不到，无法施展紫霞神功。\n");

        if( me->query_skill_mapped("force") != "zixia-gong" )
        	return notify_fail("你所用的并非紫霞功，施展不出紫霞神功！\n");

        if( (int)me->query("max_neili") <1000)
                return notify_fail("你的内力修为不足，无法施展紫霞神功！\n");

        if( (int)me->query("neili") < 800  )
        	return notify_fail("你的内力不够。\n");

        if( (int)me->query("max_jingli") <1000)
                return notify_fail("你的精力修为不足，无法施展紫霞神功！\n");

        if( (int)me->query("jingli") < 800  )
        	return notify_fail("你的精力不够。\n");
        
        if( me->query("family/master_id") == "feng qingyang" && me->query_skill("zixia-gong",1) < 400)
                return notify_fail("你是剑宗高手，施展不出气宗的高深工夫。\n");

	if( me->query_temp("leidong") )
        	return notify_fail("你已经在使用雷动九天了，无法同时运用紫霞神功！\n");

        if( me->query_skill("zixia-gong",1) > 350 && me->query_temp("zixia/lvl") == 2 )
                return notify_fail("你已经施展出紫霞神功了。\n");
	else if( me->query_skill("zixia-gong",1) < 350 && me->query_temp("zixia/lvl") == 1 )
                return notify_fail("你已经施展出紫霞神功了。\n");
	else if( (!stringp(me->query_skill_mapped("sword")) || me->query_skill_mapped("sword") != "huashan-jianfa")
		 && me->query_temp("zixia/lvl") == 3 && (weapon && weapon->query("skill_type") == "sword"))
                return notify_fail("你已经施展出紫霞神功了。\n");
	else if( (!stringp(me->query_skill_mapped("blade")) || me->query_skill_mapped("blade") != "lianyi-dao")
		 && me->query_temp("zixia/lvl") == 3 && (weapon && weapon->query("skill_type") == "blade"))
		return notify_fail("你已经施展出紫霞神功了。\n");
	else if( (weapon && (weapon->query("skill_type") == "sword" || weapon->query("skill_type") == "blade"))
		 && me->query_temp("zixia/lvl") == 4 )
		return notify_fail("你已经施展出紫霞神功了。\n");                                            
	me->set_temp("zixia/weapon",weapon);
        skill = (int)me->query_skill("zixia-gong",1);
        str = me->query_str();
    
	/**************************************************************************************************
	yun zixia
	1.
	突然之间，$N脸上满布紫气，只是那紫气一现即隐，顷刻间又回复了原来脸色。
	2.
	$N气凝丹田，运起紫霞神功，脸上紫气大盛，
	3.
	紫霞神功游走全身，更无丝毫窒滞。
	******************************************|Modify yun zixia by more mode|Modify by Karlopex@sz ****/
	if( !weapon ){
		if( !me->query_temp("zixia/lvl",1) ){
			data = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			message_vision(MAG"\n\n$N微一凝神，运起紫霞神功，脸上突然紫气大盛！只是那紫气一现即隐，$N脸上又回复如常。\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill*2/3,"精力透支过度死了");
			me->set_temp( "zixia/data1", data );
		    	me->add_temp( "apply/attack", skill / 4  );
		    	me->add_temp( "apply/dodge", skill / 8 );
		    	me->add_temp( "apply/strength", str / 2 );
			me->start_call_out((:call_other,__FILE__,"remove_effect1",me,skill,str:),skill/3);
		}else{
			data = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			message_vision(MAG"\n\n$N气凝丹田，再次运起紫霞神功，紫霞神功游走全身，更无丝毫窒滞。\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",2);
	        	me->set_temp("zixia/kongshou",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill/3,"精力透支过度死了");
			me->set_temp( "zixia/data2", data );
		    	me->add_temp( "apply/attack", skill / 5 );
		    	me->add_temp( "apply/dodge", skill / 10 );
			me->start_call_out((:call_other,__FILE__,"remove_effect2",me,skill:),skill/5);
		}
	}else{
		me->set_temp("zixia/weapon_name",weapon->name());
		if( !me->query_temp("zixia/lvl",1)){
			data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			message_vision(MAG"\n\n$N微一凝神，运起紫霞神功，脸上突然紫气大盛！\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",3);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill*2/3,"精力透支过度死了");
			me->set_temp( "zixia/data1", data );
		    	me->add_temp( "apply/attack", skill / 4 );
		    	me->add_temp( "apply/dodge", skill / 4 );
		    	me->add_temp( "apply/damage", skill / 6 );
		    	weapon->add("weapon_prop/damage", skill / 6);
			me->start_call_out((:call_other,__FILE__,"remove_effect_weapon1",me ,weapon ,skill:),skill/3);
		}else if ( weapon->query("skill_type") == "sword" ){
			/**************************************************************************************************
			用剑：
			紫霞神功施展出来，$W剑尖末端隐隐发出光芒，运起紫霞神功，将华山剑法发挥得淋漓尽致。
			**************************************************|add yun zixia by sword|Modify by Karlopex@sz ***/
			data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			message_vision(MAG"\n\n$N紫霞神功施展出来，"+weapon->name()+NOR+MAG"剑尖末端隐隐发出光芒，运起紫霞神功，将华山剑法发挥得淋漓尽致。\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",4);
	        	me->set_temp("zixia/wuqi",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill/3,"精力透支过度死了");
			me->set_temp( "zixia/data2", data );
		    	me->add_temp( "apply/attack", skill / 5 );
		    	me->add_temp( "apply/dodge", skill / 5 );
		    	me->add_temp( "apply/damage", skill / 5 );
		    	weapon->add("weapon_prop/damage", skill / 5 );
			me->start_call_out((:call_other,__FILE__,"remove_effect_weapon2",me ,weapon ,skill:),skill/5);
		}else if ( weapon->query("skill_type") == "blade" ){
			/**************************************************************************************************
			用刀：
			$N运起紫霞神功，霎时挥刀成风，刀光闪闪，慢慢施发了两仪术数中的极致，刀招源源不绝的递出。
			**************************************************|add yun zixia by blade|Modify by Karlopex@sz ***/
			data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			message_vision(MAG"\n\n$N再次运起紫霞神功，霎时挥刀成风，"+weapon->name()+NOR+MAG"刀光闪闪，慢慢施发了两仪术数中的极致，刀招源源不绝的递出。\n\n" NOR, me);
	        	me->set_temp("zixia/lvl",4);
	        	me->set_temp("zixia/wuqi",1);
		        me->add("neili", -skill);
		    	me->receive_damage("jingli",skill/3,"精力透支过度死了");
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
			tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞第一次收功后的数据：　　"+data2+"\n\n"NOR);
		}
		remove_effect2(me, amount);
	}else{
		message_vision(MAG"$N的紫霞神功运行完毕，将内力收回丹田。\n"NOR, me);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞收功后的数据：　　"+data2+"\n\n"NOR);
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
			tell_object(me, HIG"\n\n运二段紫霞前的数据：　　"+me->query("zixia/data2")+"\n运紫霞第二阶段单独收功的数据：　　"+data2+"\n\n"NOR);
		}
        	if (me->is_fighting())
			message_vision(MAG"$N深吸一口气，将内力收回丹田。\n"NOR, me);
       	}else{
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  strength ==> %d ", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"));
			tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞第二次收功后的数据：　　"+data2+"\n\n"NOR);
		}
		message_vision(MAG"$N的紫霞神功运行完毕，将内力收回丹田。\n"NOR, me);
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
			tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data2")+"\n运紫霞第一次收功后的数据：　　"+data2+"\n\n"NOR);
		}
		remove_effect_weapon2(me, weapon, amount);
	}else{
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞收功后的数据：　　"+data2+"\n\n"NOR);
		}
		message_vision(MAG"$N的紫霞神功运行完毕，将内力收回丹田。\n"NOR, me);
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
			tell_object(me, HIG"\n\n运二段紫霞前的数据：　　"+me->query("zixia/data2")+"\n运紫霞第二阶段单独收功的数据：　　"+data2+"\n\n"NOR);
		}
        	if (me->is_fighting())
			message_vision(MAG"\n$N将用在剑上的内力收回，剑招也恢复平常。\n"NOR, me);
       	}else{
		message_vision(MAG"\n$N的紫霞神功运行完毕，将内力收回丹田。\n"NOR, me);
		if(wizardp(me)){
			data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
			tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞第二次收功后的数据：　　"+data2+"\n\n"NOR);
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
                       	message_vision(CYN "\n$N脸色十分苍白，看来$N身上的紫霞真气内功心法相悖，$N只好强行将紫霞真气收回！\n"NOR, me);
		if( me->query_temp("zixia/lvl") == 1 || me->query_temp("zixia/lvl") == 2 )
			remove_effect1(me, amount, amount1);
		if( me->query_temp("zixia/lvl") == 3 || me->query_temp("zixia/lvl") == 4 )
			remove_effect_weapon1(me, weapon, amount);
	    	me->receive_wound("qi",amount,"运功不当，走火入魔死了");		
	    	me->receive_damage("qi",amount*3/2,"运功不当，走火入魔死了");
		return;
	}
	if( me->query("neili") < 300 ){
		if( me->query_temp("zixia/lvl"))
			if( me->is_fighting())
                        	message_vision(CYN "\n$N满头大汗，招式大不如先前，看来$N使用紫霞功耗尽了内力，$N只好收回紫霞功！\n"NOR, me);
			else message_vision(CYN "\n$N满头大汗，面部罩一层紫气，显然是使用紫霞功耗尽了内力，$N运功收内力回丹田！\n"NOR, me);
		me->set_temp("zixia/no_neili",1);
		if( me->query_temp("zixia/lvl") == 1 || me->query_temp("zixia/lvl") == 2 )
			remove_effect1(me, amount, amount1);
		if( me->query_temp("zixia/lvl") == 3 || me->query_temp("zixia/lvl") == 4 )
			remove_effect_weapon1(me, weapon, amount);
		return;
	}
	if( !objectp(weapon) && me->query_temp("zixia/lvl") >= 3){
		if (me->is_fighting())
			message_vision(CYN "\n$N的"+me->query_temp("zixia/weapon_name")+NOR+MAG"已失，凌厉的招式已经不复存在！\n"NOR, me);
		remove_effect_weapon1(me, weapon, amount);
		return;
	}else if ( me->query_temp("weapon") != me->query_temp("zixia/weapon")){
		if( me->query_temp("zixia/lvl") == 1 || me->query_temp("zixia/lvl") == 2 ){
                        tell_object(me, CYN "\n你的紫霞功运在空手功夫上，现手持兵刃，只好收回先前发出的紫霞功！\n"NOR, me);
			remove_effect1(me, amount, amount1);
		}else if( me->query_temp("zixia/lvl") == 3 || me->query_temp("zixia/lvl") == 4 ){
			if( !objectp(me->query_temp("weapon")))
	                        tell_object(me, CYN "\n你的兵器已经不在手中，只好收回用在"+weapon->name()+NOR+CYN"上的紫霞功！\n"NOR, me);
			else tell_object(me, CYN "\n你的兵器已换成"+(me->query_temp("weapon"))->name()+NOR+CYN"，只好收回用在"+weapon->name()+NOR+CYN"上的紫霞功！\n"NOR, me);
			me->set_temp("zixia/no_weapon",1);
			remove_effect_weapon1(me, weapon, amount);
		}
		return;
	}else if ( objectp(weapon) && ((me->query_skill_mapped("blade") != "lianyi-dao" && weapon->query("skill_type") == "blade")
		 || (me->query_skill_mapped("sword") != "huashan-jianfa" && weapon->query("skill_type") == "sword")) ){
		if( me->query_temp("zixia/lvl") == 4 ){
			tell_object(me, CYN "\n你现在的武功和运功方法与紫霞功不同，只好收回用在"+weapon->name()+NOR+CYN"上的紫霞功！\n"NOR, me);
		remove_effect_weapon1(me, weapon, amount);
		}
		return;
	}
	call_out("check", 1, me, weapon, amount, amount1);
}
/*
yun sangong=> 你吐息呐气，将遍布全身的紫霞真气缓缓散去。
yun zixia=> 你气凝丹田，运起紫霞神功，脸上紫气大盛。

那漢子舉刀擋格，豈知岳不群這一劍伴附著紫霞神功，力道強勁 
，那刀竟然被長劍逼回，一刀一劍，同時砍上他右臂，將他右臂砍下了兩截，鮮血四濺。 
那人大叫一聲，摔倒在地。 
*/