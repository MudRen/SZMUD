// Code of ShenZhou
// room: /d/city/dongjiao4.c
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
            "/d/quanzhou/npc/wuya" : 1,
		"/d/emei/obj/flower" : 1,
	]));


        set("exits", ([
                "north" : __DIR__"dongjiao3",
                "south" : __DIR__"seforest",
		"southwest" : __DIR__"nanjiao2",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

