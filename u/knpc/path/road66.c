// Code of ShenZhou
 // ʯ�ݶ�
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "ʯ�ݶ�");
    set("long", @LONG
ɽ·����ʯ�ݶ���ʯ�ݶ��������ж������������������ߴ����
�ྻ�������Ͽ���խ��״�縡�ݡ����ϱ㵽������¤��ɽ·�ľ�ͷ����
һ���ɱ����ϵĴ����
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                  "westup" : __DIR__"road65", 
		  "east" : __DIR__"road75", 
                ])
       );
	switch(random(3)){
	case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1,
				  "/d/xingxiu/npc/spider2" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }
	set("cost", 2);
    setup();
    replace_program(ROOM);
}
