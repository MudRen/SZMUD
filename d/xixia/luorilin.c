// Code of ShenZhou
// Room: /d/xixia/luorilin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ�����ݵĶ�������������������ݵ��м䣬��������
�����Ǻ��ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dalu",
  "southwest" : __DIR__"dongmen",
]));
	set("cost", 2);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
