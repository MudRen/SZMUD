// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ʱ��Ժ");
        set("long", @LONG
�����ǹ��귨��֮�����յ����Ĵ��һ������������������У�
��ǰ��һ�������������˺��ĻƳ��������˷��֡����ơ������
�
LONG
        );
        set("exits", ([
                "east" : __DIR__"jingang",
		"south" : __DIR__"sengshe",
        ]));
	set("objects",([
        "clone/weapon/fachu" : 1,
	"clone/weapon/faling" : 1,
	"/clone/weapon/falun" : 1,
        "/kungfu/class/xueshan/ling-zhi" : 1,
        ]));
	set("cost", 1);
        setup();
}
