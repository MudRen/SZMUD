// Code of ShenZhou
// Room: /d/dali/jiulou.c

inherit ROOM;

void create()
{
	set("short", "̫�;�");
	set("long", @LONG
���Ǵ���������ľ�¥��¥����Щ�����С�ԣ���������
����������·�ˡ�¥����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"jiulou2.c",
  "west" : __DIR__"taihejie2.c",
]));

        set("objects", ([
"/d/dali/npc/xiaoer2" : 1,
]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

