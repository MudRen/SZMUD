//Filename: /d/jueqing/houtang.c ����
//Code by Jiuer (08/15/2001)

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
������ˮ��ׯ�ĺ��ã�ӭ��ǽ�����빩�����㰸������������æµ
�ţ������Ҷ�����ͷ�ܽ����������Ǳ�����ԼԼ����һ����ĸ�����
������������
LONG);

	set("exits", ([
		"east" : __DIR__"changlang5",
		"west" : __DIR__"changlang4",
		"south" : __DIR__"dating",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}