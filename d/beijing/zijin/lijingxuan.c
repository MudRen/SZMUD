//Cracked by Roath
// Room: /d/beijing/zijincheng/lijingxuan.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�仪�����µķ��䡣���ǲ�������������ֻ�м���̫����
��ɨ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
