//Cracked by Roath
// Room: /d/beijing/east/shandao1.c

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
  "northdown" : __DIR__"guoyuan",
  "southup" : __DIR__"wanchunting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
