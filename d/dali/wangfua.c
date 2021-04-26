// Code of ShenZhou
// Room: /d/dali/wangfua.c

inherit ROOM;

void create()
{
	set("short", "Ğ¡Ôº");
	set("long", @LONG
ÕâÊÇÍõ¸®µÄÆÍÈËÔº¡£¶«Î÷·½¸÷ÓĞÒ»¼äÏá·¿£¬ÄÇÊÇÆÍÈËÃÇµÄÎÔ·¿¡£
ÄÏ±ßÊÇÒ»¼ä³ø·¿¡££
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaosi" : 2,
	"kungfu/class/dali/guducheng" : 1,
]));
	set("cost", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"foodroom",
  "west" : __DIR__"wofang1.c",
  "north" : __DIR__"wangfu2.c",
  "east" : __DIR__"wofang2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
