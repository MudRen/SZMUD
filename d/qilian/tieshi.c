// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ʯɽ");
        set("long", @LONG
����������ɽ������ʮ�ﴦ��ɽ����ף�ͨɽһɫ��ڣ���ͺͺ��û
��һ����������ɽ�����ʯ����ɫ��ī�����ճ�����������������������
�����ߣ��ͽ��뱱����ɽ���ˡ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"zibai",
                "northwest" : __DIR__"ailao",
		"east" : __DIR__"qilian",
        ]));
	set("objects", ([
		__DIR__"obj/iron" : 2
	]));


	set("cost", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
