//Cracked by Roath
// xiakedao/yongdao.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������ɽ����ͻ������һ��ʯ�ڣ������Ӳݴ�������ߺ����и�
С��(hole)���ƺ�������(zuan)��ȥ��������(jump)��ȥ����ɽ���ˡ�
LONG );
        set("objects", ([ 
			 __DIR__ + "npc/monkey" : 1, 
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 0);
	setup();
}

void init()
{
        ::init();

	add_action("do_zuan", "zuan");
	add_action("do_jump", "jump");
}

int do_zuan(string arg)
{	object me = this_player();
	if ( !arg )
		return notify_fail( "������ʲ��?\n");
	if ( arg != "hole" )
		return notify_fail( "����ʵʵ zuan hole �ɡ�\n");
	message_vision("$Nһ���������Ƕ������˽�ȥ��\n", me);
	write("���ڶ�������һ�����ͻȻ��ǰһ����\n");
	me->move(__DIR__"yongdao2");
	message("vision", me->name() + "�Ӷ������˳�����\n",environment(me), ({me}) );

	return 1;
}
int do_jump(string arg)
{	object me = this_player();
	if ( !arg )
	{	write("��Ҫ��������\n");
		return 1;
	}
	if ( arg != "down" )
		return 0;
	message_vision("$N��ɽ����������ȥ��\n", me);
	me->move(__DIR__"shanxia");
	if (me->query_skill("dodge") > 20) 
		message("vision", me->name() + "ɽ��������������\n",environment(me), me );
	else
		message("vision", me->name() + "ɽ���Ϲ���������\n",environment(me), me );
	return 1;
}
