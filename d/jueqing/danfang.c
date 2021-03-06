// Filename:   /d/jueqinggu/danfang.c 丹房
// Code by:    Jiuer Aug 15, 2001

inherit ROOM;

void create()
{
	set("short","丹房");

	set("long",@LONG
你打量室中，南靠壁有一把交椅和一张长条桌子，桌上摆放着一些
小柜子。桌上、柜中满列药瓶，壁上一丛丛的挂着无数乾草药，西首并
列三座丹炉(lu)，东首有面窗，这间石室便是所谓丹房了。
LONG);

	set("item_desc", ([
		"lu" : "三座丹炉都由青铜铸成，每个炉脚下都有一个滑轮，你试试想挪动(push)它们。\n"
		]));

	set("exits",([ 
		"east" : __DIR__"changlang3",
		]));
		  
	set("objects", ([__DIR__"npc/jiading" : 1,]));
	set("cost",1);
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player(),obj;

	if ( !arg || arg == "lu") 
		return notify_fail("炉子推动的方向不对！\n");
	
	if ( (int)me->query_str() < 28 )     //限制臂力大于28
		return notify_fail("挪这麽重的丹炉，你还得练几年功。\n");
	
	if (arg == "left") {
		if ( !me->query_temp("jq") )
			me->set_temp("jq",1); //左边的丹炉晃动
		else
			me->delete_temp("jq");
		message_vision("$N试着将西首的丹炉推到东首。\n",me);
	}

	if ( arg == "right" ) {
		if ( me->query_temp("jq") == 1 )
			me->set_temp("jq",2);//右边的丹炉晃动
		else
			me->delete_temp("jq");
		message_vision("$N试着将东首的丹炉推到中间。\n",me);
	}

	if ( arg == "front" ) {
		if (me->query_temp("jq") == 2){
			message_vision("$N试着将中间的丹炉推开，然后将原在中间的推到了西首，轰隆一声.....\n\n",me);
			message_vision("$N只觉足底空虚，眼前一片黑暗，身子笔直堕下不知将落于何处......\n\n\n", me);
			// (waaa. 你成功了, 但是等待你的是更可怕的...)
		
			//	remove_call_out("close_door");
			write("\n\n扑通一声，你掉进了鳄鱼潭。\n\n");
			me->move(__DIR__"eyutan");

			me->receive_damage("qi", 200, "掉进鳄鱼潭淹死了");
			me->receive_wound("qi",  200, "掉进鳄鱼潭淹死了");
			return 1;
		}
		else 
			message_vision("$N试着将中间的丹炉推开，然后将原在中间的推到了西首。\n",me);

		me->delete_temp("jq");
	}	

	return 1;
}
