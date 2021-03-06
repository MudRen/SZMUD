 // Code of ShenZhou
// Room: /city/dongdajie1.c
// YZC 1995/12/04  
// Last Modify by Scatter
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "东大街");
        set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边不时地传来金属撞击声，
西边人声嘈杂。北边是一座简朴的院子，半月形的大门上方写着“白鹿书院”四
个烫金大字，苍劲有力。里面不时地传来学生们抑扬顿挫的读书声。南边是一家
杂货铺。
LONG
        );
        set("outdoors", "city");
              set("fanhua",1); 

        set("exits", ([
                "east" : __DIR__"dongdajie2",
                "south" : __DIR__"zahuopu",
                "west" : __DIR__"guangchang",
                "north" : __DIR__"shuyuan",
              "southeast" : "/newjob/tiejiang/datiechang",
        ]));
        set("objects", ([
                __DIR__"npc/xunbu" : 1,
        ]));

        set("cost", 1);
        setup();
}


void init()
{
        if(query("exitopen"))
        {
                write(HIY"分冥子施工中请不要到 SOUTHEAST。\n Scatter '2002\n"NOR);
        }
        add_action("do_open_men", "open");
        add_action("do_close_men", "close");
}


int do_open_men(string arg)
{
        object ob, me = this_player();
        object room;

        if (query("exits/enter"))
                  return notify_fail("这扇门已经是打开的。\n");

        if (!arg || (arg != "men" && arg != "west"))
                  return notify_fail("你要打开什么？\n");

        if ( (string)SECURITY_D->get_status(me) != "(arch)" )
                  return notify_fail("什么？\n");

        set("exits/southeast", "/newjob/tiejiang/datiechang");
                set("exitopen", 1);
        message_vision("$N用手指凌空一点，吱地一声，打开一道大门。\n", this_player());

        return 1;
}

int do_close_men()
{
        if (!query("exits/southeast"))
                  return notify_fail("这扇门已经是关上的。\n");

        delete("exits/southeast");
        message("vision", "大门慢慢地关上了。\n", this_object());
                delete("exitopen");
        return 1;
}
