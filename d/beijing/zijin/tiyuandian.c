//Cracked by Roath
// Room: /d/beijing/zijincheng/tiyuandian.c

inherit ROOM;

void create()
{
	set("short", "��Ԫ��");
	set("long", @LONG
��õ����������Ϸ̨������Ϸ̨,����̫����ʮ�ٳ�ʱ,ͬ����
�����ɼ�����ÿ���ڴ˿�Ϸ,�������֮��.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"changchungong",
  "south" : __DIR__"taijidian",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
