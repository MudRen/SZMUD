// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
����ǰͻȻһ�����˴���������أ���֪���ߴӺ�͸�룬������
���칤������һ�����µ�Ժ�䣬�����ɶ���ʯ�̳ɣ��Ĵ��������滨
��ݣ���������ʹ���Ҳ�ټ��ġ���������һ����ɽ��Ժ���������
��һ�ھ���well������ʱ��Ʈ���������������������ѡ���������
����̵������á�
LONG
        );
        set("exits", ([
                "out" : __DIR__"rukou1",
		"west" : __DIR__"zhengtang",
                "north" : __DIR__"datang",
        ]));
	set("item_desc", ([
                "well" : "����д�ţ�������Ȫ����\n"
        ]));
	set("resource/water", 1);
	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
