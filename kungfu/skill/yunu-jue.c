// Code of ShenZhou
// yunu-jue.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("yunu-jue", 1);
	
	if(me->query("gender") == "����" && lvl > 39)
		return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����\n");
		
	if(me->query("class") == "bonze")
		return notify_fail("������"+RANK_D->query_respect(me)
			+"������ţ���ôȴ��ѧ�����ķ���\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("��Ů��ʮ�ľ������������ϣ���Υ��������徻֮�⣬"
                        +RANK_D->query_respect(me)+"���޴˹������������\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("��Ů��ʮ�ľ�ֻ�ܿ�ѧϰ����ߡ�\n");
}
