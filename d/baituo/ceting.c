// Code of ShenZhou
// jiuer 6/17/2002

inherit ROOM;

void create()
{
	set("short", "侧厅");
	set("long", @LONG
这里是白驼山庄的侧厅，少庄主常在这里给庄人们分配庄里庄外大大
小小的事宜。屋内设施比大厅简单些许，但是桌几屏壁雕功甚精，特别是
北边入室处白玉雕琢的两条相互缠绕的巨蛇，嗔目吐舌，狰狞无比，极显
杀气。
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"changlang4",
		"north" : __DIR__"dating",
	]));

	//set("objects", ([ 
	//	CLASS_D("baituo")+"/ke" : 1,
	//	]) );
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
