// Code of ShenZhou
// Room: /d/shaolin/zhulin1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ������������
�ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ������
΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ���
���������ڡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"hsyuan1",
		"north" : __DIR__"zhulin2",
		"south" : __DIR__"zoulang8",
	]));

	set("outdoors", "shaolin");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



