// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ϣ��Ӷ���Ʈ��һ�����͵���ζ��������һ��¥��
LONG
        );
        set("exits", ([
                "west" : __DIR__"sengshe",
                "north" : __DIR__"jingang",
                "east" : __DIR__"chufang",
		"northup" : __DIR__"hongdian",
	"south" : __DIR__"yanwu",
        ]));


	set("cost", 1);
        setup();
        replace_program(ROOM);
}
