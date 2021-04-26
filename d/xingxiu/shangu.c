// Code of ShenZhou
// Room: /d/xingxiu/shangu.c
// Date: June 30, 96   Jay

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ�����ܶ��Ƕ��͵ľ��ڣ�����ϡ��س���Щ��С�Ĺ�ľ����
��ĵ����м����㼣������ʯ����һ���ѷ�ͨ��һ��ɽ����
LONG
	);

	set("exits", ([
                "northup" : __DIR__"tianroad6",
		"northwest" : __DIR__"gcdoor",
	]));
	set("objects", ([
                "/d/qilian/npc/tuying": 2,
        ]));
	set("outdoors", "xingxiu");
	set("cost", 3);
	set("bing_can", 5);
	setup();
	replace_program(ROOM);
}

