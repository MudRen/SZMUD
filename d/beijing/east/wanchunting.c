//Cracked by Roath
// Room: /d/beijing/east/wanchunting.c

inherit ROOM;

void create()
{
	set("short", "��ͤ");
	set("long", @LONG
������ȫ��������ߵ㡣���Ͽ��Ը�������Ͻ��ǣ��򱱿�
�Կ�����¥�͹�¥��ͤ������һ��ʯ��������ʯ�ʣ���������Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"shandao4",
  "southdown" : __DIR__"shandao3",
  "northdown" : __DIR__"shandao1",
  "southwest" : __DIR__"shandao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
