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
���������ݳǵĶ��š�
LONG
        );

        set("objects", ([
            "/d/city/obj/stone" : 1,
	]));


        set("exits", ([
                "north" : __DIR__"dongmen",
                "south" : __DIR__"dongjiao4",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

