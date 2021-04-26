// Code of ShenZhou
inherit ROOM;




void create()
{
        set("short", "静室");
        set("long", @LONG
这里是黄眉大师静修的地方，屋中只有一张大青石(stone)。
LONG
        );

        set("objects",([
                "/d/dali/npc/yellow" : 1
        ]));

     set("item_desc", ([
	"stone" : "一张圆桌大小的青石，上面纵横交错画了三十八条直线。\n",
        ]));

        set("cost", 1);
	 setup();
}

void init()
{
        add_action("do_draw", "draw");
}
int do_draw(string arg)
{
object me = this_player();

        if ( !arg || arg != "line" )
             return notify_fail( "什么？\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("什么？\n");

if ((int)me->query_skill("finger",1) <= 40 ) {
             me->improve_skill("finger", me->query("str")+random(10));
             write( "你伸出手指用力在石面上画来画去。\n");
          
me->add("jingli", -35);
}
else {
write( "你伸出手指用力在石面上画来画去。却觉得自己线以经画得很直了\n");
}
return 1;
}













