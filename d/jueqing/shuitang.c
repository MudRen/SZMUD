// Filename:   /d/jueqinggu/shuitang.c
// Jiuer - Aug 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",CYN"ˮ����"NOR);

	set("long",@LONG
һ������ӿ������ǰ�ޱ��޼ʵ�ȫ��ˮ�ɻ���ԭ���������ǳǳ��
һƬˮ��(tang)�����ߣ�������ˮ�ɡ��������֣���ˮ�ɻ�����
�Ϸ�֮���֪���Ծ����ڹ���֮���ɽ�����֡�
LONG);

	set("exits",([ 
		"southwest" : __DIR__"zhulin",
		"southeast" : __DIR__"wenquan",
		]));
	  
	set("item_desc", (["tang" : 
		"ˮ����ÿ������߱���һ��ľ׮(muzhuang)��\n"]));
	set("resource/water", 1);
	set("outdoors","jueqing");
	set("cost",2);

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
		me->move(__DIR__"stoneroad");
		message("vision", me->name() + 
			"����΢�ϣ���Ծ̤׮������\n",environment(me), ({me}) );
	}
		return 1;	
}		
