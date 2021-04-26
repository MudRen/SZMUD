#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "演武场");
       set("long", @LONG
这里是武馆的演武场，是教头们平时考核弟子们成绩的地方，也是
弟子们互相切磋、讨教的地方。周围放着些石锁(suo)、石鼓(gu)，地上
还按九宫八卦之形摆放着梅花桩(zhuang)，想是用来考核弟子们轻功用的。
LONG);
       set("exits", ([
             "east" : __DIR__"yanwuting1",
             "west" : __DIR__"yanwuting3",
             "north" : __DIR__"zhengting",
		]));
	set("objects", ([
	     __DIR__"npc/xuetu1" : 3,
             "/d/wuguan/npc/mu-ren" : 1,
		]));       
/*       set("item_desc", ([
             "zhuang" : "梅花桩是按九宫八卦之形布成的。\n",
             "suo" : "石锁是给武馆弟子们练习臂力用的。你可以试着举(ju)一下。\n", 
             "gu" : "石鼓非常重，你看看是不是能推动(tui)它。\n",]));*/
       set("outdoors", "wuguan");
       setup();
}
/*void init()
{
       add_action("do_ju", "ju");
       add_action("do_tui", "tui");
}
int do_ju(string arg)
{
       object ob = this_object();
       object me = this_player();
       if ( arg != "suo" )
        {write("你举什么？\n");return 1;}
       if ( arg = "suo" )
        { if ( me->query_skill("hand") < 10 )
            return notify_fail(HIR"你扎个马步，双手发力去举石锁，但石锁象生了根似的，纹丝不动。\n"NOR);              
          if(me->is_busy())
             return notify_fail("你现在正忙着。\n"); 
      
          write(HIY"$n扎一个马步，右手发力把石锁高高举过头顶。\n"NOR);
          me->add("jingli", -20);
          me->improve_skill("hand", 20+random(20));
          me->start_busy(1+random(4));
          return 1;
           } 
} 

int do_tui(string arg)
{
       object ob = this_object();
       object me = this_player();
       if (arg != "gu")
         {write("你推什么？\n");return 1;}
       if (arg = "gu")
         { if (me->query_skill("strike") < 10)
              return notify_fail(HIR"你用足了吃奶的力也推不动这石鼓。\n"NOR);              if(me->is_busy())
              return notify_fail("你现在正忙着。\n"); 
           write(HIY"$n气聚丹田，双掌按住石鼓边缘，发力把石鼓推开了一尺。\n"NOR);
     me->add("jingli", -20);
     me->improve_skill("strike", 20+random(20));
     me->start_busy(1+random(4));     return 1;
          }
}*/







