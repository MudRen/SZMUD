// Code of ShenZhou
// room: /d/city/xijiao2.c
// Jay 7/4/96

#include <ansi.h>;
inherit ROOM;

void create()
{

        set("short", HIG"�ݵ�"NOR);
        set("long", 
"������һ���������"+HIG"�ݵ�"NOR+"������һ����ɫ��̺�����ڵ��ϡ��ݴ��п���һЩ
��֪����С������"+HIR"��"NOR+"�ġ�"+HIY"��"NOR+"�ģ�����"+MAG"��"NOR+"�ġ������ϡ���Ҷ�ϵ�"+HIC"¶��"NOR+"���ž�Ө�Ĺ⡣
���������ݳǵ����š�\n"
        );

        set("objects", ([
            "/d/city/obj/stone" : 1,
            "/d/wudang/npc/bee" : 1,
        ]));


        set("exits", ([
                "north" : __DIR__"nwforest",
                "south" : __DIR__"xijiao1",
                "northeast" : __DIR__"beijiao4",
        ]));
        set("outdoors","city");
        set("resource/grass", 1);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
