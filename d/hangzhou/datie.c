// Code of ShenZhou
// ��СȪ������
// Dong  11/03/1996.
// Buying food code needed here. !!!

// NTD:  NPC and object. ����������СȪ���嵶��

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{   set("short", "������");
    set("long", @LONG
����һ�Ҳ�С�Ĵ����̣�������˼�����¯��һλ�������ڻ�¯
����ͷ�󺹵ش��춫����һλ�������ڱ��ϡ���¯�߷��Ų��ٴ����
��������
LONG);

    set("exits", ([ /* sizeof() == 1 */ 
                   "west" : __DIR__"road22", 
                 ])
       );
	set("objects", ([
                "/d/quanzhou/npc/tiejiang" : 1,
		"/d/hangzhou/npc/ouzhizi" : 1,
        ]));
	set("cost", 0);
    setup();
    replace_program(ROOM);
}
