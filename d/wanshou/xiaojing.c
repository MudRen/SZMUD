// Code of ShenZhou
// /d/wanshou/xiaojing.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
һ����ʯ�̳ɵ�С�������쵽ǰ�治Զ��һ���������Ƶ�ɽ��
�£�ɽ�Ż�����һƬ���֣�ɽ����������ӳ������¶�����ܵ�һ�ǣ�
�·����˾�ס��
LONG
        );
        set("exits", ([
				"north" : __DIR__"shanjiao",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
