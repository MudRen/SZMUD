// Code of ShenZhou
// Room: /d/xixia/dacaigou.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��񹵵��Ʋ���������������Ҫ���Ƚ�ƽ̹���ٵ�����ȫ�����֣�
ʱ�����Է򿳲�����������д�����
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiaofu" : 1,
]));
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wsling",
  "southwest" : "/d/qilian/gulang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
