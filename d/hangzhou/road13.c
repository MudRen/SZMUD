// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{   set("short", "��ʯ���");
    set("long", @LONG
��������ˣ����У���ýΣ�����������ϲ�������������
����������������ߺͶ����ߡ������߱����ϱ�ɽ���ϱ���ͨ������
�š�
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                  "east" : __DIR__"road12", 
                  "west" : __DIR__"road14", 
                  "north" : __DIR__"beishan1", 
                  "south" : __DIR__"xileng", 
                 ])
       );
	set("objects", ([
                "/d/taishan/npc/tangzi" : 2,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
