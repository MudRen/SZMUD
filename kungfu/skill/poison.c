// Code of ShenZhou
// poison.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	int lv;
	lv = (int)me->query_skill("poison", 1);
	
	if (me->query("family/family_name") == "����ɽ") {
		if ( lv > 100 && me->query("baituo/breed") < lv )
			return notify_fail("��Զ���ȱ��ʵ��Ӧ�ã����Լ�����ߡ�\n");
	}
	else {
		if (lv < 101 && lv > 50 && me->query("body_poison") < lv/10)
			return notify_fail("�����ھ۶����࣬���Լ�����ߡ�\n");
		if (lv > 100 && me->query("body_poison") < lv)
			return notify_fail("�����ھ۶����࣬���Լ�����ߡ�\n");
	}
	return 1;
}
