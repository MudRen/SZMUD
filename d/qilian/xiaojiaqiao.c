// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ݺ͹����м䣬������ˮ������������ˮ�ļ����Ӵ���������ĳߣ�
խ�������࣬�ȴ��ѹ����ഫ����䣬����һλ���մ������������֮������
���ɽ����Ѿ���˽���������ţ��������ݣ����ȶȱ��š�
LONG
        );
        set("exits", ([
                "east" : __DIR__"gulang",
                "southwest" : __DIR__"lanzhou-beimen",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
