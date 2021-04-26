#include <ansi.h>
inherit ROOM;
int do_climb(string arg);
void create()
{
       set("short","后山悬崖");
       set("long",@LONG
位于武馆后山深处的一个比较陡的峭壁，在峭壁上有一些突起，似乎
可以向上爬(climb)，在峭壁的不远处有一块牌子(board)。
LONG);
       set("exits",([
       		"east" : __DIR__"xiaojing2",
                   ]));
       set("item_desc",([
               "board" : "上面写着"+HIC+"此处危险，请注意"+NOR+"。\n",
                 ]));   
       set("cost",4);
       set("outdoors","wuguan");
       setup();
}
void init()
{
       add_action("do_climb", "climb");
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
       gain = me->query("con")*3/2;
       if( arg == "up" )
      {
          message_vision( HIY"\n$N小心翼翼的爬了上去。\n"NOR, me);
          me->move(__DIR__"cliff2");
          message_vision( HIY"\n$N爬了上来。\n"NOR, me);
          me->start_busy( 0 );
          me->improve_skill( "dodge",gain+random( gain ));
          me->add("jingli",-cost);
          return 1;
      }     
        return notify_fail("往地下爬？\n"); 
}









