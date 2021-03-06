// huashan-jianfa
// 狂风快剑 snowyu 2002/4  

#include <combat.h>
#include <ansi.h> 
inherit SKILL;

int sanxianjian(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action":"$N一招「白云出岫」，剑势灵动轻盈，手中$w点向$n的$l",
	"force" : 150,
        "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "白云出岫",
	"damage_type":	"刺伤"
]),
([	"action":"$N使出「有凤来仪」，剑势飞舞而出，内藏五个后着，划向$n的$l",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "有凤来仪",
	"damage_type":	"割伤"
]),
([	"action":"$N吐气开声一招「天绅倒悬」，$w自上而下划出一个大弧，向$n劈砍下去",
	"force" : 220,
        "dodge" : 8,
	"parry" : 8,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "天绅倒悬",
	"damage_type":	"割伤"
]),
([	"action":"$N向前跨上一步，运足内劲，手中$w使出「白虹贯日」，急劲无踌地直刺$n",
	"force" : 250,
        "dodge" : 10,
	"parry" : 10,
	"damage": 35,
	"lvl" : 25,
	"skill_name" : "白虹贯日",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中的$w自左而右地一晃，使出「苍松迎客」带着呼呼风声直削$n的$l",
	"force" : 280,
        "dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 32,
	"skill_name" : "苍松迎客",
	"damage_type":	"割伤"
]),
([	"action":"$N飞身跃起，一式「金雁横空」，卷起漫天剑影，$w向$n电射而去",
	"force" : 310,
        "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 40,
	"skill_name" : "金雁横空",
	"damage_type":	"刺伤"
]),
([	"action":"$N凝气守中，$w逼出雪亮剑芒，挥出「无边落木」，一剑快似一剑底地攻向$n",
	"force" : 350,
        "dodge" : 10,
	"parry" : 10,
	"damage": 55,
	"lvl" : 48,
	"skill_name" : "无边落木",
	"damage_type":	"刺伤"
]),
([      "action":"$N驱剑中宫直进，剑尖颤动，中途忽然转而向上，「青山隐隐」端的是变幻无方",
	"force" : 390,
        "dodge" : 5,
	"parry" : 5,
        "damage": 65,
        "lvl" : 55,
        "skill_name" : "青山隐隐",
        "damage_type":  "刺伤"
]),
([      "action":"$N侧身斜刺一剑，一招「古柏森森」卷带着森然剑气，将$n包围紧裹",
        "force" : 410,
        "dodge" : 8,
	"parry" : 8,
        "damage": 75,
        "lvl" : 62,
        "skill_name" : "古柏森森",
        "damage_type":  "割伤"
]),
([	"action":"$N双手握起$w，剑芒暴长，一式「无双无对」，驭剑猛烈绝伦地往$n冲刺",
	"force" : 450,
	"dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 70,
	"skill_name" : "无双无对",
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("zixia-gong", 1) < 25)
		return notify_fail("你的紫霞神功火候太浅。\n");
	return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}
