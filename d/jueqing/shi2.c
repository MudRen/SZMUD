// /d/jueqing/shi2.c  大屋
// By jiuer

inherit ROOM;

void create()
{
	set("short","大屋");
	set("long",@LONG 
这是间较大的房间。房中床榻桌椅，全与古墓中的卧室相同，但见
室右有榻，室中凌空拉着一条长绳，窗前小小一几。室左立着一个粗糙
木橱，只是古墓中用具大都石制，此处的却由粗木搭成。
LONG);
	
	set("exits",([ 
		"west" : __DIR__"shi1",
		]));
	
	set("sleep_room", 1);
	set("cost",1);
	setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "west" ) {
			for (i=0; i<sizeof(inv); i++) {
				if (inv[i]->is_character())
					return notify_fail("你不能带着其他玩家离开。\n");
			}
		}
		return ::valid_leave(me, dir);
}