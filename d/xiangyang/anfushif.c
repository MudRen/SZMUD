// Code of ShenZhou
// Room: /d/xiangyang/anfushifu.c

inherit ROOM;

void create()
{
	set("short", "����ʹ��");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ��ΰ�ߴ��ʯʨ����ס�˴���
���ࡣ�Ŷ���������һ�����ң�д�š�����ʹ�����ĸ����֡������в��ٹٱ���
���ţ��䱸ɭ�ϡ����Ϲ�����յ��������Ȼд�š������֡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"xiansi",
  "north" : __DIR__"dongjie1",
]));

	setup();
	replace_program(ROOM);
}
