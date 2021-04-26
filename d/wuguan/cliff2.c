#include <ansi.h>
#include <room.h>
inherit ROOM;
int do_climb(string arg);
int do_exercise(string arg);
int do_practice(string arg);
int do_study(string arg);
int do_search(string search);
void create()
{
       set("short","悬崖");
       set("long",@LONG
你身处悬崖上，看到武馆后山和树林，真是一片好景色。抬头望去上
面好像不是很陡了，如果轻功好些还能继续向上爬 (climb)，悬崖顶
长着几株不知名的花草(drug)。
LONG);

       set("item_desc", (["drug" : "崖壁竟然长着几株花草，你从没见过那么多的奇花异草。\n"
]));       
       set("cost",4);
       set("outdoors","wuguan");
       setup();
}
void init()
{
       add_action("do_climb", "climb");
       add_action("do_search", "search"); 
       add_action("do_exercise",  "exercise");
       add_action("do_exercise",  "dazuo");
       add_action("do_exercise",  "respirate");
       add_action("do_exercise",  "tuna");
       add_action("do_practice",  "practice");
       add_action("do_practice",  "lian");
       add_action("do_study",  "study");
       add_action("do_study",  "du");
}

int do_climb(string arg)

{ 
       object me = this_player();
       int gain,cost;
       if(me->is_busy())
           return notify_fail("你现在正忙着。\n"); 
       cost = ( 200-me->query_dex()*me->query_skill("dodge")/20 )/20;
       if ( cost<10 )cost = 10;
       me->add("jingli",-cost);
       if( arg != "up" && arg != "down" )
                return notify_fail("你想往哪爬？\n");
	if(me->query_skill("dodge") < 10 && arg == "up" )
		return notify_fail("你轻功不够，怎么也爬不上去。\n");                   
    
       gain = me->query("con")*3/2;
        if(arg == "up" )
           {
          message_vision( HIY"\n$N小心翼翼的爬了上去。\n"NOR, me);
          me->move(__DIR__"cliff3");
          message_vision( HIY"\n$N爬了上来。\n"NOR, me);
          me->improve_skill( "dodge",gain+random( gain ) * 3/2);
          me->add("jingli",-cost);
          me->startbusy( 1 );
          return 1;
}
       else if(arg == "down" )
      {
       message_vision( HIY"\n$N小心翼翼的爬了下去。\n"NOR, me);
       message_vision( HIY"\n$N爬了下来。\n"NOR, me);
       me->move(__DIR__"cliff1");
       me->improve_skill( "dodge",gain+random( gain ) * 2/3);
       me->add("jingli",-cost);
       me->startbusy( 1 );
       return 1;
      }   
       return notify_fail("往地下爬？\n");
}
int do_exercise(string arg)
{
                 object me = this_player();
                 tell_object(me, "你爬在悬崖上，手脚并用，都觉得吃力，哪能腾出手来练功啊？\n");
                 return 1;

}
int do_practice(string arg)
{
                  object me = this_player();
                  tell_object(me, "你爬在悬崖上，手脚并用，都觉得吃力，哪能腾出手来练功啊？\n");
                  return 1;
}
int do_study(string arg)
{
                 object me = this_player();
                 tell_object(me, "你爬在悬崖上，手脚并用，都觉得吃力，哪能腾出手来读书啊？\n");
                  return 1;
}






