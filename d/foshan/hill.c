// Code of ShenZhou
//Jay 4/7/96

#include <room.h>

inherit ROOM;
int do_bocao(string);

void create()
{ 
       set("short","ɽ��");
       set("long", @LONG
�����Ǵ����һ��Сɽ�𡣵����ǻĲ�ûû����紵����
������֮����
LONG
     );
        set("exits", ([
                "northdown" : __DIR__"cunkou",
        ]));       

        set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));
	set("outdoors", "wudang");
	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_bocao", "bocao");
}


int do_bocao(string arg)
{
	object me = this_player();
	if (me->query_temp("qi/bocao")) {
        message_vision("$N�����Ĳݣ��ݺ�¶��һ��ɽ����\n", me);
        set("exits/enter", __DIR__"cave");
        remove_call_out("close");
        call_out("close", 5, this_object());
        return 1;
	}
	return 0;
}

void close(object room)
{
        message("vision","һ����紵���������ֿ������ˡ�\n", room);
        room->delete("exits/enter");
}
 
