// Code of ShenZhou
// �岨��
// Dong  11/03/1996.
// nta:  Need to add some npc here.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", CYN"�岨��"NOR);
    set("long", @LONG
԰�ſ���һ����¥�������Ͽ��š��岨�š�����¥��վ�ż�����
����������Ů������׹����ۡ��������ͽ��˾۾�԰��������ص���·.
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                   "east" : __DIR__"road25", 
                   "west" : __DIR__"jujing2", 

                 ])
       );
	set("objects",([
                "/d/village/npc/girl" : 2,
        ]));
	set("cost", 1);
     set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
