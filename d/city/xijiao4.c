// Code of ShenZhou
// room: /d/city/xijiao4.c
// Jay 7/4/96

#include <ansi.h>;
inherit ROOM;

void create()
{

        set("short", "�ݵ�");
        set("long", 
"������һ��������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һЩ
��֪����С������"+HIR"��"NOR+"�ġ�"+HIY"��"NOR+"�ģ�����"+MAG"��"NOR+"�ġ������ϡ���Ҷ�ϵ�¶�����ž�Ө�Ĺ⡣\n"
        );

        set("objects", ([
            "/d/city/obj/stone" : 2,
        ]));


        set("exits", ([
                "north" : __DIR__"xijiao3",
                "south" : __DIR__"swforest",
                "southeast" : __DIR__"nanjiao4",
        ]));
        set("outdoors","city");
        set("resource/grass", 1);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
