// Code of ShenZhou
// riyue-bian.c ���±޷�
// maco �޸�������code

#include <ansi.h>

int dead_msg(object me, object victim, object weapon, int damage);

inherit SKILL;
///*****************************************************************************

/*
ֻ��������������Ϻ��Ӷ�������಻���ߣ�ȥ���漱��ȴ�Ǿ��޾��磬����������������ֻ�������࣬����һ���������ؿڵ㵽���Ǻ�������һ����ֱ�ı��У��糤ì����˰������̶�����
��������һ����һ����ɽ�������ھ����ؿ�ײ�������ھ�ֻҪ�е�ʵ�ˣ���������߹Ƕ��ۣ��������顣
���о�ʽ��ÿһʽ�ж�������ʮ�б仯����ʮ��ɱ�֣�
����������ת������ԲȦ
�����������ɣ��ھ������ۺ��ޱȡ�
���������ɲ�����ʹ�ú����������裬���������Ҳ���
������ɫ�����鶯���ͣ�ֱ��һ˫�������ƣ�

����շ�ħȦ��

����������������������צ��ī�����ƣ��������ϣ��ִ������˵���
ֻ���á�������һ���ҽУ���̫�屳����������Ȧ����ֱˤ�������ۼ����ǲ����ˡ�
�ɽٵ��������ǵ������������ʤ����ա����Ѫ�����Ҳ���ܽ�����������ˡ���ħͷ�����������ա������ӷ𣡡���һ����ţ��ɶ򡢶��Ѷ�ɮ�����������ҷ�ȱ�������������ٿ�ط��𣬼��������Ͼ�����
��Խ��Խ���ľ���ֻ���������������������������Ʒ缤��֮�£����ƽ������۳ɽ�һ�㡣
������ɶ򼱹����У���Ҫ����Ȧ�ӣ�����������������ɵ�Ȧ������ͭǽ�������ƣ������γ�����������أ���Ȼ�޷�����
�������������������ִ�����Ϯ����
������ɮ�ĺ��������ն̡�����һ�̣��Ӷ�ʱ�ٺ�������������ʱ���鶯ȴҲ���˼��֡�������ʮ�У���ɮ�ĺ��������������߳ߡ�
Ѱ覵�϶���������ƣ�����Ҫ�˵���ɮ��ߡ�����ɮ�����ն̺������൱���ܣ�����������ɵ�Ȧ��������������������������˲�ס�������������Ǳ���Ȧ���˳�ȥ��
ֻ����������̰˳ߣ�������ˡ���շ�ħȦ����
��ɮ����һ������������ī��һ�㣬Χ��������Ȧ�ӡ�
�ѽ���Ȧѹ����С������Բ����Ȼ����ɮ����ȦѹС������Խǿ������ÿ��ǰһ�������ǰҪ�໨����������

������λ���ָ�ɮ������ʮ������������������ͨ��һɮ������¶��������϶�������ɮ�������Բ��㡣
��ɮ�ġ���շ�ħȦ��ȴ�����Է�����ħ�ľ���󷨡�����ֻ����Խ��Խ����
�����ȫȻ������ɮ�����ϳ��书�Ŀ���֮�£�
��ɮ�ġ���շ�ħȦ���ԡ���վ���Ϊ���ּ�壬���Ҫ������࣬�����࣬�������࣬�������ࡱ��������֮�֣�����֮�𣬾��������ջá�
ֻ����ɮ��Ϊ��ߣ�һ�����֣���ȥ���˿˵���ʤ����ͷ�����ѽ��Լ�������֮���⣬����֮��ȴ�޷���������⡰��շ�ħȦ���������������������¡�
��ɮ�жɶ���Ϊ��ߣ���������ȴ���������ࡱ�������ѡ��ɽٶ�ɮ���۶�ʤ����ͷһʢ��Ⱦ�ӱ��������������μ����ɶ�ı޷��Ǻ����������䲻�ɡ�
������ɮ�յ���ʱ�����Ƴ���ս���Ѳ�����ͻȻ�������ߺȣ��������޼���ת������Ӱ�ݺᣬ�����ƻá����޼����ӵб����ƣ�һһ��⣬

*****************************************************************************///

