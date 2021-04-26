// Code of ShenZhou
// Room: /d/dali/wangfua.c

inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
��������������Ժ������������һ���᷿�����������ǵ��Է���
�ϱ���һ��������
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
