//Cracked by Roath
// Room: /d/beijing/east/shandao5.c

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
  "northeast" : __DIR__"fulanting",
  "westdown" : __DIR__"jifangting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
