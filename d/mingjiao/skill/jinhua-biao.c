// Code of ShenZhou
// jinhua-biao.c ����

inherit SKILL;

mapping *action = ({
([      "action": "$NͻȻһ���շ������н��������������$n�����",
        "lvl" : 0,
        "cost": 120,
        "attack" : 20,
        "damage" : 5,
        "weapon" : "biao",
        "damage_type": "����"
]),
	// add more actions
});

mapping query_action(object me, string arg)
{
        int i, level, neili;
        level = ( me->query_skill("jinhua-biao", 1) + me->query_skill("force") / 3 * 2
                + me->query("max_neili") / 20 ) / 10;
        neili = me->query("neili");

        if( arg )
        {
                for( i = sizeof(action); i > 0; i-- )
                        if( level >= action[i-1]["lvl"] && action[i-1]["weapon"] == arg )
                                return action[i-1];
        }
        else for( i = sizeof(action); i > 0; i-- )
                if( level > action[i-1]["lvl"] && neili > action[i-1]["cost"] )
                        return action[NewRandom(i, 20, level/5)];
}