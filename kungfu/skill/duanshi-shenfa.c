// Code of ShenZhou
// duanshi-shenfa.c
// AceP

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : 
"$n˫��һ�죬�����أ�һʽ�����ذδС�ȫ�����Ծ���գ�����Ӳ�������ࡣ\n",
        "dodge"  : 10
]),
([      "action" :
"$n����һת��˫��һ�٣�һʽ������鳲���͵�����һ�ܣ���һֻ���������ƶˡ�\n",
        "dodge"  : 20
]),
([      "action" :
"$n����һ���������͵�������棬һʽ������������˳�Ʒ���Ծ��$N��ͷ����\n",
        "dodge"  : 30
]),
([      "action" :
"$n����Ծ��һʽ���������С��ڰ������һ�����������ֱ���ַ�����ߡ�\n",
        "dodge"  : 40
]),
([      "action" :
"$nʹ�����˷��ȥ����ȫ��������ת�������죬ɲʱ�����գ�����������С�\n",
        "dodge"  : 50
]),
([      "action" :
"$nʹ�����绯������˫��һ�죬�������ᣬ��һֻ��ɽ��𣚣�������ɡ�\n",
        "dodge"  : 60
]),
([      "action" :
"$n��Ȼ��ɫһ�䣬˫Ŀһ�գ�һʽ������ֱ�ϡ�����һͦ����һͦ��һƬ��ëƮ���ա�\n",
        "dodge"  : 70
]),
([      "action" :
"$n˫���Ȼ�ӿ죬�����͵ĺ�����һʽ��������졹��һ������ƽƽ�Ĵ�����С�\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("duanshi-shenfa");

        
        if (level < 80 )
                zhaoshu--;
   
        if (level < 70 )
                zhaoshu--;


        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*

        object me, ob;
        mapping action;

        me = this_player();
        action = query_action(me, ob);
        return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ���������������\n");
        me->receive_damage("jingli", 30, "����͸֧��������");
        return 1;
}

int is_special()
{
	return 1;
}

mixed hit_by(object me, object victim, int damage)
{
	int ap, dp, diff1, diff2;
	string result;
	object weapon;

	if ((me->query_skill_mapped("force")=="kurong-changong"
		&& me->query("family/family_name")=="����μ�")
		|| victim->query_skill("yiyang-zhi", 1) < 120
		|| victim->query_skill_mapped("force")!="kurong-changong"
		|| victim->query_skill_mapped("parry")!="yiyang-zhi"
		|| !living(victim))
		return damage;
/*
	ap = me->query("combat_exp")/100 + me->query_skill("parry")*100;
	dp = victim->query("combat_exp")/100 + victim->query_skill("finger")*120;

	if (me->query("family/family_name")=="����ɽ"
		&& me->query_skill_mapped("force")=="hamagong")
		ap = ap/2;

	if (random(dp)>ap/2 ) {
		if (weapon=me->query_temp("weapon")) {
			if (victim->query_skill("yiyang-zhi",1)>180
				&& victim->query("neili")>30) {
				result = HIY "$n��׼��"+weapon->query("name")+"����·������һ��ָ�ھ������һָ���䵴�˿�ȥ��\n" NOR;
				victim->add("neili",-30);
				damage = 0;
				return ([ "result" : result, "damage" : damage ]);
			}
		}
		else {
			damage = 0;
			result = HIY "$n������$N��������·����æ������ָӭ����\n" NOR;
			if (random(2)==1) {
				damage=damage/2;
				me->receive_damage("qi", damage+random(damage), victim);
				if (random(3)==2) {
					me->receive_wound("qi", (damage+random(damage))/2, victim);
				}
				result = result + HIR "$N���в�������$nһָ���У��ھ��񵴣���ǰһ�ڣ�������������˼�����\n" NOR;
			}
			else 
				result = result + HIY "$Nһ��$n���Ʋ����æ���У����Ա�һ�����㿪��$n�ķ�����\n" NOR;
			return ([ "result" : result, "damage" : damage ]);
        }
	}
*/
	if (damage >= (int)victim->query("qi")
		&& victim->query_temp("kurong")
		&& damage >= (victim->query("max_qi")/3*2)) {
		if (damage < (int)victim->query_temp("kurong")) {
			victim->add_temp("kurong", -damage);
			result = HIW "$n��$N��һ���ƴ����������˿����ķ����壬����������һ�����䰲Ȼ������������ȴ������ģ�\n" NOR;
			damage = 0;
			return damage;
		}
		else {
			victim->delete_temp("kurong");
			result = HIR "$n����һ���ػ�������������ȥ�������ķ�������Ӧ��ס��������ס�ڸ����ﲻ�����ˡ�\n" NOR;
			damage = damage/4;
		}
		return ([ "result" : result, "damage" : damage ]);
	}

	return damage;
}	
