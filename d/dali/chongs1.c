// Code of ShenZhou
// Room: /d/dali/chongs1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ǧѰ�����ڲ����о�����¥�ݿɹ������ʵǡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"chongs2.c",
  "out" : __DIR__"chongs.c",
]));
	set("no_clean_up", 0);
	set("cost", 3);
		setup();
	replace_program(ROOM);
}
