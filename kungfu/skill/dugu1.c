// Code of ShenZhou
//dugu-jiujian.c ���¾Ž�
//by qfy 
//June 17, 96

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
	"force" : 100,
	"dodge" : 15,
	"damage" : 25,
	"lvl" : 0,
	"damage_type" : "����"
]),
([      "action":"$n��׼$Nһ�л�ɽ�������з����ǡ������ƣ�׼�����з�����ȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ��",
        "force" : 110,
        "dodge" : 10,
        "damage" : 30,
        "lvl" : 1,
        "damage_type" : "����"
]),
([      "action":"ֻ��$N����������һ�����ǡ�������ɽ��������$w����ն�䣬ֱ����$n��$l",
	"force" : 130,
	"dodge" : 15,
	"damage" : 30,
	"lvl" : 5,
	"damage_type" : "����"
]),
([      "action":"$N����Ծ�𣬳������硸�����ա��������Ƚ��б��ϣ���תΪ�����������������⻮��$n��$l",
	"force" : 150,
	"dodge" : 20,
	"damage" : 35,
	"lvl" : 7,
	"damage_type" : "����"
]),
([      "action":"$NͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ�$w����$nһ�ʣ���ͼͻ��$n�Ĺ���",
        "force" : 160,
        "dodge" : 15,
        "damage" : 35,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action":"����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n��$l",
	"force" : 165,
	"dodge" : 10,
	"damage" : 40,
	"lvl" : 12,
	"damage_type" : "����"
]),
([      "action":"$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ",
	"force" : 170,
	"dodge" : 15,
	"damage" : 40,
	"lvl" : 15,
	"damage_type" : "����"
]),
([      "action":"$n����$N��$l��$N���˷�����ʹ����ɽ���С�������롹��ɭɭ������������",
	"force" : 175,
	"dodge" : 15,
	"damage" : 42,
	"lvl" : 18,
	"damage_type" : "����"
]),	
([      "action":"$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������;��ͻȻת�򣬴��$n����֮��",
        "force" : 180,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action":"$N����һ�£���������һ���׺磬��$nֱ�̹�ȥ����һ�ж�����ΰ��������ɽ�����еġ�ǧ���������������ǻ�ɽ�����ġ��ޱ���ľ��",
        "force" : 185,
        "dodge" : 5,
        "damage" : 63,
        "lvl" : 23,
        "damage_type" : "����"
]),
([      "action":"$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ�����",
        "force" : 190,
        "dodge" : 15,
        "damage" : 65,
        "lvl" : 26,
        "damage_type" : "����"
]),
([      "action":"$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼",
        "force" : 195,
        "dodge" : 10,
        "damage" : 68,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action":"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ",
	"force" : 200,
        "dodge" : 10,
        "damage" : 70,
        "lvl" : 33,
        "damage_type" : "����"
]),
([      "action":"ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������̩ɽʮ���̡�Ϊһ������$n",
	"force" : 205,
        "dodge" : 10,
        "damage" : 72,
        "lvl" : 36,
        "damage_type" : "����"
]),
([      "action":"$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ����",
	"force" : 212,
        "dodge" : 10,
        "damage" : 75,
        "lvl" : 39,
        "damage_type" : "����"
]),
([      "action":"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ���ƻ���$n",
        "force" : 220,
        "dodge" : 10,
        "damage" : 77,
        "lvl" : 42,
        "damage_type" : "����"
]),
([      "action":"$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n",
	"force" : 230,
        "dodge" : 15,
        "damage" : 80,
        "lvl" : 47,
        "damage_type" : "����"
]),
([      "action":"$N�������أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������Ħ���������¶����",
	"force" : 240,
        "dodge" : 5,
        "damage" : 82,
        "lvl" : 52,
	"damage_type" : "����"
]),
([      "action":"$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ�����ز���$n",
	"force" : 250,
        "dodge" : 10,
        "damage" : 85,
	"lvl" : 58,
	"damage_type" : "����"
]),
([      "action":"$N���ֺὣ����$n��$l���������������е�һ��������ȴ�����$n���Կ��彣������",
	"force" : 270,
	"dodge" : 15,
	"damage" : 87,
	"lvl" : 64,
	"damage_type" : "����"
]),
([      "action":"$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô����",
	"force" : 290,
	"dodge" : 10,
	"damage" : 89,
	"lvl" : 72,
	"damage_type" : "����"
]),
([      "action":"$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ�������$n���ò���",
	"force" : 320,
	"dodge" : 0,
	"damage" : 91,
	"lvl" : 78,
	"damage_type" : "����"
]),
([      "action":"$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ",
	"force" : 350,
	"dodge" : 15,
	"damage" : 93,
	"lvl" : 85,
	"damage_type" : "����"
]),
([      "action":"$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l",
	"force" : 370,
	"dodge" : 5,
	"damage" : 96,
	"lvl" : 90, 
	"damage_type" : "����"
]),
([      "action":"$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻ�",
	"force" : 420,
	"dodge" : 10,
	"damage" : 100,
	"lvl" : 95,
        "damage_type" : "����"
]),
([      "action":"$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼��",
	"force" : 470,
	"dodge" : 5,
	"damage" : 110,
	"lvl" : 98,
	"damage_type" : "����"
]),
([      "action":"$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ�",
	"force" : 500,
	"dodge" : 10,
	"damage" : 120,
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
	if ((int)me->query_skill("taiji-jian", 1) > 0 || (int)me->query_skill("damo-jian", 1) > 0
	|| (int)me->query_skill("fumo-jian", 1) > 0 || (int)me->query_skill("huashan-jianfa", 1) > 0
	|| (int)me->query_skill("emei-jianfa", 1) > 0 )
		return notify_fail("�������������������������޷������¾Ž������С�����ּ��\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("dugu-jiujian",1);
	
	if ( me->query_str() >= 30 && me->query_int() >= 36 
	&& random(me->query_skill("dugu-jiujian",1)) > 80 
	&& me->query_skill("force") > 150 && me->query("neili") > 400 
	&& (string)weapon->query("id") == "xuantie jian" ) {
	   me->add("neili", -100);
	   return ([
	   "action" : "$N��ɫ�����ϣ��������������ؽ���ͻȻԾ������һ��Ԧ����Ϊһ��������$n��̶�ȥ",
	   "damage" : 500,
	   "damage_type" : "����"
	   ]);
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
