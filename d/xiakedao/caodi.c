//Cracked by Roath
// xiakedao/chaodi.c
// modified by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
���ﳤ����������Ӳ� (grass)�����µ�С·�����޷����ϡ���
��һ��紵�����ǲ����ζ����������Ϸ�����ż����ͷһƳ������
�ݴ��к������ʲ�ᶫ����
LONG );

      set("exits", ([
		"east" : __DIR__"shanxia",
		"west" : __DIR__"tulu",
      ]));
	set("item_desc",([
	    "grass" : "��Ƭ�Ӳ����������\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("begger_count", 1);
	setup();
}
void init()
{
        ::init();

   	add_action("do_push", "push");
}

int do_push(string arg)
{	object begger, me = this_player();
	if ( !arg )
		return notify_fail( "��Ҫ��ʲô��\n");
	if ( arg != "grass" )
		return notify_fail( "ʲ�᣿\n");
	if (present("begger", environment(me)) || (int)query("begger_count") == 0)
	{	if (! present("ye tu", environment(me)))
		{	message_vision("$N�����Ӳݣ�һֻҰ�����˳�����\n", me);
			begger = new("/d/wudang/npc/yetu.c");
			begger->move(environment(me));
		}
		else
		{	write("�㲦���Ӳݣ�û����ʲ�ᡣ\n");	}
		return 1;	
	}	
	message_vision("$N�����Ӳݣ�һ����Ӱ���˳�����������һ������\n", me);
	begger = new(__DIR__ + "npc/xuedao");
	begger->move(environment(me));
	set("begger_count", 0);
	return 1;
}
