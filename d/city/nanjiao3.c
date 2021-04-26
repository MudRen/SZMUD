// Code of ShenZhou
// room: /d/city/nanjiao3.c
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
            "/d/city/obj/stone" : 2,
            "/d/shaolin/obj/caoliao" : 1,
		"/d/wudang/npc/bee" : 2,
	]));


        set("exits", ([
                "west" : __DIR__"nanjiao4",
                "east" : __DIR__"nanmen",
        ]));
	set("outdoors","city");
	set("resource/grass", 1);
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

