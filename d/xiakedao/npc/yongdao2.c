//Cracked by Roath
// xiakedao/yongdao2.c

inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
���������죬����ɽ������Ȼ��Ѩ������ɡ����ȵ���ˮ֮��
ʱ��ʱ�֡������Ȼ��һ����ʯ���ɵĶ��ţ��Ŷ��Ͽ��š�ӭ���ݡ�
�������֡�������һ����(hole)�����������(zuan)��ȥ��
LONG );

      set("exits", ([
		"north" : __DIR__"yongdao1",
		"south" : __DIR__"yongdao5",
		"east" : __DIR__"yingbin",
      ]));
	set("objects", ([ 
		__DIR__ +"npc/baituo" : 1, 
    	]));
      set("no_clean_up", 1);
    	set("no_fight", "1");
	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
void init()
{	add_action("do_kill", "kill");
	add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{	object me = this_player();
	if ( !arg )
		return notify_fail( "������ʲ��?\n");
	if ( arg != "hole" )
		return notify_fail( "����ʵʵ zuan hole �ɡ�\n");
	message_vision("$Nһ���������Ƕ������˽�ȥ��\n", me);
	write("���ڶ�������һ�����ͻȻ��ǰһ����\n");
	me->move(__DIR__"shibi");
	message("vision", me->name() + "�Ӷ������˳�����\n",environment(me), ({me}) );

	return 1;
}
#include "/d/xiakedao/kill.h"
