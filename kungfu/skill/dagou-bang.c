// Code of ShenZhou
// dagou-bang.c
// write by     Xiang
// Ryu added parry msg.
// fear added 3 more zhao (Jan/2000), feng effect (march 2000)

#include <ansi.h>

inherit SKILL;

nomask int parry_available() { return 1; }
string *parry_msg =     ({
                "$p$W���𣬾������$P����ʽ���ò��־�һ��һ���������쳣��ȥ��ȫ�����������ϵ�֮����$P��Ծ��ܣ���֪$W��Ȼ��ת����$P�Ľ��֡�$Pһ�����ģ��н�Ծ����\n",
                "$p��������ӵأ�ֱ�����ء���һ��ȥ�ƹŹ֣����ɴ���$P$w��$P��һ����δʹ�㣬��֪�����æԾ����ܡ�\n",
                "$p���в�֧�������ƶ��Ų���ʹ�����⡹�־���ס$P$w���ơ�\n",
                "���վ���������һ����$p$W��ת�����ش���$P���ҹɡ���һ���ᷢ��������$P$wδ��$p���壬�����ȵñ����˴��У�$P��æ��$w���С�\n",
                "$pȴ��������������$W�ϡ�$Pֻ��$p�������$W�о���һ�ɼ�ǿ������ǣ����$P$w����бб��$w������ƫ�󣬱���ƫ�ҡ�\n",
                "$p�ۼ�Σ�����Ӱ���ס��ǰ�����˼��ּ��ͣ�ʹ��"+HIG"��������ͷ��"NOR+"����$P$w���䡣\n",
                "$p��ʱ��$Pվ�����������ܲ�������æ��ת$W����$P��ʽһһ������\n",
});
string query_parry_msg(object weapon, object victim)
{
                object ob;

                if (!objectp(ob = victim->query_temp("weapon"))
                || ob->query("skill_type") != "stick" || victim->query_skill("dagou-bang", 1) <  100)
                                return SKILL_D("parry")->query_parry_msg(weapon);
                else
                                return replace_string(parry_msg[random(sizeof(parry_msg))],     "$W", ob->name());
}
mapping *action = ({
([              "action": "$Nʹ��һ��"+HIG"������˫Ȯ��"+NOR"������$w���������������$n��$l",
		"force" : 210,
                "dodge":  10,
                "damage": 90,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"

]),
([              "action": "$N����$w���һζ���һ��"+HIG"������Ѱ�ߡ�"+NOR"��$n��$l��ȥ",
                "force" : 250,
                "dodge":  20,
                "damage": 60,
                "damage_type": "����"
]),
([              "action": "$N����$w���Ӹ�����ʹһ��"+HIG"����ݾ��ߡ�"+NOR"����$n��$l",
                "force" : 330,
                "dodge":  30,
                "damage": 90,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"
]),
([              "action": "$Nʩ��"+HIG"���������졹"+NOR"��$w����������$n��ȥ",
                "force" : 400,
                "dodge":  20,
                "damage": 60,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"
]),
([              "action": "$N����$w���к�ɨ��һ��"+HIG"�����ع��Ρ�"+NOR"�����з���������Ѹ�ͣ�����$nҪ��",
                "force" : 410,
                "dodge":  20,
                "damage": 100,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"
]),
([              "action": "$Nͻʹһ��"+HIG"��б�򹷱���"+NOR"�����о����ޱȣ�$wһ�ϣ��ѻ���$n��$l",
                "force" : 420,
                "dodge":  25,
                "damage": 110,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"
]),
([              "action": "$N����$w��һ��"+HIG"������ͷ��"+NOR"����$n$l��ȥ�����ֺ���������"+HIG"���򹷰�����"+NOR"�еĸ���",
                "force" : 430,
                "dodge":  20,
                "damage": 120,
                "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"
]),
});

int     valid_enable(string     usage) { return usage == "stick" ||     usage == "parry"; }

