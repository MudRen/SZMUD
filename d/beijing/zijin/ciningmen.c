//Cracked by Roath
// Room: /d/beijing/zijincheng/ciningmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������ţ��ſ�վ�ż���������̫�ࡣ�������߾��ǻ�
̫����޹����κ���δ�����٣��������ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cininggong",
  "south" : __DIR__"cininghuayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
