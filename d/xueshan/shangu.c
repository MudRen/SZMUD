// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ȿ�");
        set("long", @LONG
������ɽ��ǰ���һ��ƽ�ء���ɽ��·ʮ�ֶ��Σ����˵ػ�ʱ��
����ѩ����
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"xshan2",
                "southup" : __DIR__"shangu1",
        ]));
	switch(random(3)){
        case 1:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }

	set("cost", 2);
        set("tjjob", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