mapping *sanxianjian_action = ({ 
	([      "action" : HIW"$N鼓荡内劲，凝气聚于$w"+HIW+"上，忽出杀着，一剑朝$n当头直劈"NOR, 
		"damage_type" : "劈伤",
		"damage_limbs" : "头顶" 
	]),      
	([      "action" : HIY"$N一剑不中，次招随至，电光石火间圈转$w"+HIY+"，朝$n拦腰横削"NOR, 
	        "damage_type" : "割伤",
		"damage_limbs" : "腰部"
	]), 
	([        "action" : HIG"$N剑势连环，"+NOR+"$w"+HIG+"反撩，疾刺$n后心，这一剑变招极快，$n背后不生眼睛，势在难以躲避"NOR, 
	        "damage_type" : "刺伤",
		"damage_limbs" : "后心"
	]), 
}); 
mapping query_action(object me, object weapon)
{
        int i, count, level, used, level2, lvl, damage, level3;
        object target;
	string action_msg;
	mapping perform; 
        string *msg =
        ({ 
                HIC"\n$N剑招一剑快似一剑，所激起的风声也越来越强。\n"NOR,
                HIW"\n$N剑锋上所发出的一股劲气渐渐扩展，$n只觉寒气逼人，脸上、手上被疾风刮得隐隐生疼。\n"NOR,
                HIR"\n$N脸上一红，将华山剑法发挥得淋漓尽致,手中"+ weapon->name() +HIR"更使得犹如疾风骤雨一般。！\n"NOR,
                HIY"\n$N吸一口气，手中"+ weapon->name() +HIY"连划三个弧形，一剑快似一剑，如风如雷般攻上！\n"NOR,
               
        });
        level = (int) me->query_skill("huashan-jianfa",1);
        level2 = (int) me->query_skill("zixia-gong",1);
        level3 = (int) me->query_skill("sword",1);
        used = me->query_temp("kuaijian");
        target = me->select_opponent();

        if( !me->query_temp("kuangfeng_kuaijian") && used > 1 && used < 6)
        {
                message_vision( msg[used-2] , me, target);
                me->set_temp("kuangfeng_kuaijian", 1);
                for( count=0; count < used-1; count++ )
                {
                        me->add("jingli", -25);
                        me->add("neili", -50);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                }
                me->delete_temp("kuangfeng_kuaijian", 1);
                me->add_temp("kuaijian", 1);
        }

	if( mapp(perform = me->query_temp("perform")) && !undefinedp(perform["sanxianjian"]) 
		&& intp(i = perform["sanxianjian"]) && i >= 1 && i <= 3 ) { 
			return (["action": sanxianjian_action[i-1]["action"], 
				"damage": level, 
				"force" : me->query_skill("force")/2 + me->query_temp("zixia/lvl")*3, 
				"damage_type": sanxianjian_action[i-1]["damage_type"], 
				"post_action": (: sanxianjian :) ]); 
	}
	if( me->query_temp( "zixia/using" ) == "sword" && me->query_temp("zixia/lvl") >= 2 ){
		i = random(sizeof(action)); 
		if ( me->query_temp("perform/zixia") ) { 
			me->delete_temp("perform/zixia"); 
			action_msg = MAG"突然间$N吸一口气，脸上紫气大盛，紫霞神功施展出来，$w"+MAG+"尖末端隐隐发出光芒，将华山剑法发挥得淋漓尽致"NOR; 
		} else action_msg = action[i]["action"]; 
		if ( wizardp(me) ) tell_object(me, HIG"\n你用的是华山剑法中的"+action[i]["skill_name"]+"伤害力："+action[i]["damage"]+"。\n"NOR);
		if ( !me->query_temp("perform/zixia") && random ( level3 ) > random ( level2 ) )
			damage = ( level3 + level2 - 350 )/ ( 10 + random ( 10 ) );
		if ( wizardp(me) ) tell_object(me, HIG"未运紫霞的伤害力："+action[i]["damage"]+"   运紫霞后的伤害力"+(action[i]["damage"]+damage)+"    增加了"+damage+"点伤害力。\n"NOR);
		return (["action": action_msg, 
			 "damage": action[i]["damage"]+damage, 
			 "force" : action[i]["force"]+level*3, 
 			 "dodge" : action[i]["dodge"], 
			 "parry" : action[i]["parry"], 
			 "damage_type": action[i]["damage_type"], 
//			 "post_action": (: call_other,  SKILL_D("zixia-gong"), "guard_crush" :) 
		]); 
	} 
	for(i = sizeof(action); i > 0; i--)
	        if(level > action[i-1]["lvl"]){
	        	lvl = NewRandom(i, 20, level/5);
			if (wizardp(me)) tell_object(me, HIG"\n你用的是华山剑法中的"+action[lvl]["skill_name"]+"伤害力："+action[lvl]["damage"]+"。\n"NOR);
			if ( level > 200 && level > random( level + level3 ) ){
				damage = ( level3 - 200 ) / ( 15 + random ( 15 ) );
				action_msg = action[lvl]["action"];
				if (wizardp(me)) tell_object(me, HIG"未到二百级的伤害力："+action[lvl]["damage"]+"   二百级后的伤害力"+(action[lvl]["damage"]+damage)+"    增加了"+damage+"伤害力。\n"NOR);
				return ([
			                "action":action_msg,
			                "dodge":action[lvl]["dodge"],
			                "force":action[lvl]["force"],
			                "parry":action[lvl]["parry"],
			                "damage":action[lvl]["damage"] + damage,
			                "damage_type":action[lvl]["damage_type"],
			        ]);
                	}
	        	return action[lvl];
		}
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你的精力不够练华山剑法。\n");
	me->receive_damage("jingli", 25, "精力透支过度死了");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huashan-jianfa/" + action;
}
void finish_sanxianjian(object me, int skill_lvl) 
{ 
	me->set_temp("apply/attack", me->query_temp("original/attack")); 
	me->set_temp("apply/damage", me->query_temp("original/damage")); 
	me->set_temp("apply/speed", me->query_temp("original/speed")); 
	me->delete_temp("perform/sanxianjian"); 
	me->set_temp("perform/disabled", 1); 
	me->delete_temp("original");
	me->start_busy(1+random(3)); 
	remove_call_out("remove_disable"); 
	call_out("remove_disable", skill_lvl / 10, me); 
} 
void remove_disable(object me) 
{ 
	if( !me ) return; 
	me->delete_temp("perform/disabled");
	tell_object(me, CYN"经过一阵调息运气，你觉得丹田中原本紊乱的内息恢复了正常。\n"NOR); 
} 
int sanxianjian(object me, object victim, object weapon, int damage) 
{        
        int ap, dp, pp, level, level2;
	int sxj = me->query_temp("perform/sanxianjian"); 
	int skill_lvl = me->query_skill("huashan-jianfa", 1) / 4; 
        object weapon2 = victim->query_temp("weapon");
	string msg; 
        string attack_skill, dodge_skill, parry_skill, result, sword_skill;

        if( !me->is_fighting(victim) || !living(victim) ) 
                return;

        level = me->query_skill("sword");
        level2 = victim->query_skill("sword");
	sword_skill = victim->query_skill_mapped("sword");
        ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;
        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( victim->is_busy() ) dp /= 3;
        if( dp < 1 ) dp = 1;
	if (wizardp(me)) 
		write("attack:"+me->query_temp("apply/attack")+",damage:"+me->query_temp("apply/damage")+",speed:"+me->query_temp("apply/speed")+"\n"); 
	if( damage > 0 ) { 
		// move this message here because will using die() to make corpse 
		victim->set_temp("guarding", 0); 
		if( victim->query("qi") <= 0 && me->is_killing(victim->query("id")) ) { 
			if ( sxj == 3 ){
				msg = HIR"\n$N这招内劲所注，力道强横之极，$w竟穿体而过，剑尖刺出$n前胸数寸！\n"NOR; 
				message_vision(msg = replace_string(msg, "$w", weapon->name()), me, victim); 
			}
			victim->receive_wound("qi", victim->query("max_qi")+100, "被"+me->name()+"用「"+HIW+"夺命连环三仙剑"+HIM+"」中的第"+chinese_number(sxj)+"剑杀死了"); 
		}
/*		if( sxj == 3 )
			message_vision(HIG"\n转瞬间，$N已经将「"+HIW+"夺命连环三仙剑"+HIG+"」这三招全部使出！\n"NOR, me, victim); 
			finish_sanxianjian(me, skill_lvl);
			return 1;
		}
		finish_sanxianjian(me, skill_lvl); 
		return 1;*/
	}/*else{
		if( ( sxj <= 3 ) && (level2 * 2 / 3 > level || (sword_skill == "dugu-jiujian" && level2 > 500))){
			msg = HIY"$n已经看破$N的连环剑招，";
			switch(random(2)){
				case 1:
			                dodge_skill = victim->query_skill_mapped("dodge");
			                if( !dodge_skill ) dodge_skill = "dodge";
					msg = SKILL_D(dodge_skill)->query_dodge_msg()+msg;
		               		msg += "使出"+to_chinese(dodge_skill)+"的身法将$N的连环剑势全部躲了过去。\n"NOR;
					break;
				case 2:
					if( weapon2 ){
				                parry_skill = victim->query_skill_mapped("parry");
				                if( !parry_skill ) parry_skill = "parry";
						msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, victim)+msg;
		                		msg += "使出"+to_chinese(parry_skill)+"的隔档之法将$N的连环剑势档住了，$N连环剑招已经连接不上。\n"NOR;
					}else{
				                dodge_skill = victim->query_skill_mapped("dodge");
				                if( !dodge_skill ) dodge_skill = "dodge";
						if( random(ap + dp) < random(dp*2) ){
							msg = SKILL_D(dodge_skill)->query_parry_msg()+msg;
			                		msg += "但$N剑势猛烈，空手无法隔挡，$n只好施展轻功躲避。\n"NOR;
						}else{
		                			msg += "$n还未来得及躲闪，$N的"+weapon->name()+"次招已经发出，剑势猛烈如初。\n"NOR;
							me->add("neili", -skill_lvl); 
							me->add("jingli", -skill_lvl); 
							me->add_temp("perform/sanxianjian", 1); 
							me->add_temp("apply/attack", skill_lvl); 
							me->add_temp("apply/damage", -skill_lvl / 2);
							COMBAT_D->do_attack(me, victim, me->query_temp("weapon")); 
							return 1; 
				                } 
					}
					break;
				}
			finish_sanxianjian(me, skill_lvl); 
			return 1; 
		}
	}*/
	if( sxj == 3 ){
		message_vision(HIG"\n转瞬间，$N已经将「"+HIW+"夺命连环三仙剑"+HIG+"」这三招全部使出！\n"NOR, me, victim); 
		finish_sanxianjian(me, skill_lvl);
		return 1;
	}
	me->add("neili", -skill_lvl);
	me->add("jingli", -skill_lvl);
	me->add_temp("perform/sanxianjian", 1);
	me->add_temp("apply/attack", skill_lvl);
	me->add_temp("apply/damage", -skill_lvl);
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	return 1; 
} 
