// Filename:   /d/jueqinggu/stoneroad.c
// Jiuer   08/2001

inherit ROOM;

void create()
{
	set("short","��ʯ��·");

	set("long",@LONG
һ����ֱ����ʯ��С·��·����ֲ�滨��ݣ����ܲ�ľ������Σ�
�����ƽ���һ·�����Ƿ����ʤ���Ų����У�ֻ��·���ɺ���������¹
��Ⱥ������С�ã����Ǽ��˲����������Ǹ���ˮ��(tang)��
LONG);
	
	set("exits",([ 
		"north" : __DIR__"shiwu",
		"west" : __DIR__"shanlu4",
		]));

	set("item_desc", (["tang" : 
			"ˮ����ÿ������߱���һ��ľ׮(jump muzhuang)��\n"]));
	
	set("objects",([
		__DIR__"npc/squirrel" : 1,
		]));

	set("outdoors","jueqing");
	set("cost",1);
	setup();	
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me = this_player();

	if(!arg || arg != "muzhuang")
		return notify_fail("��Ҫ��ʲô? \n");
	
	message_vision("$N������ľ׮����ȥ��\n", me);
	
	if ( me->query_skill("dodge",1) <= 20 ) 
	{	
		message_vision("$N����һ�ģ�һͷײ��ľ׮�ϡ�\n", me);
		me->unconcious(); 
	}
    
	if ( me->query_skill("dodge",1) > 20 && me->query_skill("dodge",1) <= 50 ) {
		message_vision("$Nһ��û����ȥ��̤���˼���ľ׮��\n", me);
            }

	if ( me->query_skill("dodge",1) > 50 ) 
	{
		me->move(__DIR__"shuitang");
		message("vision", me->name() + 
			"����΢�ϣ���Ծ̤׮������\n",environment(me), ({me}) );
	}
		return 1;	
}		
