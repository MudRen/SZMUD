// Code of ShenZhou
// Room: /d/murong/qing3
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
    这是一个不大的天井，地面铺着一块块小小的青砖(zhuan)，西面是一间不大的女室，东面是男室，看来是给这里的使女及男仆居住的。北面是一个门厅。估计后面就是内室了。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing2",
        "north" : __DIR__"qing4",
        "west" : __DIR__"chufang",
        "east" : __DIR__"kufang",
                      ]));

	set("no_clean_up", 0);
        set("outdoors", "murong");

        set("objects", ([
		"/d/murong/npc/shinu" : 3,
		]));

	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir=="east" || dir=="west") {
                if (dir=="west" && me->query("family/family_name")=="姑苏慕容")
                        return notify_fail("非慕容氏弟子不能进去！\n");
                if (dir=="east" && me->query("family/family_name")=="姑苏慕容")
                        return notify_fail("非慕容氏弟子不能进去！\n");
        }
        return ::valid_leave(me, dir);
}
