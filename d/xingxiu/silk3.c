 // Code of ShenZhou
// /d/xingxiu/silk3.c
// Last Update By Scatter
#include <ansi.h> 
inherit ROOM;

// int do_climb();

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这条中原和西域的通道，在沙包遍地、红柳丛生的大沙漠上，弯弯曲
曲地向前延伸。朝远处眺望，但见无边无际的茫茫沙海上，被旋风卷起的
沙柱，时而蓦地腾空而起，如狂奔野马，顶天立地，呼啸而来。一会儿又
似袅袅炊烟渐渐远行，徐徐散去。
LONG
        );
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "southeast" : __DIR__"silk2",
                "west" : __DIR__"silk4",
       "north" : "/newjob/tiejiang/gate1",
        ]));
        set("item_desc", ([
                "mount" : 
        "这是一座黄沙堆积形成的山。微风吹动，沙山发出嗡嗡的响声。你\n" 
        "不禁对自然的造物发出由衷的赞叹。\n"
        ]) );

        set("cost", 2);
        setup();
}


void init()
{
        if(query("exitopen"))
        {
                write(HIY"分冥子施工中请不要到 NORTH。\n Scatter '2002\n"NOR);
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

        set("exits/north", "/newjob/tiejiang/gate1");
                set("exitopen", 1);
        message_vision("$N用手指凌空一点，吱地一声，打开一道大门。\n", this_player());

        return 1;
}

int do_close_men()
{
        if (!query("exits/north"))
                  return notify_fail("这扇门已经是关上的。\n");

        delete("exits/north");
        message("vision", "大门慢慢地关上了。\n", this_object());
                delete("exitopen");
        return 1;
}
