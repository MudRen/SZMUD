// Code of ShenZhou
// Room: /d/murong/lianwu
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
    这里是燕子坞的练武场，四周放满了十八般兵器，传说
慕容氏通晓天下武技，可能此言不虚。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"xiaoqiao",
        "southeast" : __DIR__"humian",
        "east" : __DIR__"lianwu1",
                      ]));

	set("no_clean_up", 0);
        set("outdoors", "murong");

        set("objects", ([
		"/d/murong/npc/menke" : 3,
		]));

	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir=="southwest" ) {
                if (dir=="southwest" && me->query("family/family_name")=="姑苏慕容")
                        return notify_fail("那儿是慕容弟子练武的地方,没事少去为妙！\n");
        }
        return ::valid_leave(me, dir);
}
