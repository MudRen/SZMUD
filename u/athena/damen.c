// Room��/u/athena/damen.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIW"���ݷ��ƹ�"NOR);
        set("long", 
"����һ��ʮ��Ρ��Ľ�������ɫ�Ĵ���ʯǽ�ڣ����ص�ʵľ���ţ��ſ�������
�����������Ϲ�������֡������ݷ��ƹݡ������¼�����ݵķ��Ʊ�úͲ�ɣ��ʷ
���ŵ��Ҳ�����һ��ʯ����bei��,�ſڻ�����һλ���ˣ���˫Ŀ���񣬵��ƺ���˼
����ʲô��\n"
);
        set("no_fight",1);
        set("exits", ([
                "enter" : __DIR__"dating.c",
        ]));
        create_door("enter", "����", "out", DOOR_CLOSED);
        set("cost", 0);
 set("item_desc", ([ 
 "bei" : "����һ�����ͨ�����е�ವ��ʯ������ֵ�������û���κ��ֻ���ͼ����\n", 
])); 
setup();
}
