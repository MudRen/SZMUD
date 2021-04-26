// Code of ShenZhou
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "÷ׯǰ��");
        set("long", @LONG
������쾮������һ����÷��֦�����������ǲԾ���������������
һ������(zhongtang)���������(door)����һƬ÷�֡�
LONG
        );
        set("exits", ([
		"south" : __DIR__"mzgate1"
	]));

        set("item_desc", ([
		"door" : "�����ƺ���δ������\n", 
                "zhongtang" : "����������һ�����˵ı��棬ī�����죬�����۽���"
			"���⡸��������������ī�����֣��ʷ�ɭ�ϣ�һ�ʱ��糤"
			"���Ĵ̻���\n",
        ]));
        create_door("south","����","north", DOOR_CLOSED);
	set("objects", ([
		__DIR__"npc/huang2" : 1,
		__DIR__"npc/danqing2" : 1,
		__DIR__"npc/tubiweng2" : 1,
	]));
        set("no_clean_up", 0);

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
   if (dir =="south" ) {
        if (objectp(present("huangzhong gong", environment(me))))
                return notify_fail("���ӹ����ٵ�ס�����ȥ·��\n");
        if (objectp(present("tubi weng", environment(me))))
                return notify_fail("ͺ���̻ӱʵ�ס�����ȥ·��\n");
        if (objectp(present("huangzhong gong", environment(me))))
                return notify_fail("�������ӽ���ס�����ȥ·��\n");
   }
   return::valid_leave(me, dir);
}



