// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
�˵�����װɽ���Թ��Բ�ͭ���ƣ��ڼ�������һ�ٰ�ʮ����͸��ʣ�
����С��ʯ��������ͭ���ഫ��Ů�ϲ���ʱ���¡�ɽ��һ����·��ͨ������
LONG
        );
        set("exits", ([
                "east" : __DIR__"jiayuguan",
                "north" : __DIR__"yumenguan",
		"west" : "/d/xingxiu/silk1",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
