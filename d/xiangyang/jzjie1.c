// Code of ShenZhou
// Room: /d/xiangyang/jzjie1.c

inherit ROOM;

void create()
{
	set("short", "���ݽ�");
	set("long", @LONG
������������������ľ��ݽ֡���������������С�����������ּۻ�����
����˷�����Ⱥ���У���ϡ���Լ���������һ���͵ꡣ������Զ���Ǳ�������
���µ�����¥�����ŵ�������������������ɵ�ʳָ�󶯡�
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : 3, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jzjie2",
  "south" : __DIR__"dongjie2",
  "east" : __DIR__"kedian",
  "northwest" : __DIR__"yueyang",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
