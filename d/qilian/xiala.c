// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
̧����ȥ����ããһƬɳĮ�����޾�ͷ��ֱ����ߡ����ﾡ��
��ɳʯ����û��һ���������ɹ����Ϊ������
LONG
        );
        set("exits", ([
                "east" : __DIR__"gebi",
                "southeast" : __DIR__"yongchang",
		"north" :__FILE__,
		"south" :__FILE__,
		"west" :__FILE__,
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
