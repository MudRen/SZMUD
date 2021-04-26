// newjob/builder/
//Jiuer  10/2001

inherit ROOM;

void create()
{
	set("short","工棚");
	set("long",@LONG
这是一大间凿石工棚，棚子用四根大树桩子支撑着，棚顶四壁用几片
大席围成的，棚顶叠搭着几片大草席，几个小石匠正在埋头「叮铛，叮铛」
敲着手里的活计，一个白胡子老翁来回走着不断指点着身旁的助手们凿刻
一块大条石。工棚西边是一个铺子。
LONG);
	
	set("exits",([
		"east" : __DIR__"hill1",
		"west" : __DIR__"shop",
		]));
	
	set("objects", ([
		__DIR__"npc/shijiang" : 1,
		]));
	
	set("outdoors", "builder");
	set("cost", 0);
	setup();
	replace_program(ROOM);
}
