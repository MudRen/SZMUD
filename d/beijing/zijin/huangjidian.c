//Cracked by Roath
// Room: /d/beijing/zijincheng/huangjidian.c

inherit ROOM;

void create()
{
	set("short", "�ʼ���");
	set("long", @LONG
������Ǭ¡�ʵ�׼����̫�ϻʾ��е���ĵط�������Ԫ�꣬Ǭ¡
̫�ϻ����ڴ˵����ǧ���硣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ningshougong.c",
  "south" : __DIR__"ningshoumen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
