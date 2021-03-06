// Filename:   /d/jueqinggu/valley.c 山谷深处
// Code by :   Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","山谷深处");
	set("long",@LONG
皮筏行至山谷深处，这里山青水碧，景色极尽清幽，四下寂无声息，
隐隐透着凶险。你又划出三四里，溪心忽有九块大石(stone)迎面耸立，
犹如屏风一般，挡住了来船去路。
LONG);
	
	set("item_desc",([
		"stone" : "九块巨大的岩石组成的石屏，挡住了去路。你正在犹豫不知\n"
		+"该怎么过去时，突然发现右下角的岩石发出的砰撞声有点不同。\n"
		]));

	set("outdoors", "jueqing" );
	
	set("cost",2);
	setup();	
}

void init()
{
	add_action("do_push","push");
	add_action("do_drift","drift");
}

int do_push(string arg)
{
 	object me = this_player();
	if( !arg||arg == "" )
		return 0;
	if( arg == "stone"||arg=="shi") 
	{
		message_vision("$N伸手按了按，岩石没有任何反应，$N顺势推了一把岩石……\n"+
        "只听得咔喳一声巨响，中间的两块岩石向两边裂开，露出一条细窄的河道。\n\n",me);

        remove_call_out("close_door");
        call_out("close_door",10,me); 
		
		message_vision("$N迅速地划入河道，皮筏向前驶去。\n\n",me);
		me->move("/d/jueqing/path");
		message_vision("$N跳下皮筏，转身向山谷走去。\n",me);
		return 1;
        }
        else
			return notify_fail("你要干什么？\n");
}
int do_drift()
{
	object me = this_player();
	message_vision(HIW"$N握紧船弦，皮筏顺河颠簸漂流而下。\n"NOR,me);
	me->move("/d/jueqing/shangu");
	message_vision(HIW"河水卷着$N的皮筏，颠簸着从上游漂流而下。\n"NOR,me);
	return 1;
}
void close_door()
{
        tell_room(this_object(),"又过了一会儿，传来一阵轰隆声，岩石又被合在了一起。\n");
}
