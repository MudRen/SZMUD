// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ա���һƬ��ɳĮ�������������ɹ��ˣ������ͽ��ڸ��̲�ϡ�
������һ���Ǳ�����ɳ�У�һ������֮�鲻������������Ȼ������
LONG
        );
        set("exits", ([
                "south" : __DIR__"zhuti",
                "north" : __DIR__"gebi",
        ]));


	set("cost", 1);
        set("tjjob", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
