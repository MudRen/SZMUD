// Code of ShenZhou
//����1 /d/shenlong/zhulin1
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����һƬ��ʵ�����֣����߰�������һ��С�ľͻᱻ���µ�֦�������ͷ��
�����ƺ�����΢��ɳɳ���������Ǻ��紵���ֺ����ǳ���������������е㲻��
��������˵������ʲô��
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"zhulin1",
                "north" : __DIR__"liangongfang",
        ]));

        set("cost", 1);
        set("snaketype", ({"zsnake"}));

        setup();
}

#include "/d/shenlong/snakeroom.h";
