// Code of ShenZhou
// Room: /d/murong/qing5
//arthurgu /1999.9

#include "room.h"
inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
    ���ϴ��˼ҵķ��ݶ�Ϊ�������ؽṹ����һ��������ŷ���
�����������ס�ĳ������ڶ���Ϊ������µĵط���������������
����������������֮��һ�㻹�к�Ժ��
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing4",
        "north" : __DIR__"qing6",
        "west" : __DIR__"sleep1",
        "east" : __DIR__"sleep2",
                      ]));

	set("no_clean_up", 0);
        set("outdoors", "murong");

        set("objects", ([
		"/d/murong/npc/shinu" : 3,
		]));

	setup();
	
}

int valid_leave(object me, string dir)
{
        if (dir=="west" || dir=="east") {
                if (dir=="west" && me->query("gender")=="����")
                        return notify_fail("����Ů�ӵ��᷿��\n");
                if (dir=="east" && me->query("gender")=="Ů��")
                        return notify_fail("�������ӵ��᷿��\n");
        }
        return ::valid_leave(me, dir);
}
