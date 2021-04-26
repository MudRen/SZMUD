// river.c  小溪
//Jiuer 10-28-2001

inherit ROOM;

void create()
{
        set("short", "小溪");
        set("long", @LONG
迈出一大片树林，这里是一条从山里缓缓流淌的小溪。溪水在山石和
青草地间静静地流过，溪面上漂浮着些枯叶和腐桩，恰是天然形成了一座
小桥，越过小溪向西是雾朦朦的一片山谷。
LONG);
        
		set("exits", ([
			"north" : __DIR__"grassland",
			"south" : __DIR__"forest2",
			"east" : __DIR__"huangshaling",
		//	"west" : "/d/jueqing/"
			]));

		set("resource/water", 1);
		set("cost", 1);
		set("outdoors", "gumu");
		setup();
		replace_program(ROOM);
}
