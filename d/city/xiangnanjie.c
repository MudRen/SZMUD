// Code of ShenZhou
// Room: /city/xiangnanjie.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "���Ͻ�");
	set("long", @LONG
������һ�ҵ��̣�����ǽ�Ϲ���һ���ɫ�����ƣ�����д�š����̡�������
ɫ���֡�һ������ɿ�������ϰ�����Χ�������һ�ҵ��̸������¡���������
һ��С·���򱱾Ϳ��Խ��������סլ�������������ݲ�Ʊ���ˡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"west" : __DIR__"dongnanjie",
		"south" : __DIR__"mipu",
                "east" : "/kungfu/class/movie/caipiaohang",
		"north" : __DIR__ "minwu1",
		"northeast" : __DIR__ "xiaotulu",
	]));

        set("objects", ([
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

