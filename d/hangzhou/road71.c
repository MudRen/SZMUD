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
�������������߸���һ����������ϱ��������ɽ��ɽ·��
LONG);

    set("exits", ([ /* sizeof() == 3 */ 
                   "northeast" : __DIR__"road25", 
                   "west" : __DIR__"road72", 
                   "southwest" : __DIR__"yuhuang1", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/tangzi" : 2,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
