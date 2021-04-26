// Room: note
// V. 1.0
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIW"�ʼ���"NOR);
        set("long", @LONG
������Ƿ�ڤ�ӷűʼǵĵط�, ͨ�����˵�Ľ������
��ͨ���̶���������д�±ʼ�. �����Ǹ������ɵıʼǷ���.
������ο���ڤ�ӵ�����.

LONG
        );

        set("exits", ([ /* sizeof() == 3 */
                  "hs"  : "/u/scatter/workroom/hs",
                                  "sl"  : "/u/scatter/workroom/sl",
                                  "wd"  : "/u/scatter/workroom/wd",
                                  "gb"  : "/u/scatter/workroom/gb",
                                  "xx"  : "/u/scatter/workroom/xx",
                                  "em"  : "/u/scatter/workroom/em",
                                  "bt"  : "/u/scatter/workroom/bt",
                                  "xs"  : "/u/scatter/workroom/xs",
                                  "kl"  : "/u/scatter/workroom/kl",
                                  "th"  : "/u/scatter/workroom/th",
                                  "gm"  : "/u/scatter/workroom/gm",
                                  "other"  : "/u/scatter/workroom/other",
                                  "tiejiang"  : "/u/scatter/workroom/tiejiang",
"out" : "/u/scatter/workroom",
]));      
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);

        setup();
    //"/clone/board/smeetingb"->foo();
        replace_program(ROOM);
}

