// qinqi-shuhua.c �����黭

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
//          if ( me->query("int") < 24 && me->query_int() < 32)
                if ( me->query_int() < 30)
	 return notify_fail("�����黭���Ǽ������֮�£�" +RANK_D->query_respect(me)+"�ƺ�̫����������Щ��\n");
         if ((int)me->query_skill("literate", 1)*2 < (int)me->query_skill("qinqi-shuhua",1))
                return notify_fail("���Ծ������Ե��˶��壬�����黭��Ҳû����ߡ�\n");
	if(me->query("family/master_name") != "�����" )
	return notify_fail("��һ������Ĵ��ˣ�ѧ��Щ�ḯ���˵Ķ�����ʲô��\n");	
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�����黭ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
