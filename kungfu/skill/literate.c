// Code of ShenZhou
// literate.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	if (!me->query_temp("mark/��")
		&& (me->query("class") != "bonze"
			 || (me->query("family/family_name") != "������" &&
			me->query("family/family_name") != "������"
			 && !me->query_temp("mark/����"  ))
			 || me->query_skill("literate", 1) > 100) &&
			 (me->query("class") != "taoist" || me->query("family/family_name") != "ȫ���"
			 || me->query_skill("literate", 1) > 100) )
		return notify_fail("�����ڲ���ѧϰ����д�֡�\n");
	return 1;
}
