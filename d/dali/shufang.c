// Code of ShenZhou
// Room: /d/dali/shufang.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�����Ƕ��������鷿����������˰ݷ����鷿����з𾭡�
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  "d/shaolin/obj/fojing21" : 1,
  "d/shaolin/obj/fojing11" : 1,
]));
	set("cost", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wangfu9",
]));

	setup();
	replace_program(ROOM);
}
