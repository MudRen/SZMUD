// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���Ź�");
        set("long", @LONG
���Ǵ�����������һ���ذ����������Źأ�������������ľ����Ϊ��
�۵ĺ��ˣ���Ȱ������һ���ƣ����������޹��ˡ���������ȥ���˾Ͳ����ˡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"halahu",
                "south" : __DIR__"danshan",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
