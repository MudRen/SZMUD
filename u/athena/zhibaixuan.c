
// ����ܰ(Athena) 
// Room��/u/athena/zhibaixuan.c 

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", MAG"Ҿ��ָ����"NOR);
	set("long", @LONG
��������Ϊ԰���Ӵ����ͺ����ѵĵط�����ʱҲ��Ϊ��Ϸ˵
���дʫ����֮��������ȡ���䡰ǰҾ®ɽ��һ����塱�͸���
�ġ�Цָͥǰ�ء���ʫ�⡣���ڰ�������ɫ��ƾ����������Ŀ
ʯ����ᾣ��Ű��֦���ƣ�������Դ��ʮ�˾���֮�ơ�
LONG
);
	set("exits", ([
	"south" :__DIR__"liuyuan",
        "north" :__DIR__"chitang",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoxue" : 1,
                __DIR__"obj/bxz" : 1,
]));
 	set("outdoors", "Sufu");
	setup();
}
