//Cracked by Yujie
// forest/clbajiaoting.c
// by 9 / 2001

inherit ROOM;

void create()
{
        set("short", "后厢房");
        set("long", @LONG
这里是长乐帮后的厢房，再往里便是司徒帮主的师侄石破天的起
居之所。最近他身受重伤，正在里边修养，贝大夫吩咐过不许任何闲
杂人等前来骚扰。
LONG );

        set("exits", ([
		"out" :  __DIR__"clbajiaoting",
        ]));
        set("objects", ([
                "/kungfu/class/misc/dingdang.c" : 1,
                        ]));
                        
        set("cost", 0);
        set("no_fight",1);
        set("no_steal", 1);

        setup();

        replace_program(ROOM);
}
