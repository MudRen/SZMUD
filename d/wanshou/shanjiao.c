// Code of ShenZhou
// /d/wanshou/shanjiao.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ����");
        set("long", @LONG
��ʯС����������ж��ˣ���ǰ��һƬ��ɭ�����֣������
��������Գ�仢Х֮�������˲�����������ֻС�������ֱ���Ϸ�ţ�
�������˵�����ವ�һ�´ܽ����в����ˡ�
LONG
        );
        set("exits", ([
				"south" : __DIR__"xiaojing",
                "northup" : __DIR__"forest0",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
