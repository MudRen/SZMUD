// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "洱水桥");
	set("long", @LONG
一座长百余步的青石桥。此桥横跨洱水，连接下关城和大理城，
桥下清澈的洱水滚滚东去。桥北正是下关城的城门，桥南一路南行十
数里即可到大理城。
LONG
        );

	set("exits", ([
		"north" : __DIR__"xiaguan",
		"southeast" : __DIR__"gaten1",
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 2);
	setup();
}
