// Code of ShenZhou
// yiwei-dujiang.c һέ�ɽ�

inherit SKILL;

int valid_learn(object me)
{
	mapping fam;
	object weapon;

	fam = me->query("family"); 
	if( !mapp(fam) || fam["family_name"] != "������" )
		return notify_fail("�㲻���������ɣ�����ѧϰһέ�ɽ�����\n");

	if ( fam["family_name"] == "������" && fam["generation"] != 35 )
		return notify_fail("���ʸ񲻹�������ѧϰһέ�ɽ����ȵ����˶��ֱ���˵�ɡ�\n");

	return 1;
}

