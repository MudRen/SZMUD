//CODE BY SCATTER
//Control Center
//ccenter.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "工作系统控制室");
        set("long", @LONG
这里就是传说中的控制室. 虽然这里看起来很乱
但是这里的功能多到难以置信. 当然如果你看到
任何问题, 请问分冥子或相关巫师. 这个系统可
是神州的核心之一. 所以切忌乱改设定. 先跟大
家说声谢谢啦.
LONG
        );


        set("exits", ([
                "familyjob" : "/family_job/control.c",
                                        "out" : "/d/wizard/meeting_room",
                                        "wudang" : "/menpai_job/wudang/wudang.c",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
