// Code of ShenZhou

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ɽ�����ǿ����а˾�������м�͸��һ����⣬�����촰һ�㡣
���з���һ��ʯ�������¶ѷ��ż������룬һ���������ڶ��Ľ��䴦�������
����Ʒ��Ȼ��׾����Ҳ�뱸��
LONG
        );
        set("exits", ([
                "out" : __DIR__"icefire3",
        ]));


        set("resource/water", 1);
        set("objects", ([
		"/d/island/npc/xiexun" : 1,
	]) );

	set("outdoors", "island");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

