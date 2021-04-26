// Room: scatterLobby

#include <ansi.h>
#include <room.h>


inherit ROOM;

void create()
{
        set("short", HIG"�����Ҷ�"NOR);
        set("long", @LONG
������ǻ�����һ��.ֻ���������������ͼ.��ʱ�㻹����
�����ڴ��˯.��䷿�����;�Ǹ���ʦ�����õ�.ͨ��һ�����
���Ὺһ�����ֻ���.�����߾��Ǵ�����.

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                  "out"  : "/u/scatter/lobby",
]));      
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);
//      set("objects", ([
//              "/clone/board/bj_wizb" : 1,
//      ]));

        setup();
        replace_program(ROOM);
}

