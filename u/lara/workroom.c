// Room: /u/lara/workroom.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"古墓丽影工作室"+NOR);
        set("long", @LONG
这是测试巫师劳拉的工作室，由于劳拉忙于测试工作，很少回家
打扫卫生，这里积满了灰尘，结满了蜘蛛网，蜘蛛网上有几只倒霉的
小虫(bug)被网住了。

LONG
        );
        set("exits", ([ 
                  "job" : "/d/wizard/job_room",
                  "huiyi"  : "/d/wizard/meeting_room",
                  "gumu"  : "/d/gumu/dating",
                  "mp"  : "/d/wizard/smiling_room",                  
                  "wg"  : "/d/wuguan/zhengting",                  
                  "clb"  : "/d/forest/clzoulang2",                  
                  "test"  : "/d/wizard/test_room",                  
                  "gold"  : "/d/wizard/wizard_room",                         
                  "bamboo" : "/d/wulin/xiaowu",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("item_desc", ([
              "bug" : "好大的一只臭虫，你很想抓(catch)在手里将它捏死。\n",
             
 ]));
        set("cost", 0);
        setup();
        call_other("/clone/board/lara_b", "???");
}
void init()
{   add_action("do_catch", "catch"); }

int do_catch (string arg)
{   object room;
    object me = this_player();
    if (!arg||arg!="bug") return notify_fail("你要抓什么？\n");
    message_vision("$N恶狠狠的想抓住大臭虫，不料却抓了个空。\n\n"
                   +HIB"原来这只是一个幻影......\n" 
                   +HIC"$N正感诧异，忽觉身子一轻，已被时空转移到了武林同盟山门。\n"NOR, me );
   
    me->move("/d/wulin/shanmen") ;

    return 1 ;
}

