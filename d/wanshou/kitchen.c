// Code of ShenZhou
// /d/wanshou/kitchen.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ɽׯ�����ò�֮�����������еĳ������ô���װ�Ÿ���
ɽ��Ұζ��һ�ǵ�һ��С������ţƤ����װ����ϡ�ı��鹩ɽׯ��
�����á�
LONG
        );
        set("exits", ([
				"east" : __DIR__"qianting",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
