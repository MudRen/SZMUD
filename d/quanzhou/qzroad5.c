// Code of ShenZhou
// Room: /d/quanzhou/qzroad5.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
�����ڶ��ϵ�һɽ������ɽ�ϡ�����Ӷ��洵�������ż��ֺ��⡣
�ϱ߾��������ĺ���Ȫ���ˡ�
LONG
	);

	set("exits", ([
                "south" : __DIR__"shanlu1",
                "north" : "/d/hangzhou/road62",
	]));

        set("objects", ([
		"/d/wudang/npc/yetu" : 2 ]));

	set("outdoors", "quanzhou");
	set("cost", 3);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

