//Cracked by Roath
// Room: /d/beijing/east/xiaojing2.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
��������һ��ʯ��·�ϣ�·�Թ������죬���ݴ��к����׷ɣ�
��ʱ�����Կ�����ֻС�޴��Ա��ܹ��������߾ͽ��Ͻ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xiaojing1",
  "south" : "/d/beijing/zijin/shenwumen",
  "east" : __DIR__"xiaojing3",
  "northup" : __DIR__"shandao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
