// Code of ShenZhou
//
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ������ϼ�����֣������ƽ�����ɫ�ͷף������������ط���
����Ҫïʢ��࣬���µ�����Ҳʮ�����ʣ������˸ո��������
LONG
	);
        
	set("exits", ([
                "west" : __DIR__"xiangzhong",
		"east" : __DIR__"jingshe",
           ]));
        
        set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));
	
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}

/*
void init()
{
	object ob = this_player();
	if (ob->query_temp("th_tomb_thief")) {
		tell_object(ob,CYN"���ƺ������������е�����������˵��������\n"NOR);
		delete("exits/east");
		set("exits/east", __DIR__"hyjuchu");
    		remove_call_out("close_door");
    		call_out("close_door",random(20),ob);

	}
}


void close_door()
{
	delete("exits/east");
	set("exits/east", __DIR__"jingshe");
}


int valid_leave(object me, string dir)
{
	if (me->query_temp("th_tomb_thief") && dir == "east") { 
		me->move("/d/taohua/hyjuchu");
         	return 1;
	}

    	return ::valid_leave(me, dir);
}
*/
