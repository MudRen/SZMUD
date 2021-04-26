// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
ɽ��Խ��Խ���գ����������Ӳݣ���ɽ��Ҳ�����ж���Ψ��ɽҰ�ú�
��ֻ��ӥ����춿ա���������ʮ�����ң��һ�룬���������������
�۴��̣�����ͨ�롣
LONG
        );
        set("exits", ([
                "south" : __DIR__"bulang-po",
                "northwest" : __DIR__"datong-ling",
        ]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
