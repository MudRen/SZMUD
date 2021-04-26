//Cracked by Roath
// xiakedao/pubu.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
ɽ·�ľ�ͷ��ӭ����һ���ٲ�(fall)��ʮ���ɵĸߴ�ֱ��������
�������µ�ˮ���������ٲ��µ�С̶���������������������С̶��
��һ�ô���(tree)��
LONG );

      set("exits", ([
		     "southdown" : __DIR__"wanghait",
      ]));

	set("item_desc",([
	    "fall" : "�ٲ���������и������������(jump)��ȥ������\n",
	    "tree" : "����һ��������ɣ����Ϲ���Щ�Ͳ����¡�̫�����ò��š�\n",
	]));
	set("objects", ([ 
	    __DIR__ + "npc/master2" : 1,
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("pole_count", 3);
	setup();
}

void init()
{
        ::init();

	add_action("do_jump", "jump");
	add_action("do_climb", "climb");
}

int do_jump(string arg)
{	object me = this_player();
	object coat;

	if ( (!arg )|| ((arg != "fall") && (arg != "tree")))
	{	write("��������(jump tree)\n");
		return 1;
	}
	if( (arg == "tree") )
	{	message_vision("$Nʹ������һ���������ò����������ϵ����¡�������(climb)���ɡ�\n", me);
		return 1;
	}
	if (!present("rain coat", me))
	{	write("ˮ������㻹���Ҽ����°ɡ�\n");
		return 1;
	}
	coat = present("rain coat", me);
	if  (coat->query("equipped") == 0)
	{	write("ˮ������㻹�ǰ����´��ϰɡ�\n");
		return 1;
	}
	else
	{	message_vision("$N�߽��ٲ�������Ծ�˽�ȥ��\n", me);
		me->move(__DIR__"yongdao1");
		message("vision", me->name() + "�������˽�����\n",environment(me), ({me}) );
	}

	return 1;
}
int do_climb(string arg)
{	object coat, me = this_player();

	if ( (!arg ) || (arg != "tree") )
		return 0;

	if (!(present("rain coat", me)) || !(present("rain coat", environment(me))))
	{	message_vision("$N������������������һ�����¡�\n", me);
		coat = new(__DIR__+ "obj/coat.c");
		coat->move(me);
	}
	else
		write ("����̰�ģ����˻��á�\n");

	return 1;
}
