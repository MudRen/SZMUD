// Code of ShenZhou
// Room: /d/dali/eastgate.c

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
这里就是大理城的东门，青石城墙上刻了“大理”两个斗大
的篆字。门口站了几个衣甲鲜明的兵士，神色漠然地看着来往的
行人。
LONG
	);
	set("outdoors", "dali");
	set("cost", 1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dahejie1",
  "east" : __DIR__"guandao9",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dalishibing" : 3,
  __DIR__"npc/dalijunguan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
