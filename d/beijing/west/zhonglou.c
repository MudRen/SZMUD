//Cracked by Roath
// Room: /d/beijing/west/zhonglou.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
��������¥�߾������࣬��ȫשʯ�ṹ������Ԫ����Ԫ��
�䡣��¥�ϵĴ�ͭ��һ�������죬�ͻ������һ�������������
��˵����һ�������������������˵��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"gulou",
  "west" : __DIR__"guloudajie",
  "east" : "/d/beijing/east/zhongtianlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
