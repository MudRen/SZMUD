//Cracked by Yujie
///d/forest/shilu.c
// by yujie 10 / 2001

inherit ROOM;


void create()
{
        set("short", "石路");
        set("long", @LONG
这是从封锁的石门后通往长乐帮后山的石路，再往北走就是长乐帮的
天然温泉场。这一路景色颇佳，还不时地有鸟语花香随风飘来。
LONG );
        set("exits", ([
		"out"  : __DIR__"clhoulang3",
		"north": __DIR__"clwenquan",
	]));
	
        set("outdoors","forest");
        set("cost",1);
        
        setup();
        
        replace_program(ROOM);
     
}


