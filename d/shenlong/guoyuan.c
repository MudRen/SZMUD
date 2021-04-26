// Code of ShenZhou
// /d/shenlong/guoyuan.c
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
����һƬ��԰���ֵ���һЩˮ������ƻ������ͷ��ɽ�ꡢ���ӡ����ӡ�÷
�ӵȣ��е��ѵ����ջ�ʱ�ڣ�֦ͷ�ѱ���ʵѹ�������������ģ���һ��֦ͷ
һ��һ���ģ����˿���ֱ����ˮ�����桢�����ƺ�����ũ�������ɽ�𣬶�
����һ��ɽ�ڡ�
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"shanqiu",
        ]));
        set("objects", ([
            "/d/shenlong/obj/apple" : 2 + random(8),
        ]));
        set("cost", 3);
        set("snaketype", ({"jinhuan"}));
        setup();
}

#include "/d/shenlong/snakeroom.h";
