// Code of ShenZhou
// d/emei/tombpath.c С��
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "С��");
	set("long", @LONG
����һ�����ѵ�ɽ��С����һ��ͨ����üɽ��ɽ����һ�߲�֪ͨ�����
��һ·�˼�������ֻ��Щ��֪����С����֨֨ߴߴ���š�
LONG
	);

        set("exits", ([
                "west" : __DIR__"tomb",
		"southwest" : __DIR__"grassland",
		"northdown" : __DIR__"tombpath2",
        ]));

	set("cost", 4);
	setup();
        replace_program(ROOM);
}

