// Code of ShenZhou
// Room: /city/datiepu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬
��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���������������
ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG
	);

	set("exits", ([
		"south" : __DIR__"xmqiao",
	]));

	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
	]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if( present("tie jiang", me) )
                return notify_fail("����մ�������ʲô���۸���ʵ�˰���\n");

        return ::valid_leave(me, dir);
}

