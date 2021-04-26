// Code of ShenZhou
//dugu-jiujian.c ���¾Ž�
//by qfy 
//June 17, 96

#include <ansi.h>
#include <combat.h>
void interrupt_me(object who);

inherit SKILL;

string *dodge_msg = ({
	"$nͦ��һ�����ǡ����Ƴ�ᶡ��ش�$N��$l����ͼ��$N�Ĺ��ƻ��⡣\n",
	"$n�������ܣ��ٽ������ʹ�������両�ࡹ����$N��$l���뵲��$N���С�\n",
	"ֻ��$n���˷���������Ʈ�磬�����һʽ�������������������޶�����׽����ָ��$N��$l��\n",
	"$n�˽���磬��������з���$N��$l�����Ա�$N���أ��������ǡ���ħ�����ġ�����ʽ����\n",
	"$n�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$N�͹����ػӳ���λ�����̩ɽ���������������\n",
	"ȴ��$n̤ǰһ������ʽбָ$N��$l����Ҫʹ$N������ˡ�\n",
	"$n����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ������������ع�$N��\n",
	"$n�ٽ���ӣ�Ѹ���ޱȵص���$N��$l��ȴ���˿�������������ʲô��ʽ��\n",
});

mapping *action = ({
([      "action":"$Nͦ���ش�$n��$l���������ǻ�ɽ�����ġ����Ƴ�ᶡ�����ɽ�����ġ��������ڡ����Ƶ�$n���أ�ֹͣ��$N�Ĺ���",
	"force" : 180,
	"dodge" : 25,
	"damage" : 80,
	"lvl" : 0,
	"damage_type" : "����"
]),
([      "action":"$n��׼$Nһ�л�ɽ�������з����ǡ������ƣ�׼�����з�����ȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ��",
        "force" : 180,
        "dodge" : 20,
        "damage" : 80,
        "lvl" : 1,
        "damage_type" : "����"
]),
([      "action":"ֻ��$N����������һ�����ǡ�������ɽ��������$w����ն�䣬ֱ����$n��$l",
	"force" : 185,
	"dodge" : 25,
	"damage" : 80,
	"lvl" : 5,
	"damage_type" : "����"
]),
([      "action":"$N����Ծ�𣬳������硸�����ա��������Ƚ��б��ϣ���תΪ�����������������⻮��$n��$l",
	"force" : 185,
	"dodge" : 25,
	"damage" : 85,
	"lvl" : 7,
	"damage_type" : "����"
]),
([      "action":"$NͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ�$w����$nһ�ʣ���ͼͻ��$n�Ĺ���",
        "force" : 185,
        "dodge" : 25,
        "damage" : 85,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action":"����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n��$l",
	"force" : 190,
	"dodge" : 20,
	"damage" : 85,
	"lvl" : 12,
	"damage_type" : "����"
]),
([      "action":"$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ",
	"force" : 190,
	"dodge" : 25,
	"damage" : 85,
	"lvl" : 15,
	"damage_type" : "����"
]),
([      "action":"$n����$N��$l��$N���˷�����ʹ����ɽ���С�������롹��ɭɭ������������",
	"force" : 195,
	"dodge" : 25,
	"damage" : 85,
	"lvl" : 18,
	"damage_type" : "����"
]),	
([      "action":"$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������;��ͻȻת�򣬴��$n����֮��",
        "force" : 200,
        "dodge" : 20,
        "damage" : 90,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action":"$N����һ�£���������һ���׺磬��$nֱ�̹�ȥ����һ�ж�����ΰ��������ɽ�����еġ�ǧ���������������ǻ�ɽ�����ġ��ޱ���ľ��",
        "force" : 200,
        "dodge" : 25,
        "damage" : 90,
        "lvl" : 23,
        "damage_type" : "����"
]),
([      "action":"$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ�����",
        "force" : 210,
        "dodge" : 25,
        "damage" : 90,
        "lvl" : 26,
        "damage_type" : "����"
]),
([      "action":"$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼",
        "force" : 215,
        "dodge" : 20,
        "damage" : 90,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action":"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ",
	"force" : 220,
        "dodge" : 25,
        "damage" : 95,
        "lvl" : 33,
        "damage_type" : "����"
]),
([      "action":"ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������̩ɽʮ���̡�Ϊһ������$n",
	"force" : 225,
        "dodge" : 25,
        "damage" : 95,
        "lvl" : 36,
        "damage_type" : "����"
]),
([      "action":"$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ����",
	"force" : 230,
        "dodge" : 20,
        "damage" : 95,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action":"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ���ƻ���$n",
        "force" : 235,
        "dodge" : 30,
        "damage" : 100,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action":"$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n",
	"force" : 240,
        "dodge" : 30,
        "damage" : 100,
        "lvl" : 47,
        "damage_type" : "����"
]),
([      "action":"$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ���������¶����",
	"force" : 250,
        "dodge" : 35,
        "damage" : 100,
        "lvl" : 52,
	"damage_type" : "����"
]),
([      "action":"$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ�����ز���$n",
	"force" : 260,
        "dodge" : 30,
        "damage" : 100,
	"lvl" : 58,
	"damage_type" : "����"
]),
([      "action":"$N���ֺὣ����$n��$l���������������е�һ��������ȴ�����$n���Կ��彣������",
	"force" : 270,
	"dodge" : 35,
	"damage" : 105,
	"lvl" : 64,
	"damage_type" : "����"
]),
([      "action":"$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô����",
	"force" : 290,
	"dodge" : 30,
	"damage" : 105,
	"lvl" : 72,
	"damage_type" : "����"
]),
([      "action":"$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ�������$n���ò���",
	"force" : 320,
	"dodge" : 30,
	"damage" : 105,
	"lvl" : 78,
	"damage_type" : "����"
]),
([      "action":"$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ",
	"force" : 350,
	"dodge" : 35,
	"damage" : 110,
	"lvl" : 85,
	"damage_type" : "����"
]),
([      "action":"$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l",
	"force" : 370,
	"dodge" : 30,
	"damage" : 110,
	"lvl" : 90, 
	"damage_type" : "����"
]),
([      "action":"$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻ�",
	"force" : 420,
	"dodge" : 30,
	"damage" : 115,
	"lvl" : 95,
        "damage_type" : "����"
]),
([      "action":"$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼��",
	"force" : 470,
	"dodge" : 35,
	"damage" : 120,
	"lvl" : 98,
	"damage_type" : "����"
]),
([      "action":"$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ�",
	"force" : 500,
	"dodge" : 35,
	"damage" : 130,
	"lvl" : 100,
	"damage_type" : "����"
]),
});	                                  

