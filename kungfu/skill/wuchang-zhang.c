// Code of ShenZhou
// wuchang-zhang.c �޳��ȷ�

inherit SKILL;

mapping *action = ({
([	"action":"$N΢һ����һ�С�ӹ�����š���$w���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
	"force" : 100,
        "dodge" : -10,
        "parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "ӹ������",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�����Ƿǡ���������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
	"force" : 110,
        "dodge" : -10,
        "parry" : 10,
	"damage": 15,
	"lvl" : 7,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "����Ƿ�",
	"damage_type":"����"
]),
([	"action":"$Nһ�С����񲻰���������$wƹƹ���ҵ��������ã���$n�����ұܣ��Ǳ�����",
	"force" : 120,
        "dodge" : -5,
        "parry" : 5,
	"damage": 20,
	"lvl" : 14,
	"skill_name" : "���񲻰�",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�������ɫ��������$w�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$l",
	"force" : 130,
        "dodge" : -5,
        "parry" : 5,
	"damage": 20,
	"lvl" : 20,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "������ɫ",
	"damage_type":"����"
]),
([	"action":"$N��$w��ס�Լ������ţ�һ��ָ��$n��һ�С��ľ��������������к��ų���$n",
	"force" : 140,
        "dodge" : -15,
        "parry" : 15,
	"damage": 30,
	"lvl" : 25,
	"skill_name" : "�ľ�����",
	"damage_type":"����"
]),
([	"action":"$Nһ�С���ʬ���⡹��ȫ��ֱ�������ų���ǰ�У��䲻������������$n��ȥ",
	"force" : 150,
        "dodge" : 5,
        "parry" : -15,
	"damage": 30,
	"lvl" : 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "��ʬ����",
	"damage_type":"����"
]),
([	"action":"$N�����ɫ��һ�С���������������$n˵���䣬һ����$n�Ŵ�����ͱ�˹�ȥ",
	"force" : 300,
        "dodge" : -5,
        "parry" : 20,
	"damage": 40,
	"lvl" : 35,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$Nһ�С��������ġ������⽫$wˤ����ϣ���$n������һ�Ź��𣬻���$n��$l",
	"force" : 350,
        "dodge" : -5,
        "parry" : 25,
	"damage": 40,
	"lvl" : 40,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N����װ����һ�С���;û·����һ������������$w��������������$n���ɲ�",
	"force" : 400,
        "dodge" : -5,
        "parry" : 25,
	"damage": 50,
	"lvl" : 45,
	"skill_name" : "��;û·",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�����ľ�������������Ų��ƣ�$wȴֱ�ɰ�գ���ƫ���е�����$n��$l",
	"force" : 450,
        "dodge" : -5,
        "parry" : 25,
	"damage": 50,
	"lvl" : 50,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "����ľ��",
	"damage_type":"����"
]),
([	"action":"$N�߾�$w��һ�С��˹���;������������Ȱ�Ʈ������׼$n�������һ�ȴ���",
	"force" : 500,
        "dodge" : -5,
        "parry" : 25,
	"damage": 60,
	"lvl" : 55,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "�˹���;",
	"damage_type":"����"
]),
([	"action":"$Nһ�С���������������ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
	"force" : 550,
        "dodge" : -5,
        "parry" : 25,
	"damage": 60,
	"lvl" : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "�������",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("wuchang-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query_str() < 20)
                return notify_fail("��ı����������޳��ȷ���\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ����������޳��ȷ���\n");

        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("�������ǧҶ����Ϊ��������\n");

	me->receive_damage("jingli", 20);
        if(me->query_skill("wuchang-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("wuchang-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
	return 1;
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zui-gun", 1) >= 200
        &&  (int)me->query_skill("wuchang-zhang", 1) >= 200
        &&  !me->query("sl_gifts/zg") ) {
                me->add("dex", 1);
                   log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)��������޳��ȵõ� һ ������\n",  
                           ctime(time())[0..15], me->query("family/family_name"), me->name(), getuid(me)));  
           me->add("AddGift/sl/dex",1);  
                me->set("sl_gifts/zg", 1);
                write("\n���������޳���ѧ�����ɣ�������������\n");
        }
}
