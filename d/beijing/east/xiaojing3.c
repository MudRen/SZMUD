//Cracked by Roath
// Room: /d/beijing/east/xiaojing3.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
��������һ��ʯ��·�ϣ�·�Թ������죬���ݴ��к����׷ɣ�
��ʱ�����Կ�����ֻС�޴��Ա��ܹ��������߾ͽ��Ͻ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaojing2",
  "northup" : __DIR__"guanmiaoting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
