//Cracked by Roath
// Room: /d/beijing/east/xiaojing1.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
��������һ��ʯ��·�ϣ�·�Թ������죬���ݴ��к����׷ɣ�
��ʱ�����Կ�����ֻС�޴��Ա��ܹ���������һ������������߾ͽ�
�Ͻ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : "/d/beijing/west/bridge",
  "east" : __DIR__"xiaojing2",
  "northup" : __DIR__"jifangting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