int     valid_learn(object me)
{
                if ((int)me->query("max_neili") < 100)
                                return notify_fail("�������������\n");
                return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        object ob, victim;
        string* msghit, msg;
        string* msgxuedao, limb_hurt;
        
        level = (int)me->query_skill("dagou-bang", 1);

        ob = me->select_opponent();
        
        if (random(me->query_skill("stick")) > 100 
        && me->query_skill("force") > 90
        && me->query("neili") > 100 ) {
//        	me->add("neili", -30);
        	return ([
        	"action": "$N�������һ����â������$wʹ��"+HIG"�������޹���"+NOR"������ǵذ㹥��$n������֮���������ѧ�еľ���",
        	"force" : 480,
        	"dodge" : 30,
        	"damage": 150,
        	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        	"damage_type": "����"]);
        }

        if( objectp(victim = me->query_temp("zhuan")) )
        {
        	if( ob == victim )
        	{
        		if(random(5) < 1)
        		{
        			if(random(me->query("combat_exp")) * me->query_skill("stick") > 
        			random(ob->query("combat_exp"))* ob->query_skill("dodge")/2)
        			{
        		
        				msghit = ({
        					"\n$nһ�������������˵���",
        					"\nֻ�������۵ش���$n��"
        				});
        				msgxuedao = ({
        					"ǿ��Ѩ",
        					"�縮Ѩ",
        					"��׵Ѩ",
        					"��̨Ѩ",
        					"����Ѩ"
        				});
        				msghit += msgxuedao;
        				ob->receive_damage("qi", level/3, "���˹�������");
        				ob->start_busy(1 + random(3));
        				msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
        				message_vision(msg, me, victim);
        			}
        			else
        			{
        				msghit = ({
        					"\n$n�����������Լ����񣬾���$P��"+limb_hurt+"�ϴ���һ�£�����δ�����Ѩ����ȴҲ����ʹ���á�\n",
        					"\n$n������һ�£�����Σ���м���Ѩ������δ�����ˡ�\n"
        				});
        				ob->receive_damage("qi", level, "���˹�������");
        				msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
        				message_vision(msg, me, victim);
        			}
        			me->delete_temp("zhuan");
        		}
        		else
        		{ 
        			ob->receive_damage("jing", level/3, "����͸֧��������");
        			ob->receive_damage("jingli", level/3, "����͸֧��������");
        		}
        	}
        }

        return action[random(sizeof(action))];
}

int     practice_skill(object me)
{
                object weapon;

                if (!objectp(weapon     = me->query_temp("weapon"))
                //|| (string)weapon->query("skill_type") !=     "staff")
                || (string)weapon->query("skill_type") != "stick")
                                return notify_fail("��ʹ�õ��������ԡ�\n");
                if ((int)me->query("jingli") < 50)
                                return notify_fail("��ľ����������򹷰�����\n");
                me->receive_damage("jingli", 40);
                return 1;
}

mixed hit_ob(object me, object victim, int damage)
{
        string msg;
        int ap, dp, zhencost;
        string result;
        object weapon;

        if (!objectp(weapon     = me->query_temp("weapon")))
                return 0;
        
        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("stick");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("dodge");
        ap = (ap + random(ap*2))/2;
        zhencost = sqrt(weapon->weight()/10)+10;
        
        if(victim->query_temp("feng")) {
//        msg = HIG"$N����򹷰����еġ��⡹�־���$n��ȥ��\n"NOR;
//        message_vision(msg,me,victim);

        if ( random(ap+dp) > ap ) {
                result = HIG "ֻ����ડ���һ����$n�ֱ��ϱ����˴���һ�£���æ���֣��Ѹ��������顣\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage")*2);
                victim->start_busy(1+random(2));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = HIG "ͻȻ����������������������޷���"+(string)weapon->query("name")+HIG"������$n��\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage")*3);
                victim->start_busy(1+random(3));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = HIG "$N�͵صݳ�һ�У���һ��Ѹ�����ף�ֱȡ$nü�ģ�$p��������һ�������˳����ߣ�\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage")*4);
                victim->start_busy(1+random(4));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else
        {
                result = weapon->name()+HIG"�϶�������֮�侹��ת��$n����ĵ�һ������$p���ϳ���һ�¡���\n" NOR;
                message_vision(result,me,victim);
//                message_vision((string)weapon->query("weapon_prop/damage") + "\n",me,victim);
                victim->add("qi", -weapon->query("weapon_prop/damage"));
                victim->start_busy(1+random(2));
                me->add("neili", -zhencost);
                me->add("jingli", -zhencost);
                damage = 0;
        
                return ([ "result" : result, "damage" : damage ]);
        }
     }
}

string perform_action_file(string action)
{
                return __DIR__"dagou-bang/"     + action;
}
