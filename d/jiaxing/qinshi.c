// Code of ShenZhou
// Jay 8/9/96
#include "room.h"
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��̴�㣬һ��(bed)һ��������򵥣����Ϲ���ɴ�ʣ���
�ǳ¾ɣ��ѳʻ�ɫ�����Ϸ���һ�����١�������һ���¶���(door)��
ͨ��÷ׯ������ȡ�
LONG
        );
        set("exits", ([
		"east" : __DIR__"huilang",
	]));

	set("objects", ([
		__DIR__"npc/huang" : 1,
		__DIR__"npc/obj/yaoqin" : 1,
	]));
        set("item_desc", ([
                "bed" : "����ͨͨ��һ�Ŵ���\n",
		"door" : "�����ƺ���δ������\n",
        ]));
        create_door("east","�¶���","west", DOOR_CLOSED);

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if (dir=="enter") {
	say (me->name()+"�߽����������ӹ��ְѰ��Ź�������\n");
	me->set_temp("new_valid_dest", "/d/jiaxing/didao1");
	delete("exits/enter");
	me->set_temp("huang",0);
	me->set_temp("danqing",0);
	me->set_temp("tubiweng",0);
	me->set_temp("heibai",0);
	return 1;
    }
    return ::valid_leave(me, dir);
}