mapping *action = ({
([      "action": "$N����$w�ӳ���$w�Ƶ��漱��ȴ�Ǿ��޾��磬��$n$l���Ӷ���������Ѳ�����",
        "dodge":  -5,
        "damage": 60,
        "force" : 160,
        "lvl" : 30,
        "damage_type":  "����"
]),
([      "action": "$N����һ����$wֱ��������ײ��$n���ţ��鶯���ͣ�����һ��������צ��ī������",
        "dodge": -10,
        "damage":  95,
        "force" : 320,
        "lvl" : 60,
        "damage_type":  "����"
]),
([      "action": "$N$w������ת������ԲȦ���Ӱ������$nͷ�����£������������ɣ��ھ������ۺ��ޱ�",
        "dodge":  -15,
        "damage": 120,
        "force" : 480,
        "lvl" : 90,
        "damage_type":  "����"
]),
([      "action": "$N���˸վ���$w����������ֱ����ɽ����һ�㣬��������˷���ȥ����ʱ�ȵ�$n��������",
        "dodge":  -15,
        "damage": 140,
        "force" : 520,
        "lvl" : 120,
        "damage_type":  "����",
	"post_action" : (: dead_msg :)
]),
([      "action": "$N����һ����$w��$n�ؿڵ㵽������һ����ֱ�ı��У��糤ì����˰������̶�������������֮��",
        "dodge":  -15,
        "damage": 160,
        "force" : 400,
        "lvl" : 180,
        "damage_type":  "����",
	"post_action" : (: dead_msg :)
]),
([      "action": "$N�����ھ������߶����ڹ�ʩչ�������쾡�£�$w��Х��������$n���ŵ�ȥ������δ����$w����Ю��������$nһ������",
        "dodge":  -15,
        "damage": 140,
        "force" : 540,
        "lvl" : 240,
        "damage_type":  "����",
	"post_action" : (: dead_msg :)
]),
([      "action": "$N����$w�������裬���������Ҳ�����Ӱ�ݺᣬ�����ƻã�������о�ʽ��ÿһʽ�ж�������ʮ�б仯����ʮ��ɱ��",
        "dodge":  -15,
        "damage": 170,
        "force" : 600,
        "lvl" :  300,
        "damage_type":  "����",
	"post_action" : (: dead_msg :)
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        mapping fam;
        object weapon;

        fam = me->query("family"); 
        if( !mapp(fam) || fam["family_name"] != "������" )
                return notify_fail("�㲻���������ɣ�����ѧϰ����������±޷���\n");

        if ( fam["family_name"] == "������" && fam["generation"] > 36 )
                return notify_fail("���ʸ񲻹�������ѧϰ���±޷����ȵ����˱�����˵�ɡ�\n");

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("����������㣬û�а취�����±޷�������Щ���������ɡ�\n");

        if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
                return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("���������һ�����Ӳ������޷���\n");

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
        level   = (int) me->query_skill("shaolin-bian",1);
        for(i = sizeof(action); i > 0; i--)
        
        if (random(level) > 300 && random(me->query("neili")) > 1000 ){
        me->add("neili", -20);
        return ([
        "action":HIW"$N����������$w"NOR+HIW"�Ӷ�ʱ������Ϣ���������տ�����������������¶��ǣ�$n�����������������״����һ��Ϯ�����Ⱦ��ް������"NOR,
        "force" : 520+(level/5)+random(level/2),
        "dodge" : 0,
        "parry" : 0,
        "damage" : 150+random(level/3),
        "damage_type":"����",
	"post_action" : (: dead_msg :)
        ]);
        }
        else if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ������������±޷���\n");
        me->receive_damage("jingli", 10 );
        if( me->query_skill("riyue-bian",1) > 150 ) me->receive_damage("jingli", 5 );
        if( me->query_skill("riyue-bian",1) > 180 ) me->receive_damage("jingli", 10 );
        if( me->query_skill("riyue-bian",1) > 200 ) me->receive_damage("jingli", 15 );

        return 1;
}
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
	object weapon;
        string *msg;
        weapon = me->query_temp("weapon");
        msg = ({
                HIR"ֻ���á�������һ���ҽУ�$n����Ϊ"+weapon->name()+HIR"�����У�ˤ����սȦ���ۼ��ǲ����ˡ�\n"NOR,
                HIR"��һ���������ޣ���ʱ���$p�Խ����ѣ���֫���ۣ��������Ρ�\n"NOR,
                HIR""+weapon->name()+HIR"һ��֮�£�һ����ɽ�������ھ���$n�ؿ�ײ����$n�����߹Ƕ��ۣ��������顣\n"NOR,
        });
        level  = (int) me->query_skill("shaolin-bian",1);
	if ( !living(victim) && level > 200 && me->query("neili")>1000) 
	return msg[random(sizeof(msg))];
}
*/      

string perform_action_file(string action)
{
        if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
                return __DIR__"riyue-bian/" + action;
}


int dead_msg(object me, object victim, object weapon, int damage)
{
	int level;
//	object weapon;
        string *msg;
        //weapon = me->query_temp("weapon");
        msg = ({
                HIR"ֻ���á�������һ���ҽУ�$n����Ϊ"+weapon->name()+HIR"�����У�ˤ����սȦ���ۼ��ǲ����ˡ�\n"NOR,
                HIR"��һ���������ޣ���ʱ���$p�Խ����ѣ���֫���ۣ��������Ρ�\n"NOR,
                HIR""+weapon->name()+HIR"һ��֮�£�һ����ɽ�������ھ���$n�ؿ�ײ����$n�����߹Ƕ��ۣ��������顣\n"NOR,
        });
        level  = (int) me->query_skill("shaolin-bian",1);
	if ( !living(victim) && level > 200 && me->query("neili")>1000) 
	message_vision(msg[random(sizeof(msg))], me, victim);

}