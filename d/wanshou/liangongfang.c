// Code of ShenZhou
// /d/wanshou/liangongfang.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ɽׯ��������֮���������һ����ű����ܣ�������Ÿ�
�ֱ���������С�������Ȼ���ʲô���д������ա�
LONG
        );
        set("exits", ([
				"west" : __DIR__"qianting",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
