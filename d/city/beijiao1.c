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
��֪����С������"+HIR"��"NOR+"�ġ�"+HIY"�Ƶ�"NOR+"������"+MAG"��"NOR+"�ġ������ϡ���Ҷ�ϵ�"+HIC"¶��"NOR+"���ž�Ө�Ĺ⡣
���������ݳǵı��š�\n"
        );

        set("objects", ([
            "/d/city/obj/stone" : 2,
            "/d/emei/obj/flower" : 1,
        ]));


        set("exits", ([
                "east" : __DIR__"beijiao2",
                "west" : __DIR__"beimen",
        ]));
        set("outdoors","city");
        set("resource/grass", 1);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
