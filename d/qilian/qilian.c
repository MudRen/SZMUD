// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����ɽΪ������ɽ������߷壬������ǧ���ٶ��ף�ɽ��ͦ�Σ�Ϊ�������
Ȫ�����������˵ĵ�һɽ��ɽҰ������ʯ��Ϊ����һ����ۣ��붫�Ϸ�����ɽң
�ԡ�ɽ�о���ʱ�����˾�ʯ����.
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"niaoju",
                "east" : __DIR__"mazong",
		"west" : __DIR__"tieshi",
        ]));


	set("cost", 3);
        set("tjjob", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
