// huashan-jianfa
// ���콣 snowyu 2002/4  

#include <combat.h>
#include <ansi.h> 
inherit SKILL;

int sanxianjian(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action":"$Nһ�С����Ƴ�ᶡ��������鶯��ӯ������$w����$n��$l",
	"force" : 150,
        "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "���Ƴ��",
	"damage_type":	"����"
]),
([	"action":"$Nʹ�����з����ǡ������Ʒ���������ڲ�������ţ�����$n��$l",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "�з�����",
	"damage_type":	"����"
]),
([	"action":"$N��������һ�С�����������$w���϶��»���һ���󻡣���$n������ȥ",
	"force" : 220,
        "dodge" : 8,
	"parry" : 8,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "������",
	"damage_type":	"����"
]),
([	"action":"$N��ǰ����һ���������ھ�������$wʹ�����׺���ա��������޳��ֱ��$n",
	"force" : 250,
        "dodge" : 10,
	"parry" : 10,
	"damage": 35,
	"lvl" : 25,
	"skill_name" : "�׺����",
	"damage_type":	"����"
]),
([	"action":"$N���е�$w������ҵ�һ�Σ�ʹ��������ӭ�͡����ź�������ֱ��$n��$l",
	"force" : 280,
        "dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 32,
	"skill_name" : "����ӭ��",
	"damage_type":	"����"
]),
([	"action":"$N����Ծ��һʽ�������ա����������콣Ӱ��$w��$n�����ȥ",
	"force" : 310,
        "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type":	"����"
]),
([	"action":"$N�������У�$w�Ƴ�ѩ����â���ӳ����ޱ���ľ����һ������һ���׵ع���$n",
	"force" : 350,
        "dodge" : 10,
	"parry" : 10,
	"damage": 55,
	"lvl" : 48,
	"skill_name" : "�ޱ���ľ",
	"damage_type":	"����"
]),
([      "action":"$N�����й�ֱ���������������;��Ȼת�����ϣ�����ɽ�������˵��Ǳ���޷�",
	"force" : 390,
        "dodge" : 5,
	"parry" : 5,
        "damage": 65,
        "lvl" : 55,
        "skill_name" : "��ɽ����",
        "damage_type":  "����"
]),
([      "action":"$N����б��һ����һ�С��Ű�ɭɭ�������ɭȻ��������$n��Χ����",
        "force" : 410,
        "dodge" : 8,
	"parry" : 8,
        "damage": 75,
        "lvl" : 62,
        "skill_name" : "�Ű�ɭɭ",
        "damage_type":  "����"
]),
([	"action":"$N˫������$w����â������һʽ����˫�޶ԡ���Ԧ�����Ҿ��׵���$n���",
	"force" : 450,
	"dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 70,
	"skill_name" : "��˫�޶�",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zixia-gong", 1) < 25)
		return notify_fail("�����ϼ�񹦻��̫ǳ��\n");
	return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}
mapping *sanxianjian_action = ({ 
	([      "action" : HIW"$N�ĵ��ھ�����������$w"+HIW+"�ϣ�����ɱ�ţ�һ����$n��ͷֱ��"NOR, 
		"damage_type" : "����",
		"damage_limbs" : "ͷ��" 
	]),      
	([      "action" : HIY"$Nһ�����У��������������ʯ���Ȧת$w"+HIY+"����$n��������"NOR, 
	        "damage_type" : "����",
		"damage_limbs" : "����"
	]), 
	([        "action" : HIG"$N����������"+NOR+"$w"+HIG+"���ã�����$n���ģ���һ�����м��죬$n�������۾����������Զ��"NOR, 
	        "damage_type" : "����",
		"damage_limbs" : "����"
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
                HIC"\n$N����һ������һ����������ķ���ҲԽ��Խǿ��\n"NOR,
                HIW"\n$N��������������һ�ɾ���������չ��$nֻ���������ˣ����ϡ����ϱ�����ε��������ۡ�\n"NOR,
                HIR"\n$N����һ�죬����ɽ�������ӵ����쾡��,����"+ weapon->name() +HIR"��ʹ�����缲������һ�㡣��\n"NOR,
                HIY"\n$N��һ����������"+ weapon->name() +HIY"�����������Σ�һ������һ����������װ㹥�ϣ�\n"NOR,
               
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
			action_msg = MAG"ͻȻ��$N��һ����������������ʢ����ϼ��ʩչ������$w"+MAG+"��ĩ������������â������ɽ�������ӵ����쾡��"NOR; 
		} else action_msg = action[i]["action"]; 
		if ( wizardp(me) ) tell_object(me, HIG"\n���õ��ǻ�ɽ�����е�"+action[i]["skill_name"]+"�˺�����"+action[i]["damage"]+"��\n"NOR);
		if ( !me->query_temp("perform/zixia") && random ( level3 ) > random ( level2 ) )
			damage = ( level3 + level2 - 350 )/ ( 10 + random ( 10 ) );
		if ( wizardp(me) ) tell_object(me, HIG"δ����ϼ���˺�����"+action[i]["damage"]+"   ����ϼ����˺���"+(action[i]["damage"]+damage)+"    ������"+damage+"���˺�����\n"NOR);
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
			if (wizardp(me)) tell_object(me, HIG"\n���õ��ǻ�ɽ�����е�"+action[lvl]["skill_name"]+"�˺�����"+action[lvl]["damage"]+"��\n"NOR);
			if ( level > 200 && level > random( level + level3 ) ){
				damage = ( level3 - 200 ) / ( 15 + random ( 15 ) );
				action_msg = action[lvl]["action"];
				if (wizardp(me)) tell_object(me, HIG"δ�����ټ����˺�����"+action[lvl]["damage"]+"   ���ټ�����˺���"+(action[lvl]["damage"]+damage)+"    ������"+damage+"�˺�����\n"NOR);
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
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������ɽ������\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
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
	tell_object(me, CYN"����һ���Ϣ����������õ�����ԭ�����ҵ���Ϣ�ָ���������\n"NOR); 
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
				msg = HIR"\n$N�����ھ���ע������ǿ��֮����$w���������������̳�$nǰ�����磡\n"NOR; 
				message_vision(msg = replace_string(msg, "$w", weapon->name()), me, victim); 
			}
			victim->receive_wound("qi", victim->query("max_qi")+100, "��"+me->name()+"�á�"+HIW+"�����������ɽ�"+HIM+"���еĵ�"+chinese_number(sxj)+"��ɱ����"); 
		}
/*		if( sxj == 3 )
			message_vision(HIG"\nת˲�䣬$N�Ѿ�����"+HIW+"�����������ɽ�"+HIG+"��������ȫ��ʹ����\n"NOR, me, victim); 
			finish_sanxianjian(me, skill_lvl);
			return 1;
		}
		finish_sanxianjian(me, skill_lvl); 
		return 1;*/
	}/*else{
		if( ( sxj <= 3 ) && (level2 * 2 / 3 > level || (sword_skill == "dugu-jiujian" && level2 > 500))){
			msg = HIY"$n�Ѿ�����$N���������У�";
			switch(random(2)){
				case 1:
			                dodge_skill = victim->query_skill_mapped("dodge");
			                if( !dodge_skill ) dodge_skill = "dodge";
					msg = SKILL_D(dodge_skill)->query_dodge_msg()+msg;
		               		msg += "ʹ��"+to_chinese(dodge_skill)+"������$N����������ȫ�����˹�ȥ��\n"NOR;
					break;
				case 2:
					if( weapon2 ){
				                parry_skill = victim->query_skill_mapped("parry");
				                if( !parry_skill ) parry_skill = "parry";
						msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, victim)+msg;
		                		msg += "ʹ��"+to_chinese(parry_skill)+"�ĸ���֮����$N���������Ƶ�ס�ˣ�$N���������Ѿ����Ӳ��ϡ�\n"NOR;
					}else{
				                dodge_skill = victim->query_skill_mapped("dodge");
				                if( !dodge_skill ) dodge_skill = "dodge";
						if( random(ap + dp) < random(dp*2) ){
							msg = SKILL_D(dodge_skill)->query_parry_msg()+msg;
			                		msg += "��$N�������ң������޷�������$nֻ��ʩչ�Ṧ��ܡ�\n"NOR;
						}else{
		                			msg += "$n��δ���ü�������$N��"+weapon->name()+"�����Ѿ��������������������\n"NOR;
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
		message_vision(HIG"\nת˲�䣬$N�Ѿ�����"+HIW+"�����������ɽ�"+HIG+"��������ȫ��ʹ����\n"NOR, me, victim); 
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
