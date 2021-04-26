// Code of ShenZhou
// luoying-shenfa ��Ӣ��

#include <combat.h>
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n��ͷһ�ͣ�˫�����䣬������ǰ���Ƽ�����$N������ȥ������һ�С�����������$N��֮�£���������ͳͳ����$n��󣬾�����ա�\n",
        "dodge"  : 10,
        "skill_name" : "������"
]),
([      "action" : "$n���μ�����ʹ��һ�С������ڿա���������ͬΪ�������������Ʈ��һ�����࣬�ܹ�$N������\n",
        "dodge"  : 20,
        "skill_name" : "�����ڿ�"
]),
([      "action" : "$n����һ�ݣ�Ծ�ڰ�գ��ո����أ�һ�С��������㡱���ڿ�����������һ������������Ϣ������$N���\n",
        "dodge"  : 30,
        "skill_name" : "��������"
]),
([      "action" : "$n�ۼ����й�����ίʵ���޿ɱܣ���Ȼһ�С���Ͽ�ƶϡ������һ�������ţ�ȫ����ϥ�����ϣ�ƽƽ�۶ϣ�$N������ʱʧ��׼ͷ��ȫ�����ڿմ���\n",
        "dodge"  : 40,
        "skill_name" : "��Ͽ�ƶ�"
]),
([      "action" : "$n����������ʹ��һ�С�����������˫��չ���������������裬��̬Ʈ�ݣ�����$N������\n",
        "dodge"  : 50,
        "skill_name" : "��������"
]),
([      "action" : "$n��һ�䣬һʽ��������衱������$N���ƣ��������󣬵������ң�$N�俴�ƴ�ռ�Ϸ磬ȴ��һ���ܹ����С�\n",
        "dodge"  : 60,
        "skill_name" : "�������"
]),
([      "action" : "$nһ����Х�����ΰεض�������һ�С��������������ڿ���һ������ת�ۣ���ҡֱ�ϣ�Ѹ���������������������$N������\n",
        "dodge"  : 70,
        "skill_name" : "��������"
]),
([      "action" : "$n����������¼��Ⱥ�����Է�λ��һʽ����ȥ���⡱����������֮��ǰ�������ں�$N��æ���ң����ֵ����������ܣ������ỹ�ַ����ˡ�\n",
        "dodge"  : 80,
        "skill_name" : "��ȥ����"
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("luoying-shenfa");

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
                return notify_fail("��ľ���̫���ˣ���������Ӣ����\n");
        me->receive_damage("jingli", 30);
        return 1;
}

int is_special()
{
        return 1;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        mapping prepare,action;
	string msg,result,attack_skill;
	object w,w2;
	int ap, dp;
	w = victim->query_temp("weapon");
	w2 = me->query_temp("weapon");

	if( !victim->is_busy() ) return damage;

	if( objectp(w2) )	attack_skill = w2->query("skill_type");
	else {
	prepare = me->query_skill_prepare();
	if (!prepare) prepare = ([]);
	else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
	else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
	else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
		}
	attack_skill = me->query_skill_mapped(attack_skill);

	if( !victim->query_temp("wuzhuan") ) return damage;
	
	if( !living(victim) ) return damage;
	if( victim->query_temp("exercise/playing")) return damage;

	ap = me->query("combat_exp")/1000;
	ap += me->query("jiali")*2;
	dp = victim->query("combat_exp")/1000;
	dp += victim->query_skill("bitao-xuangong", 1);
	dp += victim->query_skill("qimen-dunjia", 1);
	dp = (dp + random(dp*3/2)) / 2;
	action = me->query("actions");

	if( ap > dp ) return damage;


	/* //remove special parry  // maco
	if( wizardp(victim) )
			tell_object(victim,"\ndp��"+dp+" ap��"+ap+" "+to_chinese(attack_skill)+"��"+action["skill_name"]+"��"+action["weapon"]+"��\n");

	if( !victim->is_busy() ) {
	if(victim->query_skill_mapped("parry") !="tanzhi-shentong") return damage;
	if((int)victim->query_skill("tanzhi-shentong", 1) < 120) return damage;
	if((victim->query_temp("th_jianzhi") > 1 && objectp(w) && w->query("skill_type") == "sword") || !objectp(w) ) {
		if( victim->query_skill_prepared("finger") != "tanzhi-shentong")
		return damage;
		else if( victim->query_temp("wuzhuan_hit") < 0) return damage;
		else if(attack_skill=="tanzhi-shentong")
		result = HIG"$n��ָһ�����͵�һ�����죬һ��ϸϸ�ľ��������ȥ�����ɡ���ָ��ͨ��ָ����������ʱ��������Ρ�\n" NOR;
//		else if( objectp(w2) &&  stringp(action["skill_name"]) )
//		result = HIG"$n��ָһ�����͵�һ�����죬һ��ϸϸ�ľ��������ȥ����ʱ��"+w2->name()+HIG"�������ھ���������������������"+to_chinese(attack_skill)+"�ġ�"+action["skill_name"]+"����\n" NOR;
		else if( objectp(w2) )
		result = HIG"$n��ָһ�����͵�һ�����죬һ��ϸϸ�ľ��������ȥ����ʱ��"+w2->name()+HIG"�������ھ���������������������"+to_chinese(attack_skill)+"��\n" NOR;
		else result = HIG"$n��ָһ�����͵�һ�����죬һ��ϸϸ�ľ��������ȥ���⡸��ָ��ͨ����$N�ġ�"+to_chinese(attack_skill)+"�����˸�����൱��˭Ҳû����˭��\n" NOR;
                                victim->add("neili",- (30+me->query("jiali")/2));
                                victim->add_temp("wuzhuan_hit",-1);

                                damage = 0;
                                return ([ "result" : result, "damage" : damage ]);

			}

	else return damage;
	}
	else {
	*/

        victim->start_busy(1);
        victim->interrupt_me();
	msg = HIB "$Nһ����Х�����²������Ų�������ǰ�������������з���";
        msg += "���ȶ�Ӱ��˲��ֻ����ʮ����Ӱ������������߲�����\n"NOR;
        
	message_vision(msg, victim);
	return damage;
//	}
}

