// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ݺ͹����м䣬������ˮ������������ˮ�ļ����Ӵ���������ĳߣ�
խ��Ҳ�������࣬�ɴ��ѹ����ഫ�ں���ʱ������һλ���մ������������֮
�����鼯�ɽ����Ѿ���˽���������š��������ݣ����ȹ����š�
LONG
        );
        set("exits", ([
                "east" : __DIR__"gulang",
                "southwest" : __DIR__"lanzhou-beimen",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
