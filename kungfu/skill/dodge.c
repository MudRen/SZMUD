// Code of ShenZhou
// dodge.c

inherit SKILL;
string type() { return "base_skill"; }
string *dodge_msg = ({
        "���Ǻ�$p����ƫ�˼��硣\n",
        "���Ǳ�$p����ض㿪�ˡ�\n",
        "����$n����һ�࣬���˿�ȥ��\n",
        "���Ǳ�$p��ʱ�ܿ���\n",
        "����$n����׼�������Ų�æ�Ķ㿪��\n",
});

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
