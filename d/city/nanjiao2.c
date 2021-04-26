// Code of ShenZhou
// room: /d/city/nanjiao.c
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
            "/d/shaolin/obj/caoliao" : 3,
	]));


        set("exits", ([
                "west" : __DIR__"nanjiao1",
                "east" : __DIR__"seforest",
		"northeast" : __DIR__"dongjiao4",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

