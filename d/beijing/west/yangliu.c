//Cracked by Roath
// Room: /d/beijing/west/yangliu.c

inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
���Ǳ�������һ��ƽ����С��ͬ����Ϊ��ͬ������������������
�������Ϊ������ͬ����ͬ����������լ�ӣ�����ƺ��в��ٲ����
�������˳���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baidamen",
  "south" : __DIR__"xidan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
