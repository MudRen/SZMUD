// Code of ShenZhou
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "������");
	set("long", @LONG
��·�������������������һƬ����ľ������Խ��ïʢ���Ϸ�
�ľ������������ա�
LONG
	);

	set("exits", ([
		"north" : __DIR__"huyang3",
		"south" : __DIR__"shule",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

