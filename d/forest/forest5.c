// Code of ShenZhou
// room: /d/city/forest1.c
// Jay 7/9/96

#include "tree.h"
 
void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"forest4",
		"west" : __DIR__"forest6",
		"northeast" : __DIR__"field1",
              //  "north" : "/d/taohuacun/taohua1",
        ]));

	set("objects", ([
		__DIR__"npc/mulang" : 1,
	]));

	set("climbup",__DIR__"tree11");

	set("cost", 3);
        setup();
}

