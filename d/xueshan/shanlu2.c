// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һɽ·�ϣ�������һ����Сɽ����ң�������Ϸ���ѩɽ
�ı�´��ɽǰ����ԼԼ������һ����Ժ��
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shanlu6",
                "westup" : __DIR__"beilu",
        ]));
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
