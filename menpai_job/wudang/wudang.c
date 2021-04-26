 //CODE BY SCATTER
//Control Center
//wudang.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "武当门派工作控制室");
        set("long", @LONG
可以使用的指令如下
检查工作等级 (chklevel)
检查门派点数 (chkmp)
检查工作细节 (chkinfo)

设定工作等级 (setlevel <等级>)
设定门派点数 (setmp <点数>)
修改细节 (setinfo <FUNCTION> <VALUE> <COUNTER>)

LONG
        );


        set("exits", ([
                                        "out" : "/d/wizard/ccenter",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
