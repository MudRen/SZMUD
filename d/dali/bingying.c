// Code of ShenZhou
// Room: /d/newdali/bingying.c

inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
大理国虽小，却重视精兵良将。然屈人必先屈志，兵戈乃下下之
策，段氏大理先与北邻宋朝修和，再以姻亲拉拢当地人，多年无战事。
这是城里的铁骑营，为皇族的嫡系，装备给养无不优于中原地方。军
士们严阵以待，盔甲鲜明，刀剑锋利。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"north" : __DIR__"dahejie",
		"west" : __DIR__"majiu",	
		]));

	set("objects", ([
		__DIR__"npc/weishi2" : 1,
		__DIR__"npc/dalishibing" : 2,
		]));

	set("no_clean_up", 0);

	setup();
}
