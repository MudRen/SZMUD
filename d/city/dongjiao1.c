// Code of ShenZhou
// room: /d/city/dongjiao1.c
// Jay 7/4/96

inherit ROOM;

void create()
{

        set("short", "�ݵ�");
        set("long", @LONG
������һ��������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һЩ
��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�¶�����ž�Ө�Ĺ⡣
������һƬ���֡�
LONG
        );

        set("objects", ([
            "/d/city/obj/stone" : 2,
		"/d/xingxiu/npc/snake" : 1,
		__DIR__"npc/obj/juhua" : 1,
		"/d/emei/obj/flower" : 2,
	]));


        set("exits", ([
                "north" : __DIR__"dongjiao2",
                "south" : "/d/gaibang/ml1",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

