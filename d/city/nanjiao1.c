// Code of ShenZhou
// room: /d/city/nanjiao1.c
// Jay 7/4/96

inherit ROOM;

void create()
{

        set("short", "�ݵ�");
        set("long", @LONG
������һ��������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һЩ
��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�¶�����ž�Ө�Ĺ⡣
���������ݳǵ����š�
LONG
        );

        set("objects", ([
            "/d/city/obj/stone" : 3,
		"/d/emei/obj/flower" : 1,
            "/d/shaolin/obj/caoliao" : 2,
	]));


        set("exits", ([
                "east" : __DIR__"nanjiao2",
                "west" : __DIR__"nanmen",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

