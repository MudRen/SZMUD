// Code of ShenZhou
// Room: /d/xiangyang/damen.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����������������Ĵ��������ĸ�ۡ���������ߣ���ģ���
���ӵ��š��ɹŴ���������������������޲������䱸��������һ
·��ʯ�̵أ�ֱͨ������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating",
  "north" : __DIR__"jzjie4",
]));

	setup();
	replace_program(ROOM);
}
