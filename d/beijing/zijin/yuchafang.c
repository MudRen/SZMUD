//Cracked by Roath
// Room: /d/beijing/zijincheng/yuchafang.c

inherit ROOM;

void create()
{
	set("short", "���跿");
	set("long", @LONG
������̫���ֵ��,����̫����������ʱ�Ⱥ�ʵ۵����١�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"qianqinggong",
  "south" : __DIR__"duanningdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
