// Code of ShenZhou
// Room: /d/dali/shibei.c

inherit ROOM;

void create()
{
	set("short", "段氏与三十七部会盟碑");
	set("long", @LONG
此碑立于明政三年，是大理国主段素时代的遗物，相当于宋
太祖开宝四年，碑高一.二五米，宽零.五八米，碑文十一行，每
行十三字，碑末有职官题名八行，每行字数不等，碑文共计二百
余字。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"taihejie6.c",
]));
        set("objects", ([
                "/d/village/npc/boy" : 1,
		"/d/village/npc/girl" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