int valid_enable(string usage) 
{ 
	object weapon;

	if (this_player()->query("family/master_id") != "feng qingyang" 
	&& !wizardp(this_player()) )
		return notify_fail("��������������ô����˼�����������Ľ�����\n");
	
	if (this_player()->query_skill("dugu-jiujian", 1) >= 350)
		return usage == "sword" || usage == "parry" || usage == "dodge"
		|| usage == "finger" || usage == "strike" || usage == "blade"
		|| usage == "cuff" || usage == "claw" || usage == "hand" 
		|| usage == "stick" || usage == "staff" || usage == "club"
		|| usage == "hook" || usage == "pike" || usage == "halberd";

        if (objectp(weapon = this_player()->query_temp("weapon"))
        && (string)weapon->query("skill_type") == "sword")
		return usage == "sword" || usage == "parry" || usage == "dodge"; 
	else
		return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
        if ((string)me->query("family/master_id") != "feng qingyang" )
                return notify_fail("�㲻�����������ѧϰ���¾Ž���\n");
        if ((int)me->query_skill("sword", 1) < 50)
        	return notify_fail("��Ļ����������̫ǳ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if ( (int)me->query_skill("taiji-jian") > 0 || (int)me->query_skill("damo-jian") > 0
	|| (int)me->query_skill("fumo-jian") > 0 || (int)me->query_skill("huashan-jianfa") > 0 
	|| (int)me->query_skill("emei-jianfa") > 0 || (int)me->query_skill("yuxiao-jian") > 0
	|| (int)me->query_skill("mingwang-jian") > 0 || (int)me->query_skill("duanjia-jian") > 0
	|| (int)me->query_skill("huifeng-jian") > 0 || (int)me->query_skill("jinshe-jianfa") > 0
	|| (int)me->query_skill("tangshi-jian") > 0 || (int)me->query_skill("quanzhen-jianfa") > 0 )
		return notify_fail("�������������������������޷������¾Ž������С�����ּ��\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("dugu-jiujian",1);
	
	if( weapon ) {
	if ( me->query_str() >= 30 && me->query_int() >= 36 
	&& random(me->query_skill("dugu-jiujian",1)) > 80 
	&& me->query_skill("force") > 150 && me->query("neili") > 400 
	&& (string)weapon->query("id") == "xuantie jian" ) {
	   me->add("neili", -100);
	   return ([
	   "action" : "$N��ɫ�����ϣ��������������ؽ���ͻȻԾ������һ��Ԧ����Ϊһ��������$n��̶�ȥ",
	   "damage" : 200,
	   "damage_type" : "����"
	   ]);
	}
	}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ������������¾Ž���\n");
        me->receive_damage("jingli", 15, "����͸֧��������");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string perform_action_file(string action)
{
        return __DIR__"dugu-jiujian/" + action;
}

int is_special()
{
	return 1;
}

mixed hit_by(object me, object victim, int damage)
{
	int ap, dp, i, level;
	object weapon = me->query_temp("weapon");
	mapping prepare;
        string attack_skill, result;

        if ( (level = victim->query_skill("dugu-jiujian", 1)) < 100 || !living(victim) )
                return damage;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( victim->query_skill_mapped("parry") == "dugu-jiujian" )
		dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);

	ap = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
	prepare = me->query_skill_prepare();
        if( !prepare ) prepare = ([]);

	if( objectp(weapon) ) attack_skill = weapon->query("skill_type");
        else switch( sizeof(prepare) )
        {
                case 0: attack_skill = "unarmed"; break;
                case 1: attack_skill = (keys(prepare))[0]; break;
                case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
        }

        ap += COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

	ap /= 100;
        dp /= 200;

        if ( random(ap+dp) > ap ) {
                result = GRN "$nͻȻ�ٽ�һ�̣�����������£�ȴĪ�������ͻ����$N�Ĺ��ƣ����$N���ϣ�\n";
                result += "$nһת���ƣ�����ԴԴ��������$N�������ƣ�\n" NOR;
		victim->add("neili", -30);
		victim->add("jingli", -30);
                me->start_busy( level/50 );
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = GRN "$n�ٽ��������������ش���$N��������$N��������������һ������������\n" NOR;
		victim->add("neili", -20);
		victim->add("jingli", -20);
		me->start_busy( level/100 );
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = GRN "$n�ὣ�ش̣��������$N��������$N���ò��������أ�����һ�μ����˳�����\n" NOR;
		victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = GRN "$n�ۼ����޿ɱܣ�ֻ���ὣ�Ҵ�һͨ����Ȼ�������ϵؽ�$N�Ĺ�����ȥ��롣\n" NOR;
		victim->add("jingli", -10);
                damage /= 5;

                return ([ "result" : result, "damage" : damage ]);
        }
        else
                return damage;
}
