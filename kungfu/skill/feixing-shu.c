// Code of ShenZhou
// feixing-shu

#include <ansi.h>
inherit SKILL;
string type() { return "base_skill"; }

string *parry_msg = ({
	  "$n����һ�һ�����εľ����ͳ�����$N����$n��$l��һ��ֱ���˿�ȥ��\n",
          "����$n������һЦ�����������һ����������$N��������;���˿�ȥ��\n",
          "$n������˿���������Ϻ����֣�$N΢�����죬���ɵý��������˻�ȥ��\n",
          "$nһ����У����һ���������ж㿪��\n",
          "$n��Ҳ��������$N����ʹ����˫������$N��΢���¼���һ���ĭ���Լ�Ʈ����ֻ�����㿪��\n",
});


int valid_enable(string usage)
{
        return (usage == "parry");
}


string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}


int practice_skill(object me)
{
        return notify_fail("��������������ϰ��ֻ��ͨ���Լ������ѧϰ��ߡ�\n");

}
string perform_action_file(string action)
{
        return __DIR__"qiankun-danuoyi/" + action;
}

