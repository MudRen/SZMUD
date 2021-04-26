 // welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIC"杂货店"NOR);
        set ("long", "这里是一个小的杂货店，店铺四周凌乱的摆放着几个小箱子，都是一
些日常用品。在这里你可以用"HIG"list"NOR"命令列出货物表，用"HIG"buy <物品名>"NOR"命令
来买东西，用"HIY"eat <物品名>"NOR"和"HIY"drink <物品名>"NOR"命令来吃或者喝东西。
");

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"welcome2",
                ]));

        set("objects", ([
                "/d/city/npc/xiaoer2" : 1,
                ]));

        set("valid_startroom", "1");
        set("no_fight", 1);

        setup();
}

void init()
{
        object me = this_player();        
        object wage;
        if(!me->query("wage"))
        {
                wage = new("/clone/money/silver");
                wage->set_amount(10);
                wage->move(me);
                me->set("wage",1);
        }

}

