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
�������߿����׷壬�ϱ��Ǿ����¡�
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road71", 
                   "west" : __DIR__"road73", 
                   "south" : __DIR__"jingci1", 
                   "northup" : __DIR__"xizhao1", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/dao-ke" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
