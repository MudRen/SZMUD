// Code of ShenZhou
// ������
// Dong  11/03/1996.

#include <ansi.h>
#include <room.h>

#define BANGZHU "/d/huanghe/npc/bangzhu"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������̬����ͦ�Σ�������С��ȴ�����˼��ߵ�������˵��
Խ��Ǯ��������뾩������δ������������ˬΪףԭ��ƽ��������
������������������������������ɽ��·��
LONG  );

        set("objects",([
		BANGZHU : 1,
        ]));

        set("exits", ([ /* sizeof() == 1 */ 
                  "southdown" : __DIR__"baoshi1", 
                ])
        );

	set("cost", 3);
        set("outdoors", "hangzhou");

        setup();

        replace_program(ROOM);
}
