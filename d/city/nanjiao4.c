// Code of ShenZhou
// room: /d/city/nanjiao4.c
// Jay 7/4/96

inherit ROOM;

void create()
{

        set("short", "�ݵ�");
        set("long", @LONG
������һ��������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һЩ
��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�¶�����ž�Ө�Ĺ⡣
LONG
        );

        set("objects", ([
            "/d/city/obj/stone" : 2,
		"/d/wudang/npc/yetu" : 1,
	]));


        set("exits", ([
                "northwest" : __DIR__"xijiao4",
                "east" : __DIR__"nanjiao3",
		"west" : __DIR__"swforest",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

