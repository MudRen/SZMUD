// Code of ShenZhou
// xilang2.c ��������
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ���ľ��������ϣ�������һ����¥���������䵱���ӵ�������
���ڣ���ʱ����������������������
LONG
	);

	set("exits", ([
		"northup" : __DIR__"cangjingge",
		"east" : __DIR__"xilang1",
		"south" : __DIR__"liangongfang2",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

