// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����ɽ״��������ɽ���೤��ɽ��᯲�룬����Ұ��֮�ס��������ǽ���
���ĳ϶�����ɽ�ߣ��ɵñ��ض��飬����Ϊ�����ʽ�ɽ�ߣ�����������
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"niaoju",
                "west" : __DIR__"qilian",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
