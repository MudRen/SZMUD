// Code of ShenZhou
// ɽϪ /d/shenlong/shanxi
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽϪ");
        set("long", @LONG
��ɽϪ���У�Ϫˮ���ȣ���ľ���£��ĸ��Ŀ�������������ɽ·������
����������һ���޼ʵĴ󺣡�
LONG
        );
        set("outdoors", "shenlong");
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
        ]));

	set("cost", 5);

        set("snaketype", ({"shuishe"}));

	setup();
}

#include "/d/shenlong/snakeroom.h"

