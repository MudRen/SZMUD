//Cracked by Roath
// Room: /d/beijing/zijincheng/longzong.c

inherit ROOM;

void create()
{
	set("short", "¡����");
	set("long", @LONG
����ǿ����ʵ�ס�����ĵ�;�������һ����Ҫ���š������¡�
��ּ���ټ��Ĺ�Ա׼��ͨ���⣬�������಻�������롣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cininggong",
  "east" : __DIR__"xiaohuayuan",
]));

	setup();
	replace_program(ROOM);
}
