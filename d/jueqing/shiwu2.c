// Filename:   /d/jueqinggu/shiwu2.c
// by Jiuer /08/2001


inherit ROOM;

void create()
{
	set("short","石室");
	set("long",@LONG
这是一个很小的石头搭起的屋子。屋角摆着一个大水缸，地上铺着
两张草席。
LONG);

	set("exits",([ "out" : __DIR__"shiwu1", ]));

	set("sleep_room",1);
	set("no_fight",1);
	set("resource/water", 1);

	set("cost",1);
	setup();	
}

