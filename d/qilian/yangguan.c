// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�������ݳ�����������ݣ�����ȫ�Ǵӳ����ԭ��������
����ɱ�Ļ����������ۡ����������Ŀ��̣����˵ش�⣬�޲�
������������ʡ����в��ٸ�����Ժ�����ﵽ���͵�ȡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"weststreet",
        ]));
	set("objects", ([
                __DIR__"npc/xiaoer2": 1,
	]));
	set("cost", 1);
        setup();
        replace_program(ROOM);
}    
