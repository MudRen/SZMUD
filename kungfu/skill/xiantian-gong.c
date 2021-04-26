// Code of ShenZhou
/// kungfu/skill/xiantian-gong.c ���칦
// sdong, 7/25/98

#include <combat.h>
#include <ansi.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int lvl = (int)me->query_skill("xiantian-gong", 1);
			  mapping skl;
		  string *sname;
		  int i, k=0;
	int t = 1, j;
	for (j = 1; j < lvl / 10; j++) t *= 2;
			  skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("this_skill") > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 && me->query_skill("taiji-shengong") < 80 )
		  return notify_fail("�����ڲ�ͬ���������ײ����������������书��\n");
		  }


	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ��������������������������������\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("�������������������ϣ���Υ��������徻֮�⣬"
			+RANK_D->query_respect(me)+"���޴˹������������\n");

	if ((int)me->query_skill("force", 1) < 10
	  || (int)me->query_skill("force", 1)/2 < lvl/3 )
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if (lvl > 10 && (int)me->query("shen") < t * 100
		  && me->query_skill("taoism", 1) < 100)
		return notify_fail("�����������̫���ˡ�\n");

	return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("xiantian-gong", 1) < 150 )
                return notify_fail("������칦��Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ���칦������֣��������ķ��ɡ�\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰ���칦��\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰ���칦��\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰ���칦��\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "����͸֧��������");
		  me->receive_damage("qi", 60, "����͸֧��������");
		  return 1;
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	object weapon1 = me->query_temp("weapon");
	object weapon2 = victim->query_temp("weapon");
	int ap, dp;
	string result;

	if ( (int)victim->query_skill("xiantian-gong", 1) < 50 ) return damage;

	dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
	if (objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" ) {
		if ( victim->query_skill_mapped("parry") != "quanzhen-jian" )
			return damage;
		dp /= 3;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/2;
	} else if (!objectp(weapon2) ) {
		if ( victim->query_skill_prepared("strike") != "sanhua-juding" )
			return damage;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
	} else return damage;

	ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);
	if (objectp(weapon1))
		ap += COMBAT_D->skill_power(me, weapon1->query("skill_type"), SKILL_USAGE_ATTACK);
	else
		ap *= 2;

	ap /= 100;
	dp /= 100;

	if ( random(ap+dp) > ap ) {
		if ( weapon2 && objectp(weapon2) ) {
			if (damage + damage_bonus > 0)
			{
				me->receive_damage("qi", (damage + damage_bonus)/2, victim);
				result = HIG"ֻ��$n���н������һճһ����$N������ͨͨ���ڿմ���$P�������ͣ�ʧȥƽ�⣬���˸��ӡ�\n"NOR;
				result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
				me->start_busy( 2+random(2) );
			}
			else
				result = "ֻ��$n���н������һճһ����$N������������Ϊ���Ρ�\n";
		}
		else if( victim->query_temp("sanhua") || victim->is_busy() )
		{
			if( !weapon1 )
			{
				result = HIM"ֻ��$n���커������Ȼ��Ȼ��������$N����������������$P�Լ���\n"NOR;
				if (damage + damage_bonus > 0)
					me->receive_damage("qi", (damage + damage_bonus)/2, victim);
				result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			}
			else
			{
				result = HIM"ֻ��$n���커������Ȼ��Ȼ��������$N����������һ�ߡ�\n"NOR;
			}
		}
		else return damage;

		damage_bonus = -5000; // just a number negative enough
		return ([ "result" : result, "damage" : damage_bonus ]);

	} else if( random(ap+dp+dp+dp) > ap ) {

		if (objectp(weapon2)) {
			result = "$n���н�����б����$N�������������˴�롣\n";
			damage_bonus = 0;
		}
		else if( victim->query_temp("sanhua") || victim->is_busy())
		{
			result = MAG"ֻ��$n���커������Ȼ��Ȼ��������$N�Ĺ�����Ϊ���Ρ�\n"NOR;
			damage_bonus = -5000;
		}
		else return damage;

		return ([ "result" : result, "damage" : damage_bonus ]);
	} else if( random(ap+dp+dp+dp+dp) > ap ) {

		 if( victim->query_temp("sanhua") || victim->is_busy() )
		{
			result = MAG"ֻ��$n���커������Ȼ��Ȼ�������ֿ�$N�Ĺ�����\n"NOR;
			damage_bonus = 0;
		}
		else return damage;

		return ([ "result" : result, "damage" : damage_bonus ]);
	} else
		return damage;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"���ڵ��£�ͷ��һ���������������ϣ���������һ�㡣",
		"start_self"	: YEL"����ϥ���£��������ˣ������������Ѩ��ת��\n"NOR,
		"unfinish_other": "����һ�ᣬ"+ me->name() +"�³�һ����Ѫ��\n",
	]);
}
