//room: jian.c

inherit ROOM;

#include <ansi.h>;
void init();
int do_zou(string);

void create()
{
  set("short","百丈涧");
  set("long",@LONG
山道到此突然消失，在你面前是一条山涧，山涧之中云雾缭绕，你根
本无法看清对面。一条铁索(tiesuo)深入云中，旁边有一块石碑(bei)。
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "southdown" : __DIR__"yan",
     ]));
  set("objects",([
    "/kungfu/class/lingjiu/tbhao" : 1,
    ]));
  set("item_desc",([
      "bei" : "『灵鹫宫』重地，擅入者死！\n" ,
      "tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。\n" ,
     ]));
        set("cost", 3);
  setup();
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="tiesuo")
		return notify_fail("你要走什么？\n");

	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能移动。)\n");

        if( !me->query_skill("yueying-wubu", 1) > 0 && !me->query_skill("lingbo-weibu", 1) > 0 
		&& random((int)me->query_skill("dodge")) <= 30  ){
                me->receive_damage("qi", 50, "从山坡上滚下来摔死了");
                me->receive_wound("qi",  50, "从山坡上滚下来摔死了");
                message_vision(HIR"$N一不小心脚下一滑，... 啊...！\n"NOR, me);
                me->move(__DIR__"shanjiao");
                message("vision", HIR"只见" + me->query("name")
                + "咕碌咕碌地从山坡上滚下来，狼狈不堪。\n"NOR, environment(me), me);
	tell_object(me, HIR"你从山坡上咕碌咕碌地滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
        return 1;
        }

	if(!( room = find_object(__DIR__"xianchou")) )
		room = load_object(__DIR__"xianchou");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' \n");
	message_vision("$N踩上铁索，飘然而去。\n",me);
	message("vision","你只见一个身影飘然而来。\n", room);
        me->move(room);
        return 1;
}
