//Cracked by Roath
// Room: /d/beijing/east/shandao4.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��������һ��ƽ����ʯ��·�ϣ�·�Թ������죬����
���к����׷ɣ���ʱ�����Կ�����ֻС�޴��Ա��ܹ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"wanchunting",
  "eastdown" : __DIR__"zhoushangting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
