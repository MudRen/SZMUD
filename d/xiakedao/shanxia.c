//Cracked by Roath
// xiakedao/shanxia.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ɽ����");
        set("long", @LONG
ɽ������һ��ƽ�أ����ܰ��˼���ľ׮(muzhuang)����������Ǹ�
���䳡����һλ��������������������֦��ͷ����Сɽ���д���������
LONG );

      set("exits", ([
		     "north":__DIR__"xiaolu3",
		     "west" : __DIR__"caodi",
		     "southup"  : __DIR__"shanlu4",
      ]));
	set("item_desc",([
	    "muzhuang" : "����һ�����߸ߵ�ľ׮���м���ź���ţƤֽ��������������
���ģ�����Դ��(strike muzhuang)��\n",
	]));
	set("objects", ([ 
		       __DIR__ + "npc/taohua" : 1,
      ]));
	
	set("outdoors", "xiakedao" );
	set("cost", 2);
	setup();
}

void init()
{
        ::init();
	add_action("do_strike", "strike");
	add_action("do_jump", "jump");
}
/*
int do_play(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "������ʲ��?\n");
	if ( arg != "shiqiu" )
		return notify_fail( "����ʲ�����ġ� play shiqiu �ɡ�\n");

	check = (int)me->query_skill("parry",1)*(int)me->query_skill("parry",1)*(int)me->query_skill("parry",1);
	if (check > (int)me->query("combat_exp") * 10)
	{	write ("��ʵս���鲻�㣬�޷�����\n");
		return 1;
	}

      if ((int)me->query("qi") < 30)
		return notify_fail("û��������������ʯ��\n");
	me->receive_damage("qi", 20);

	message_vision("$N����һ��ʯ�򣬰�ʯ��������ת��תȥ���档\n", me);
	if ((int)me->query_skill("parry", 1) >= 30)
	{	write("������һ�����ƣ������ȴ�޷������ʲ�ᡣ\n");
		return 1;
	}

	me->improve_skill("parry", me->query("int"));
	return 1;
}
*/

int do_strike(string arg)
{	object me = this_player();
	int check;
	if ( !arg )
		return notify_fail( "�����ʲ��?\n");
	if ( arg != "muzhuang" )
		return notify_fail( "����ʵʵ��ľ׮�ɡ�\n");

	check = (int)me->query_skill("strike",1)*(int)me->query_skill("strike",1)*(int)me->query_skill("strike",1);
	if (check > (int)me->query("combat_exp") * 10)
	{	write ("��ʵս���鲻�㣬�޷�����\n");
		return 1;
	}

      if ((int)me->query("qi") < 30)
		return notify_fail("���۵���վ��վ�������ˣ������ľ׮��\n");
	me->receive_damage("qi", 20);

	message_vision("$Nվ��һ���������ƻ���ľ׮��\n", me);
	if ((int)me->query_skill("strike", 1) >= 30)
	{	write("�����һ�ᣬ�����Ѿ��޷������ʲ�ᶫ���ˡ�\n");
		return 1;
	}

//	write("������ľ׮�������˼��������Ʒ��е����⡣\n");
	me->improve_skill("strike", me->query("int"));
	return 1;
}
int do_jump(string arg)
{	object me = this_player();
	if ( !arg )
		return 0;
	if ( arg != "up" )
		return 0;
	if (me->query_skill("dodge") > 20) 
	{	message_vision("$Nһ�������Ŵ�ɽ���ϴ��µ���֦������ȥ��\n", me);
		me->move(__DIR__"shibi");
		message("vision", me->name() + "��ɽ��������������\n",environment(me), me );
	}
	else
		message_vision("$N������ȴ�����Ŵ��ŵ���֦��\n", me);
	return 1;
}
