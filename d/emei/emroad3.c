// Code of ShenZhou
// emroad3.c С·
// Xbc: 96/10/02

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������Ĵ��������������Ľ��磬�׳������ܡ�С��·����������������
��ũ������ֻţ�����ڳԲݡ�·�����˺��٣����ҴҸ�·��
LONG
        );
        set("exits", ([
		"east" : __DIR__"emroad4",
                "southwest" : __DIR__"emroad2",
		"southeast" : "/d/wudang/wdroad6",
        ]));

        set("objects", ([
                __DIR__"npc/cow": 1,
	]) );

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

