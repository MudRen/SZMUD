//Cracked by Roath
// Room: /d/beijing/east/shandao2.c

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
  "northeast" : __DIR__"wanchunting",
  "westdown" : __DIR__"fulanting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
