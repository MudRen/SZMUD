// Code of ShenZhou
int valid_learn(object me)
{
        int level, dg, xl, ds, qg, ld;
        string *sname;
	level = me->query_skill("begging", 1);	
	dg = me->query_skill("dagou-bang", 1);
	xl = me->query_skill("xianglong-zhang", 1);
	ds = me->query_skill("shexing-diaoshou", 1);
	qg = me->query_skill("huntian-qigong", 1);
	ld = me->query_skill("liuhe-dao", 1);
	
	if (me->query("family/family_name") == "ؤ��"){
	if (dg+xl+ds+qg+ld > level*3)	
                return notify_fail("���ǽл��ӣ����Ŀɲ�����������ʦ��ѧϰ�����书��\n");
        return 1;
	}
}
