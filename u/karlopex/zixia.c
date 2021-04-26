// Code of ShenZhou
//yun xixia
//by xiaojian on Oct8,2000
//Modify by Scatter

#include <ansi.h>
inherit F_CLEAN_UP;
#include "poison_list.h"

void remove_effect(object me, int amount);
void remove_effect_weapon(object me, object weapon, int amount);
void check(object me, object weapon, int amount);
string data, data2;
int exert(object me, object target)
{
        int skill, str, dex;
        object weapon = me->query_temp("weapon");

	if( me->is_ghost() ) return notify_fail("你现在是鬼魂，无法使用「紫霞神功」。\n");
	
	if( !wizardp(me) && me->query("yun_zixia") != "can" ) return notify_fail("测试中，请勿使用，谢谢合作。\n");
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

        if( (me->query_temp("zixia/lvl") == 1 && (!me->is_fighting() || !objectp(weapon))) || me->query_temp("zixia/lvl") == 2 )
                return notify_fail("你已经施展出紫霞神功了。\n");
        skill = (int)me->query_skill("zixia-gong", 1)+((int)me->query_skill("ziyin-yin", 1)+(int)me->query_skill("zhengqi-jue", 1))/2;
        me->set_temp("zixia/amount", skill);
        skill = me->query_temp("zixia/amount");
        me->set_temp("zixia/weapon",weapon);
	if (objectp(weapon)) me->set_temp("zixia/weapon_name",weapon->name());
        /**************************************************************************************************
        yun zixia
        1.
        突然之间，$N脸上满布紫气，只是那紫气一现即隐，顷刻间又回复了原来脸色。
        2.
        $N气凝丹田，运起紫霞神功，脸上紫气大盛，
        3.
        紫霞神功游走全身，更无丝毫窒滞。
        ******************************************|Modify yun zixia by more mode|Modify by Karlopex@sz ****/
	if( !me->query_temp("zixia/lvl",1) ){
		data = sprintf("attack ==> %d  damage ==> %d  dodge ==> %d  strength ==> %d  dexerity ==> %d ",
			 me->query_temp("apply/attack"), me->query_temp("apply/damage"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"), me->query_temp("apply/dexerity"));
		tell_object(me, MAG"\n你气凝丹田，运起紫霞神功，脸上紫气大盛。\n"NOR);
		message("vision", MAG"\n\n突然之间，"NOR+me->name()+MAG"脸上满布紫气，只是那紫气一现即隐，顷刻间又回复了原来脸色。\n\n" NOR, environment(me), ({me}) );
		me->set_temp("zixia/lvl", 1);
                me->add("neili", -skill * 3 / 2);
                me->receive_damage("jingli",skill*2/3,"精力透支过度死了");
                me->set_temp( "zixia/data1", data );
                me->add_temp( "apply/attack", skill / 2 );
                me->add_temp( "apply/damage", skill * 2 / 5 );
                me->add_temp( "apply/dodge", skill * 2 / 5 );
                me->add_temp( "apply/strength", skill / 4 );
                me->add_temp( "apply/dexerity", skill / 4 );
                data2 = sprintf("attack ==> %d  damage ==> %d  dodge ==> %d  strength ==> %d  dexerity ==> %d  skill ==> %d",
                	me->query_temp("apply/attack"), me->query_temp("apply/damage"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"), me->query_temp("apply/dexerity"), skill);
                tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞功后的数据：　　"+data2+"\n\n"NOR);
                me->start_call_out((:call_other,__FILE__,"remove_effect", me, skill:), skill / 2);
        	call_out("check", 1, me, weapon, skill);
        }else{
		if ( weapon->query("skill_type") == "sword" ){
			if( (!stringp(me->query_skill_mapped("sword")) || me->query_skill_mapped("sword") != "huashan-jianfa") && me->query_temp("zixia/lvl") == 1 )
                		return notify_fail("你已经施展出紫霞神功了。\n");
                        /**************************************************************************************************
                        用剑：
                        紫霞神功施展出来，$W剑尖末端隐隐发出光芒，运起紫霞神功，将华山剑法发挥得淋漓尽致。
                        **************************************************|add yun zixia by sword|Modify by Karlopex@sz ***/
                        data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
                        message_vision(MAG"\n\n突然间$N吸一口气，脸上紫气大盛，紫霞神功施展出来，"+weapon->name()+NOR+MAG"剑尖末端隐隐发出光芒，运起紫霞神功，将华山剑法发挥得淋漓尽致。\n\n" NOR, me);
                        me->set_temp("zixia/lvl",2);
                        me->set_temp("zixia/sword", 1);
                        me->add("neili", -skill / 2);
                        me->receive_damage("jingli",skill/3,"精力透支过度死了");
                        me->set_temp( "zixia/data2", data );
         		me->add_temp( "apply/attack", skill / 8 );
                        me->add_temp( "apply/damage", skill / 4 );
                        weapon->add("weapon_prop/damage", skill / 4);
                        me->start_call_out((:call_other,__FILE__,"remove_effect_weapon",me ,weapon ,skill:),skill/5);
                }else if ( weapon->query("skill_type") == "blade" ){
			if( (!stringp(me->query_skill_mapped("blade")) || me->query_skill_mapped("blade") != "lianyi-dao") && me->query_temp("zixia/lvl") == 1 )
		                return notify_fail("你已经施展出紫霞神功了。\n");
                        /**************************************************************************************************
                        用刀：
                        $N运起紫霞神功，霎时挥刀成风，刀光闪闪，慢慢施发了两仪术数中的极致，刀招源源不绝的递出。
                        **************************************************|add yun zixia by blade|Modify by Karlopex@sz ***/
                        data = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d", me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"));
                        message_vision(MAG"\n\n只见$N脸上紫气隐隐，钢刀刃上发出幽幽蓝光，霎时挥刀成风，"+weapon->name()+NOR+MAG"刀光闪闪，慢慢施发了两仪术数中的极致，刀招源源不绝的递出。\n\n" NOR, me);
                        me->set_temp("zixia/lvl",2);
                        me->set_temp("zixia/blade", 1);
                        me->add("neili", -skill / 2);
                        me->receive_damage("jingli",skill/3,"精力透支过度死了");
                        me->set_temp( "zixia/data2", data );
         		me->add_temp( "apply/attack", skill / 8 );
                        me->add_temp( "apply/damage", skill / 4 );                      
                        weapon->add("weapon_prop/damage", skill / 4 );
                        me->start_call_out((:call_other,__FILE__,"remove_effect_weapon",me ,weapon ,skill:),skill/5);
                }else return notify_fail("你已经施展出紫霞神功了。\n");
                data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d  skill ==> %d",
                	me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), weapon->query("weapon_prop/damage"), skill);
                tell_object(me, HIG"\n\n运紫霞（武器）前的数据：　　"+me->query_temp("zixia/data2")+"\n运紫霞（武器）后的数据：　　"+data2+"\n\n"NOR);
		remove_call_out("check");
        	call_out("check", 1, me, weapon, skill);
        }
        if( me->is_fighting() )
                me->start_busy(1+ random(1));
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me || !me->query_temp("zixia/lvl")) return;
        if(me->query_temp("zixia/lvl") == 2 && me->is_fighting()){
                me->set_temp("zixia/remove", 1);
                remove_effect_weapon(me, me->query_temp("zixia/weapon"), amount);
	}
        me->add_temp( "apply/attack", -amount / 2 );
        me->add_temp( "apply/damage", -amount * 2 / 5 );
        me->add_temp( "apply/dodge", -amount * 2 / 5 );
        me->add_temp( "apply/strength", -amount / 4);
        me->add_temp( "apply/dexerity", -amount / 4);
        if(wizardp(me)){
                data2 = sprintf("attack ==> %d  damage ==> %d  dodge ==> %d  strength ==> %d  dexerity ==> %d",
                	me->query_temp("apply/attack"), me->query_temp("apply/damage"), me->query_temp("apply/dodge"), me->query_temp("apply/strength"), me->query_temp("apply/dexerity"));
                tell_object(me, HIG"\n\n运紫霞前的数据：　　"+me->query_temp("zixia/data1")+"\n运紫霞收功后的数据：　　"+data2+"\n\n"NOR);
        }
       	me->delete_temp("zixia");
	message_vision(MAG"$N的紫霞神功运行完毕，将内力收回丹田。\n"NOR, me);
	remove_call_out("remove_effect");
	remove_call_out("check");
}
void remove_effect_weapon(object me, object weapon, int amount)
{
	string skill_type;
        if (!me || !me->query_temp("zixia/lvl")) return;
        me->add_temp( "apply/attack", -amount / 8 );
        if ( !me->query_temp("zixia/no_weapon",1) )
        	me->add_temp( "apply/damage", -amount / 4 );
        if( objectp(weapon) ){
        	if ( weapon->query("skill_type") == "sword" )
        		skill_type = "剑招";
        	if ( weapon->query("skill_type") == "blade" )
        		skill_type = "刀招";
		weapon->add("weapon_prop/damage", -amount / 4);
	}
        if(me->query_temp("zixia/lvl") == 2){
                me->set_temp("zixia/lvl", 1);
                if(wizardp(me)){
                        data2 = sprintf("attack ==> %d  dodge ==> %d  damage ==> %d  weapon_damage ==> %d",
                        	me->query_temp("apply/attack"), me->query_temp("apply/dodge"), me->query_temp("apply/damage"), (objectp(weapon))?weapon->query("weapon_prop/damage"):0,);
                        tell_object(me, HIG"\n\n运紫霞（武器）前的数据：　　"+me->query_temp("zixia/data2")+"\n运紫霞（武器）收功后的数据：　　"+data2+"\n\n"NOR);
                }
                me->delete_temp("zixia/sword", 1);
                me->delete_temp("zixia/blade", 1);
		if ( !me->query_temp("zixia/no_weapon", 1) )
			if ( !me->is_fighting() )
                		message_vision(MAG"$N运转紫霞功，将附在"+weapon->name()+NOR+MAG"上的紫霞真气散去。\n"NOR, me);
               		else message_vision(MAG"\n$N运转紫霞功收回内劲，"+weapon->name()+NOR+MAG"上的紫霞真气渐渐散去，" +skill_type+ "也恢复平常。\n"NOR, me);
        }
	remove_call_out("remove_effect_weapon");
}
void check(object me, object weapon, int amount)
{
	int poi_lvl;
        if(!me || me->is_ghost() || !me->query_temp("zixia")){
		if ( me && me->is_ghost() )
			me->delete_temp("zixia");
                return;
        }
	if ( !me->is_fighting() && me->query_temp("zixia/lvl") == 2 ){
		me->set_temp("zixia/no_fight",1);
		remove_effect_weapon(me, weapon, amount);
	}
	for( int i=0; i < sizeof(poison_list); i++ )
		if( me->query_condition(poison_list[i]["poison"]) > 0 )
		{
			poi_lvl = me->query_condition(poison_list[i]["poison"]) * poison_list[i]["lvl"];
			if ( me->query("neili") < poi_lvl ) break;
			if ( me->is_fighting() ){
	                        message_vision(MAG "\n只见$N脸上隐隐现出" + poison_list[i]["ansi"] + poison_list[i]["color"] + NOR+MAG"色，转瞬间$N周身紫气大盛，脸色恢复正常。\n"NOR, me);
				tell_object(me, MAG "\n你将" + poison_list[i]["ansi"] + poison_list[i]["name"] + NOR+MAG"的毒用紫霞功逼在体外。");
			}
			me->add("neili",-( poi_lvl * 2 / 3 ));
			me->add("jing",-( poi_lvl * 1 / 2 ));
			me->clear_one_condition(poison_list[i]["poison"]);
			break;
		}
        if( me->query_skill_mapped("force") != "zixia-gong" ){
                me->set_temp("zixia/no_force", 1);
                        message_vision(CYN "\n$N脸色十分苍白，看来$N身上的紫霞真气内功心法相悖，$N只好强行将紫霞真气收回！\n"NOR, me);
                if( me->query_temp("zixia/lvl") == 1 )
                        remove_effect(me, amount);
                if( me->query_temp("zixia/lvl") == 2 )
                        remove_effect_weapon(me, weapon, amount);
                me->receive_wound("jing",amount / 2,"运功不当，走火入魔死了");                
                me->receive_damage("jing",amount ,"运功不当，走火入魔死了");
                me->receive_wound("qi",amount / 2,"运功不当，走火入魔死了");                
                me->receive_damage("qi",amount ,"运功不当，走火入魔死了");
                return;
        }
        if( me->query("neili") < 300 ){
                if( me->query_temp("zixia/lvl"))
                        if( me->is_fighting())
                                message_vision(CYN "\n$N满头大汗，招式大不如先前，看来$N使用紫霞功耗尽了内力，$N只好收回紫霞功！\n"NOR, me);
                        else message_vision(CYN "\n$N满头大汗，面部罩一层紫气，显然是使用紫霞功耗尽了内力，$N运功收内力回丹田！\n"NOR, me);
                me->set_temp("zixia/no_neili", 1);
                if( me->query_temp("zixia/lvl") == 1 )
                        remove_effect(me, amount);
                if( me->query_temp("zixia/lvl") == 2 )
                        remove_effect_weapon(me, weapon, amount);
                return;
        }
        if( !objectp(weapon) && me->query_temp("zixia/lvl") == 2 ){
                me->set_temp("zixia/no_weapon", 1);
                if (me->is_fighting())
                        message_vision(CYN "\n$N的"+me->query_temp("zixia/weapon_name")+NOR+CYN"已失，凌厉的招式已经不复存在！\n"NOR, me);
                remove_effect_weapon(me, weapon, amount);
                return;
        }else if ( me->query_temp("weapon") != me->query_temp("zixia/weapon") && me->query_temp("zixia/lvl") == 2 ){
                me->set_temp("zixia/no_weapon", 1);
                remove_effect_weapon(me, weapon, amount);
                return;
        }else if ( objectp(weapon) && ((me->query_skill_mapped("blade") != "lianyi-dao" && weapon->query("skill_type") == "blade")
                 || (me->query_skill_mapped("sword") != "huashan-jianfa" && weapon->query("skill_type") == "sword")) ){
                if( me->query_temp("zixia/lvl") == 2 ){
                        tell_object(me, CYN "\n你现在的武功和运功方法与紫霞功不同，只好收回用在"+weapon->name()+NOR+CYN"上的紫霞功！\n"NOR, me);
                remove_effect_weapon(me, weapon, amount);
                }
                return;
        }
        call_out("check", 1, me, weapon, amount);
}

/*
yun sangong=> 你吐息呐气，将遍布全身的紫霞真气缓缓散去。
yun zixia=> 你气凝丹田，运起紫霞神功，脸上紫气大盛。

那漢子舉刀擋格，豈知岳不群這一劍伴附著紫霞神功，力道強勁 
，那刀竟然被長劍逼回，一刀一劍，同時砍上他右臂，將他右臂砍下了兩截，鮮血四濺。 
那人大叫一聲，摔倒在地。 
*/
