// Code of ShenZhou
// Room: /city/kedian2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼的打酣声，一
阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜处付了钱再上来
睡觉。
LONG
	);

	set("exits", ([
		"down" : __DIR__"qzkedian",
		"enter" : __DIR__"qzkedian3",
	]));

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       if(me == present("xiao er"))
		return ::valid_leave(me, dir);
	                       
	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("门锁着呐，进不去! \n");

	return ::valid_leave(me, dir);
}
