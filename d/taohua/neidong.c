// Code of ShenZhou
//Kane

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ڶ�����ʪ�쳣������ˮ��ſ�׹�£����ڵ����Сˮ���У�
�������졣�������̫���������Ҫ����������
LONG
	);

                set("exits", ([
                "east" : __DIR__"neidong",
                "south" : __DIR__"neidong",
                "west" : __DIR__"neidong",
                "north" : __DIR__"neidong",
                ]));

        set("cost", 15);
	setup();
//	replace_program(ROOM);
}

void init()
{
   add_action("do_use","use");
}

int do_use(string arg)
{
    object me = this_player();

    if( !arg || arg=="" ) return 0;
    if (!present("fire", me))  return 0;
    if( arg=="fire" ) {
	write("���Ż��ӳ�գ����߳����⡣\n");
     	me->move(__DIR__"qingyin");
	}
    return 1;
}

int valid_leave(object me, string dir)
{
	int kar;

	kar = 80 - me->query("kar");

	if(random(kar) == 1) {
		write("���ߵþ�ƣ���������ڵ��˶��⡣\n");
		me->move(__DIR__"qingyin");
		return 1;
	}

	return ::valid_leave(me,dir);
}
