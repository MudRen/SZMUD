//Cracked by Roath
// /xiakedao/Dong3.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ�������ɽ�������ܵ�ǽ�ϲ��Ż�ѡ������ǽ�߷���һ��ʯ����
���Ϸ���һ����װ��(book)��
LONG );

	set("exits", ([
		"south" : __DIR__"",
	]));

	set("item_desc",([
	    "book" : 	"����һ������ȥ�ܾɵ��飬������д��������֣��׽��ƪ��\n"
			"��������Ŷ���(du book)ȥѧ������ڹ��� \n",
	]));

	setup();
}

void init()
{
        ::init();

	add_action("do_du", "du");
}

int do_du(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "����ѧʲ��?\n");
	if ( arg != "book" )
		return notify_fail( "����ʵʵ du book �ɡ�\n");

	if (!(int)me->query_temp("mark/ѧ1"))
	{	write("ÿ��ѧϰ��ľ��ͻ��ٶ�ʮ�㣬�����ľ�̫�;�����޷����С�\n");
		write("������ʵս����̫�ͣ�(�����ڹ�^3 > ����*10)������޷���ѧ�ˡ�\n");
		me->set_temp("mark/ѧ1", 1);
	}

	check = (int)me->query_skill("force",1)*(int)me->query_skill("force",1)*(int)me->query_skill("force",1);
	if (check < (int)me->query("combat_exp") * 10)
	{	write("�����ڵ�ʵս���鲻�㣬�޷���������ڹ���\n");
	}
	else if ((int) me->query("jing") < 30)
	{	write("�㾫���޷����С�\n");
	}	
	else
	{	me->receive_damage("jing", 20, "������������");
	      me->improve_skill("force", (int)me->query_skill("literate")/5 + 1);
      	write("����������ڹ�����ļ������ѡ�\n");
	}
	return 1;
}
