// Code of ShenZhou
// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥�����Ϻ����ĵ�һ��С���ϡ��Ϻ����겻�ϵ�ˮ������
���ֵ��������ɵġ�¥���Ǽҷ��ꡣ
LONG
	);

	set("exits", ([
                "north" : __DIR__ "nanhu1",
	]));

	set("outdoors", "quanzhou");
        set("objects", ([
            __DIR__"npc/xiaoer" : 1,
	    __DIR__"npc/hai" : 1,
	    __DIR__"npc/xiaoguizi" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

