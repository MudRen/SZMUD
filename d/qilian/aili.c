// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ����ɳ��̧����ȥ����ããһƬɳĮ�����޾�ͷ��ֱ����ߣ�
һ������̤�룬��ʯţ�뺣����ʧ����Ӱ�����ˣ��ɹ����Ϊ��������
LONG
        );
        set("exits", ([
                "north" : __DIR__"aili2",
                "west" : __DIR__"aili2",
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
