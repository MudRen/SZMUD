// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ȫ");
        set("long", @LONG
�ഫ������Ǻ��󽫾���ȥ������¥��������֮�أ���������ƶ�ʮ
ƿ�������̶���������ʮȪ�ڣ������������������Ծ�Ȫ֮ˮ��ƣ���
�ɿڡ�
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"shalu1",
                "southwest" : __DIR__"loulan",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
