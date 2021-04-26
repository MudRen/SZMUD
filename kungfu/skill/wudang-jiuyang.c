// Code of ShenZhou
// taiji-shengong.c ̫����

#include <combat.h>
#include <ansi.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("taiji-shengong", 1);
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

        if ( k >=2 )
        return notify_fail
("�����ڲ�ͬ���������ײ����������������书��\n");
        }



//      if ( me->query("gender") == "����" )
//              return notify_fail("̫��������������������������������ϣ��Թ����޸�����֮������޵ã�\n");

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ����������������������̫���񹦡�\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("̫���񹦽����������ϣ���Υ��������徻֮�⣬"
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
        return notify_fail("̫����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"taiji-shengong/" + func;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");
        int ap, dp, s_damage;
	mapping prepare;
        string attack_skill, result;

        if( (int)victim->query_skill("taiji-shengong", 1) < 50 ) return damage;

        dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
        if( objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" )
	{
		if( victim->query_skill_mapped("parry") != "taiji-jian" ) return damage;
		dp /= 3;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        }
	else if( !objectp(weapon2) && victim->query_skill_mapped("parry") == "taiji-quan" )
	{
		if( victim->query_skill_prepared("cuff") != "taiji-quan" ) return damage;
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        }
	else return damage;

        ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);

        prepare = me->query_skill_prepare();
        if( !prepare ) prepare = ([]);

        if( objectp(weapon1) ) attack_skill = weapon1->query("skill_type");
	else switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
	}

	ap += COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        ap /= 100;
        dp /= 100;

	if( wizardp(victim) ) tell_object(victim, sprintf("ap: %d, dp: %d\n", ap, dp));
        if( random(ap+dp) > ap )
	{
		if( objectp(weapon2) )
			result = "ֻ��$nʹ��������ǧ��֮�ɾ�������б����$N�������������ڿմ���\n";
		else
		{
			result = "ֻ��$nʹ��������ǧ��֮�ɾ�������һת��һ�ƣ�$N��������������$P�Լ���\n";
			s_damage = damage + damage_bonus;
			if( victim->query_temp("taiji") )
				s_damage += me->query_temp("apply/damage");
                        if( s_damage > 0 )
			{
				me->receive_damage("qi", s_damage, victim);
				me->receive_wound("qi", random(s_damage/2), victim);
				result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			}
                }
                damage_bonus = -10000; // just a number negative enough
                return ([ "result" : result, "damage" : damage_bonus ]);
        }
	else if( random(ap+dp+dp) > ap )
	{
                if( objectp(weapon2) )
		{
                        result = "$nʹ��������ǧ��֮�ɾ�����$N������жȥ��롣\n";
                        damage_bonus = 0;
                }
		else
		{
                        result = "$nʹ��������ǧ��֮�ɾ�����$N����������жȥ��\n";
                        damage_bonus = -10000; // just a number negative enough
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        }
	else
	if( random(ap+dp+dp+dp) > ap )
	{
                if( !objectp(weapon2) )
		{
                        result = "$nʹ��������ǧ��֮�ɾ�����$N������жȥ��롣\n";
                        damage_bonus = 0;
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        }
	else return damage;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"����һ�Դ����붨��ͷ������"HIW"�뵰���"NOR"������������",
		"start_self"	: HIW"��Ǳ��������������Ѩ����ת���ˣ�������Ϣ��\n"NOR,
		"start_other"	: HIW"ֻ��"+ me->name() +"��Ŀ���£�Ƭ��֮ʱ��ͷ��ð��˿˿������\n"NOR,
		"finish_self"	: HIY"��ֻ����Ϣ��ת˳�������������ϵ��վ��������\n"NOR,
		"finish_other"	: me->name() +"�Ұ׵���ɫ�������󣬻��������ۣ�վ��������\n",
		"unfinish_self" : "�㽥�������������󾢲��̣����ò��������ڰ��˵���Ϣ�ջء�\n",
		"unfinish_other": me->query("eff_qi") < me->query("max_qi")*3/4 ?
				  "�͵���"+ me->name() +"��һ�ţ����������Ѫ��\n" :
				  "�͵���"+ me->name() +"��һ�ţ��³����Ϻ���Ѫ��\n",
	]);
}

		