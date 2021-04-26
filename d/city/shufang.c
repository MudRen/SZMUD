//Cracked by Yujie
// Room: /city/shufang.c
// by 2001/9/13

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "天宝阁书房");
        set("long", @LONG【神州】里的著作就是出自这个小小的作坊
。正中放着一件大的工作桌，堆着一垒一垒新成的草稿，旁边围着一群正在
埋头抄书的伙计学徒，整个书房洋溢着一种浓厚的书卷味。
LONG
        );
        set("exits", ([
                "out" : __DIR__"beidajie1",
        ]));

        set("objects", ([
                "/d/huanghe/npc/shutong" : 1,
        ]));

        set("no_fight",1);
        set("no_sleep",1);
        set("cost", 0);
        setup();
}

void init() 
{ 
  write(HIG"一走进这里迎面就扑来一阵书香，你顿时神清气爽，外面的腥雨江湖俨如两个世界。\n"NOR);
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");

}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "恩。你还是专心抄书吧！\n");
        return 1;
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "恩。你还是专心抄书吧！\n");
        return 1;
}
int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "这里是书房，比手划脚的可不雅观哦！\n");
        return 1;
}


int valid_leave(object me, string dir) 

{ 

if (present("booktool",me))

return notify_fail("做事要有始有终哦，半途而废可不对。\n"); 

return ::valid_leave(me, dir); 
}



