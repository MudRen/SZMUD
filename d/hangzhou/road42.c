// Code of ShenZhou
// é�Ҳ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "é�Ҳ�");
    set("long", @LONG
·���Ը��ż���С���������ſ�һλ�ϴ�������ι��������С��
����׷����Ϸ���������ϻ����롣�����Ƕ���ɽ��
LONG
        );

    set("exits", ([ /* sizeof() == 2 */ 
                   "northup" : __DIR__"road41", 
                   "southwest" : __DIR__"road43", 
                 ])
        );
	set("objects", ([ "/d/village/npc/boy" : 1,
			  "/d/village/npc/oldwoman" : 1]));

	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
