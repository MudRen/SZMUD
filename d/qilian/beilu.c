// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽ��´");
        set("long", @LONG
����ɽ�Ʊȴ�ѩɽ�����Ի���Ҳ����ʮ�ֵ��Ϻ���ɽ����
�Գ�����ϡϡ������һЩҰ�ݡ����º����˼���ֻ�м�ֻͺӥ
�ڸߴ�������������ããѩɽ��
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shanlu2",
                "south" : __DIR__"dshanlu",
        ]));
	set("objects", ([
 "/d/qilian/npc/hua" : 1, 
        ]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
