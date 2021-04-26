// Code of ShenZhou

void init()
{
	add_action("do_start", "start");
	add_action("do_knock", "knock");
}

string look_book()
{
	string desc, *msg;
	
	desc = "С������д��һЩ�������йصĿھ���ʫ�ʣ�����һҳд�ţ�\n\n";
	
	msg = ({
"������ʮ������
һ����������	�����б����	�����о���ϸ	�ġ�ȫ������	�塢��ռҪ��
������·��ͨ	�ߡ��ڹ����	�ˡ������ͽ�	�š��������	ʮ����˧����\n\n",
"����ȫ����ʮ������Ϊ��ɫ��Ϊ�죬�蹵�����ֺӽ磬��·�ݺᾡ��ͨ��\n\n",
"������˧�����ۣ���ʿ������Ź�����緽����ϱ�������ֱ����������
��б�շ���������Խ������Զ����������ǰ���������ɺ�һ���ɺ�ͨ��\n\n",
"����Ϊ��ǣ���������֣�Ӯ���Ե��⣬������������\n\n",
"��ͷһ�ڵ��ȶ࣬���ᳵǰ��ɺӣ���ʤ����Ӧ���ˣ�ʧ����������͡�\n\n",
"���巨���ñ�ͬ��ı��ȫƾ���ֹ���ʤ�������յ��ƣ�̰�����ӱ��޹���
������������Ӧ��������ӽ伱�����ɰ�Ѱ����η�ӣ����������Ծ�ͨ��\n\n",
	});
	desc += msg[random(sizeof(msg))];
	return desc;
}

int do_start(string arg)
{       object board, me = this_player();

	if (present("chinese chess board", environment(me) ) )
	{       
	write("�����Ѿ���һ�������ˡ�\n");
		return 1;       
	}       
	message_vision("$N�ں����������̣�׼�����֡�\n", me);
	board = new("/clone/misc/chess");
	board->move(environment(me));
	return 1;
}
