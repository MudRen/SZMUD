// By xuanyuan
// road: /d/lingjiu/midao1

int do_study(string);

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
	add_action("do_study", "lingwu");
}
int do_study(string arg)
{
	object me;
        mapping fam;

	me = this_player();

	if ( !arg || arg != "fuhao" )
		return notify_fail("ʲô��\n");

        if (!mapp(fam = me->query("family")) || (string)me->query("family/family_name") != "���չ�") 
		return notify_fail("�㲻�����չ��ӵܣ����򲻵�ʯ�������̵Ĺ�����š�\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if (me->query("jing") < 60)
		return notify_fail("��ľ���������\n");

	me->receive_damage("jing", random(60), "�����ʴ�����");

	message_vision("$N��ר���ж�ʯ���ϵĹ�����š�\n", me);

	if (   (int)me->query_skill("bahuang-gong", 1) < 120
		&& (int)me->query_skill("liuyang-zhang", 1) < 120
		&& (int)me->query_skill("zhemei-shou", 1) < 120
		&& (int)me->query_skill("tianyu-qijian", 1) < 120){
		message_vision("$N�ַ�ʯ�ڣ���ɫ��䣬ҡҡ��׹��\n", me);
		message_vision("��Ȼ$N�����������������������λζ�������ˤ���ڵء�\n", me);
		me->unconcious();
		return 1;
		}

	switch( random(3) ) 
	{
	    case 0:
		if ( (int)me->query_skill("liuyang-zhang", 1) < 200)
		{
			me->improve_skill("liuyang-zhang", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ�����ɽ�������е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("zhemei-shou", 1) < 200)
		{
			me->improve_skill("zhemei-shou", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ�����ɽ��÷���е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("tianyu-qijian", 1) < 200)
		{
			me->improve_skill("tianyu-qijian", me->query("int"));
			write("�����ʯ����ĥ��һ�ض����ƺ��������潣�е��ĵá�\n");
			me->set_temp("shibi1_learned",1);
		}
	}

	if ( !me->query_temp("shibi1_learned") )
	{
		write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}