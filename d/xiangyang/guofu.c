// Code of ShenZhou
// Room: /d/xiangyang/guofu.c

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
	set("outdoors", "xiangyang");
        set("coordinates", ([ "x" : 3, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jzjie4",
  "enter" : __DIR__"dating",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
