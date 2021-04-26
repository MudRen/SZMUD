// Code of ShenZhou
// Room: /d/dali/hongtj.c

inherit ROOM;

void create()
{
	set("short", "塔基");
	set("long", @LONG
宏圣寺塔基座系用石板砌成，与千寻塔基为砖砌不同。基
座西面有塔门，可入内攀登而上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hongts1.c",
  "out" : __DIR__"hongshengt.c",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "up" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(10));
                write("你爬上一层楼，有些累了。\n");
        }

        else if (dir == "up" && current_jingli <= 10)
        {
                write("你累得走不动了，忽然眼冒金星，晕了过去。\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

