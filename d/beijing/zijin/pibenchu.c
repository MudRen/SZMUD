//Cracked by Roath
// Room: /d/beijing/zijincheng/pibenchu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ڸ��ֵı��¶������������ʸ��ʵ�,�ʵ�������,����
���������ڸ�.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"maoqindian",
  "south" : __DIR__"yuehuamen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
