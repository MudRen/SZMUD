// Code of ShenZhou
// room: /d/city/xijiao1.c
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
            "/d/city/obj/stone" : 1,
		"/d/emei/obj/flower" : 1,
	]));


        set("exits", ([
                "north" : __DIR__"neforest",
                "south" : __DIR__"dongjiao1",
		"northwest" : __DIR__"beijiao2",
        ]));
	set("outdoors","city");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

