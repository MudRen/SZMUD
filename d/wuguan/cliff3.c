#include <ansi.h>
inherit ROOM;
int do_climb(string arg);
int do_search(string arg);void create()
{
       set("short","崖顶");
       set("long",@LONG
这里已经是崖顶，这里是一个平台，四周只长着一些花草(drug)，向
四周望去，武馆完全展现在你的眼里。
LONG);
       set("item_desc",([
                "drug" : "这里有很多的药草。\n"]));
       set("cost",4);
       set("outdoors","wuguan");
       setup();
}
void init()
{
       add_action("do_climb", "climb");
       add_action("do_search", "search");
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
       gain = me->query("con")*2;
       if( arg == "down" )
      {
          message_vision( HIY"\n$N小心翼翼的爬了下去。\n"NOR, me);
          me->move(__DIR__"cliff2");
          message_vision( HIY"\n$N爬了下来。\n"NOR, me);
          me->start_busy( 0 );
          me->improve_skill( "dodge",gain+random( gain )*3/2);
          me->add("jingli",-cost);
          return 1;
      }     
        return notify_fail("这里不能往上爬。\n"); 
        return 0;
}

int do_search(string arg)
{
              object me = this_player();
              int gain,cost,rr,aa,bb;
              if(me->is_busy())
              return notify_fail("你现在正忙着。\n"); 
              cost = ( 40-me->query_dex())/2;
              if ( cost<10 )cost = 10;
              me->add("jingli",-cost);
              gain = me->query("con")*2;
              aa = gain + random(20);
              bb = gain + random(10);
              rr = gain + random(10);
              if (arg == "drug")
               {
                me->start_busy(random(5));
                 if ( random(rr) > 32)
                  { 
                   message_vision(HIR"$N眼前一亮，找到一株草药。\n"NOR, me);
                   me->add("combat_exp",aa);
                   me->add("potential",bb);
if ( me->query("potential") > me->query("max_potential"))
{me->set("potential", me->query("max_potential"));}
                 
                tell_object(me,HIC"你得到了"+HIG+chinese_number(aa)+NOR+HIC+"点"+HIR+"经验\n"NOR);
                tell_object(me,HIC"你得到了"+HIG+chinese_number(bb)+NOR+HIC+"点"+HIW+"潜能\n"NOR);
                          return 1;}  
                   else 
                      {
return notify_fail(HIR"$N找到了几棵草药，但看来没什么用。你随手把它扔掉了。\n"NOR, me);
        }
           return 1;
}
     return;
}              








