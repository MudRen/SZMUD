// Room: /u/piao/guibinshi.c
// piao 2001/10/07

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "贵宾室");
        set("long", @LONG
这里是饕餮楼的贵宾室。室内布置的古色古香，红木家具雕工精细，
墙上挂书字画，均为历代名家真迹。从窗户朝外望去，泰山的风景一览无
余，群山连绵起伏，烟雾缭绕。窗边一张茶几上摆着一个水晶盘子(panzi)
，里面经常陈放着人参果、腊八粥之类的罕见珍品。
LONG
        );

        set("exits", ([
                "down" : __DIR__"taotielou",
        ]));
/*        
        set("objects",([
                "/d/city/obj/kaoya" : 1,
         	"/d/xingxiu/obj/hulu" : 1,
	]));
*/
        set("item_desc", ([
                "panzi" : HIW"这是一个水晶制成的盘子。\n"NOR,
        ]));      
        
        set("no_fight","1");
        set("no_steal", "1");
        set("no_sleep_room", "1");
	set("cost", 0);
        setup();
}

void init()
{

        object me;
        me = this_player();
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_exercise",  "practice");
        add_action("do_exercise",  "lian");
        add_action("do_exercise",  "study");
        add_action("do_exercise",  "du");
	add_action("do_search",    "search");
	if (interactive(me)) 
	me->delete_temp("guibinshi");
	return;
	
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, CYN"在这高雅之地做这种事，不太好吧。\n"NOR);
        return 1;
}

int do_search(string arg)
{
        object ob,me;
        me = this_player();
        if (!arg || arg == "") return 0;
        
        if (arg == "panzi" || arg == "tray")

        {
                if (query("searched"))
                        return notify_fail("你来迟了一步，盘子里的珍品已经被人吃完了。\n");

                switch (random(5))
                {
                        case 0:
                        ob = new(DRUG_D("renshen_guo"));
                        break;
                        case 1:
                        ob = new(DRUG_D("xueteng"));
                        break;
                        case 2:
                        ob = new(DRUG_D("xuelian"));
                        break;
                        case 3:
                        ob = new(DRUG_D("lingzhi"));
                        break;
                        case 4:
                        ob = new("/d/xiakedao/obj/zhou");
                        break;
                }

                set("searched",1);              
                message_vision("$N从盘子里找到了"+ob->query("name")+"。\n",me);
                ob->move(me);
                return 1;
        }
}       


   

