//Cracked by Roath
// Room: /d/beijing/kangqin/xiaotang.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����������ֳ�ʪ�����ȱߴ���һ����̨����������
�ײ����⡣ǰ����һ���η��������ﲻʱ����������
�ص�������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"shiwu",
  "south" : __DIR__"laofang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
