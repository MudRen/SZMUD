//Cracked by Roath
// Room: /d/beijing/zijincheng/chengsudian.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǳ��������Ǿ��ʹ���������ի����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jingrengong",
  "south" : __DIR__"zhaigong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
