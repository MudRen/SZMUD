// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

#include <ansi.h>

inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", HIG"舍身崖"NOR);
        set("long", @LONG
这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小心
，一失足掉下去，只怕连骨头都找不到。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
          "eastdown" : "/d/huashan/canglong",

        ]));

        set("outdoors", "huashan");
        set("cost", 3);
        setup();
}
void init()
{
        add_action("do_climb","climb");

}
int do_climb(string arg)
{
        object me = this_player();

        if (arg!="up") 
        return notify_fail(HIG"这个方向没办法爬。\n"NOR);
                
        if (me->query_skill("dodge",1) < 360)
        return notify_fail(HIG"你爬了半天毫无进展，还是回去练练轻功在来吧。\n"NOR);
        
        if (me->query("jingli") < 2000)
        return notify_fail(HIG"你精神不好，还是歇歇再爬吧，小心送了小命！\n"NOR);

        me->add("jingli",-500);

        message_vision(HIG"$N手脚并用，使出了吃奶的力气终于爬了上来。\n"NOR,me);
        me->move("/u/slow/questwg/juding1");
}
                
