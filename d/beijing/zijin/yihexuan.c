//Cracked by Roath
// Room: /d/beijing/zijincheng/yihexuan.c

inherit ROOM;

void create()
{
	set("short", "�ú���");
	set("long", @LONG
����ԭΪǬ¡�ʵ۹�������Ϣ֮�������ú͡���������Ǭ¡��
��Ԥף���Լ������Ҹ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"leshoutang",
  "north" : __DIR__"hougongmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
