// Code of ShenZhou
// room: /d/xingxiu/tianroad4.c
// Jay 3/18/96
#include <ansi.h>

inherit ROOM;

void init();
int do_jump(string);

void create()
{
        set("short", "天山山路");
        set("long", @LONG
这里是天山东麓，山风从山上吹来，你冷得瑟瑟发抖。路边是一片针叶
林。石壁上盛开着一朵洁白的天山雪莲，一个采药人正在采药。东面一条深
涧(valley)挡住了下山的路。
LONG
        );
        set("exits", ([
            "westup" : __DIR__"tianroad5"
]));
        set("objects", ([
                __DIR__"npc/caiyaoren"  : 1,
        ]));

       set("item_desc", ([
        "valley" : "深涧有三丈多宽，不过因为这边地势高，应该不难跳(jump)过去。\n"
        ]) );


        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 3);
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_jump", "jump");
}

/*
int do_jump(string arg)
{
        int i;
        object me, *ob;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="valley" ) {
               message("vision", me->name() + 
                          "一提气，双足点地跳过了深涧。\n",
               environment(me), ({me}) );
                ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++){
        if( ob[i]->query("rider") == me )
        ob[i]->move("/d/xingxiu/tianroad3");
        }
               me->move("/d/xingxiu/tianroad3");
               message("vision", me->name() + 
                          "从深涧上面跳了下来。\n",
               environment(me), ({me}) );
               return 1;
       }
}
*/

int do_jump(string arg)
{
        int i;
        object me, *ob;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        
        if( arg=="valley" ) {
        
        	if( me->query("rided") ){
                          message("vision", me->name()+"猛地一提缰绳，胯下的马一声长嘶越过了深涧。\n",
         		  environment(me), ({me}) );
                          write("你猛地一提缰绳，胯下的马一声长嘶越过了深涧。\n");
                          ob = all_inventory(environment(me));
        		  for(i=0; i<sizeof(ob); i++){
        	          	if( ob[i]->query("rider") == me )
        		  	ob[i]->move("/d/xingxiu/tianroad3");
        		  }
          
 	                  me->move("/d/xingxiu/tianroad3");
                          message("vision", "只听得唏溜溜一声马嘶，" + me->name() +  "从深涧的那端纵马跳了过来，好似当年马跳\n檀溪的玄德公。\n",
                          environment(me), ({me}) );
                          write("只听得唏溜溜一声马嘶，你从深涧的那端纵马跳了过来，"
                          "真是酷呆了。\n");
                          return 1;
                }
                else {
                	if (me->query_skill("zhaixinggong",1)>100){
                		if (me->is_busy())
                			return notify_fail("你现在正忙着呢！。\n");
                		message_vision(HIY"$N运起本门轻功，用力一纵，轻飘飘地越过了深涧。\n"NOR, me);
                		me->move("/d/xingxiu/tianroad3");
                		message_vision(HIC"$N定了定神，觉得身轻气爽，脚底飘浮，急忙收住轻功。\n"NOR, me);
                		me->start_busy(random(3)+2);
  //              		me->improve_skill("dodge",random(me->query_skill("zhaixinggong",1)));
                		me->add("jingli",-100);
                	} else  write("你试了试，发现深涧的那边比这边高，非是人力可以跳上去的。\n");
                        return 1;
                }
        }
}
