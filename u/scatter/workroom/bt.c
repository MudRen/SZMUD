// Room: menpai
// V. 1.0
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIM"���ձʼ���"NOR);
        set("long", @LONG
������Ƿ�ڤ�ӷűʼǵĵط�, ͨ�����˵�Ľ������
��ͨ���̶���������д�±ʼ�. ������������߾Ϳ��Իص�
�ʼǷ�.
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
                                  "out" : "/u/scatter/note",
]));      
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);

        setup();
                "/clone/board/scbt"->foo();
        replace_program(ROOM);
}

