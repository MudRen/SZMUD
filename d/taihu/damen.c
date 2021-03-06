inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大门");
        set("long", @LONG
面前是一座庄院，门楼不甚高大，青砖绿瓦，灰色底的匾上写着
『归云庄』三个大黑字。牌匾较为陈旧，边角处的漆皮已剥落，露出
暗黄色的木质。看来挂在那已不下二十个春秋了。
    门前停着有一对白雕(diao)。
LONG
        );
         set("exits", ([
                "enter" : __DIR__"qianyuan",
                "south" : __DIR__"matou",
        ]));
        set("cost", 1);
        set("outdoors", "taihu");
		set("item_desc", ([
		"diao" : "这是一对白色的大雕，正展翅欲飞。\n"
		"如果是桃花岛的弟子，骑上(ride)就可以飞到\n"
                "桃花岛。看上去它只能驮得动未成年的孩子。\n",
				]));
        set("objects", ([
                "/d/taihu/npc/jiading" : 2,
        ]));

        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "桃花岛") && (dir == "enter") && (!me->query_temp("guiyun")) && present("jia ding", environment(me)))
        return notify_fail("家丁做了个揖，说道：尊驾与敝庄素无往来，庄主不见外客，还是请回吧\n");

    return ::valid_leave(me, dir);
}

void init()
{
    add_action("do_ride", "thd");
    add_action("do_ride", "ride");
}

int do_ride ()
{
    mapping myfam;
    object ob = this_player () ;
    myfam = (mapping)ob->query("family");
/*
        if ( !arg || arg == "")
 return notify_fail("你要骑什么？\n"); 
if( arg != "diao") return 0;
*/
	if( (int)ob->query("str") > 26 ) 
         return notify_fail("白雕发出了几声凄厉的惨叫，原来它被你压扁了。\n");
    if(!myfam || myfam["family_name"] != "桃花岛")
    {
      message_vision("$N一跃身跨上了白雕。只见白雕仰天长唳，突然猛然一颠......\n"
                     HIR "结果$N摔了个鼻青脸肿！\n" NOR
                     "看来白雕对$N并不感兴趣，它只认识桃花岛的弟子。\n" , ob ) ;
      ob -> receive_damage ("qi",50) ;
      ob -> receive_wound  ("qi",50) ;
      return 1;
    }
	if( (int)ob->query("age") > 18 ) 
         return notify_fail("白雕扑打了几下翅膀，但是没有飞起来，显然你的年纪太大了。\n");
    if( (int)query("sb_ride") ) 
         return notify_fail("现在白雕正忙着,请过一会再乘坐!\n" ) ;
    add("sb_ride",1) ;
    message_vision(HIW"$N一跃身跨上了白雕。只见白雕仰天长唳，突然展翅高飞。\n\n"NOR
                   HIW"但看一雕一人身形渐渐缩小，终至不见。\n" NOR, ob );
    ob->move("/d/taohua/lantian") ;
    tell_object(ob, CYN  "\n你不断地飞呀飞，万水千山身下飘过 ......\n\n" NOR ) ;
    call_out("taohua", 3 , ob );
    add("sb_ride",-1) ;
    return 1 ;
}
void taohua( object ob )
{
  tell_object(ob, "你终于飞到了桃花岛，白雕落了下来。\n\n"  ) ;
  ob -> move ("/d/taohua/haitan");
}
