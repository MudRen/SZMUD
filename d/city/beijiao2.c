// Code of ShenZhou
// room: /d/city/beijiao2.c
// Jay 7/4/96

#include <ansi.h>;
inherit ROOM;
void create()
{

        set("short", "�ݵ�");
        set("long", 
"������һ���������"+HIG"�ݵ�"NOR+"������һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һЩ
��֪����С������"+HIR"��"NOR+"�ġ�"+HIY"��"NOR+"�ģ�����"+MAG"��"NOR+"�ġ������ϡ���Ҷ�ϵ�"+HIC"¶��"NOR+"���ž�Ө�Ĺ⡣\n"
        );

        set("objects", ([
            "/d/city/obj/stone" : 1,
        ]));


        set("exits", ([
                "east" : __DIR__"neforest",
                "west" : __DIR__"beijiao1",
                "southeast" : __DIR__"dongjiao2",
        ]));
        set("outdoors","city");
        set("resource/grass", 1);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
