// Code of ShenZhou
#include <room.h>
inherit ROOM;

void kick();

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ������С������ֱ�ĳ��������졣���Ծ���������յ�ï�ܵ����֣�
�ϱ�������һ��С����
LONG
        );
        set("exits", ([
		"east" : __DIR__"zhulin2",
                "south" : __DIR__"pomiao",
        ]));

	set("objects",([
		CLASS_D("gaibang") + "/jian" : 1,
	]));

	create_door("south", "С��", "north", DOOR_CLOSED);

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "ؤ��") && dir == "east" &&
                objectp(present("jian zhanglao", environment(me))))
                return notify_fail("����һ�Ѿ�ס�������˵�������ţ���\n");
        return ::valid_leave(me, dir);
}

