//Cracked by Roath
// xiakedao/xkx.h

string* bskills = ({
	"force", 
	"dodge", 
	"sword", 
	"strike",
	"", 
	"", 
	"", 
	"", 
	"", 
	"", 
	"", 
	"", 
	"", });


//	"cuff", 
//	"claw",
//	"blade",
//	"throwing", 
//	"club",
//	"whip",
//	"finger", 
//	"stick",
//	"hand", });

string* askills = ({
	"taixuan-gong", 
	"liuxing-bu",
	"wugou-jianfa", 
	"wuyu-zhangfa", 
	"",
	"",
	"", 
	"",
	"", 
	"",
	"",
	"",
	"", });
int do_study(string arg)
{	object me = this_player();
	int check;

	if ( !arg )
		return notify_fail( "����ѧʲ��?\n");
	if ( arg != "wall" )
		return notify_fail( "����ʵʵ study wall �ɡ�\n");
	call_out("do_learn", 0, me, flag);
	return 1;
}

int do_learn(object me, int flag)
{	//object me = this_player();
	//string here, 
	int check;
	string bskill = bskills[flag-1];
	string askill = askills[flag-1];
	// ����㾭�鲻��250�������������10�����޷�ѧ�����й���
	if (bskill == "")
	{	write("�㿴��һ��ͼ�ף������޷�����������ʲ���ˡ�\n");
		return 1;
	}
	
	if (askill == "")
	{	write("�㿴��һ��ͼ�ף������޷�����������ʲ���ˡ�\n");
		return 1;
	}

	if (((int)me->query("combat_exp") < 250) || ((int)me->query_skill(bskill, 1) < 10))
	{	if ((int)me->query_skill(bskill, 1) > 20)
		{	write("�㿴��һ��ͼ�ף������Ѿ��޷�����������ʲ���ˡ�\n");
			return 1;
		}
		check = (int)me->query_skill(bskill,1)*(int)me->query_skill(bskill,1)*(int)me->query_skill(bskill,1);       
		if (check > (int)me->query("combat_exp") * 10)
		{	write ("��ʵս���鲻�㣬�޷�����\n");
			return 1;
		}
		if ((int)me->query("jing") < 30 ) 
		{	write("�㾫���޷����С�\n");
			return 1;
		}
		write("��������" + to_chinese(bskill) + "����ļ������ѡ�\n");
		me->improve_skill(bskill, me->query("int"));
		me->receive_damage("jing", 20, "������������");
		
	}
	else
	{	if ((int)me->query_skill("literate", 1) == 0)
		{	write("��һ�ֲ�ʶ��������ǽ�ϵ�ע�⡣\n");
			return 1;
		} 
		//if (((int)me->query("learned") > 0) && ((int)me->query("learned") != flag))
		//{	write("����ѧ������������һ�Ź��򣬾Ͳ�����ѧ����ˡ�\n");
		//	return 1;
		//}

		if ((int)me->query_skill(askill, 1) > 20 || askill == "")
		{	write("�㿴��һ��ͼ�ף������Ѿ��޷�����������ʲ���ˡ�\n");
			return 1;
		}
		check = (int)me->query_skill(askill,1)*(int)me->query_skill(askill,1)*(int)me->query_skill(askill,1);
		if (check > (int)me->query("combat_exp") * 10)
		{	write ("��ʵս���鲻�㣬�޷�����\n");
			return 1;
		}
		if ((int)me->query("jing") < 30 ) 
		{	write("�㾫���޷����С�\n");
			return 1;
		}
		
		//if ((int)me->query_temp(here) == 0)
		//{	write("��һ�ֲ�ʶֻ�ÿ���ʯ���ϵĻ��׷�����\n");
		//	me->set_temp(here, 1);
		//}
		write("��������" + to_chinese(askill) + "�еļ������ѡ�\n");
		me->set("learned", flag);
		me->improve_skill(askill, me->query("int"));
		if (me->query_skill(askill, 1) == 1)
		{	write("�������enable "+bskill + " " +askill+"�������������⼼�ܡ�\n");
			if (flag == 1)
			{	write("���̫����ѧ����ʮ��������������ʮ��ʱ�Ϳ���������(yun heal)��\n");
				write("�ȵ��˵�ʮ�弶�����ж�ʮ��ʱ�Ϳ���Ϊ��������(yun heal xxx)��\n");
				write("Ȼ���������ɵ��ڹ�ȴ��Ҫ�ϸߵȼ��������ϵĹ��ܡ�\n");
				write("���������������ʮ��ʱ�㻹����exert regenerate ���ָ��Լ��ľ�\n");
				write("exert recover �ָ��Լ�������exert refresh �ָ��Լ��ľ�����\n");
			}
		}
		me->receive_damage("jing", 20, "������������");
	}

	return 1;
}
