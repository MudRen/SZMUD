// Code of ShenZhou
// /d/wanshou/qianting.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽׯǰ��");
        set("long", @LONG
����ɽׯ���ű���ǰ����ǰ���������ǽ���������ž޷�ˮ
ī��������Գ�������������а���һ��̫ʦ�Σ���������ɽׯ��
ׯ��--������Գʷ�Ͻݡ��������������ȣ���ͨ���ã���������
����ǰ���ڹ�ȥ����������
LONG
        );
        set("exits", ([
				"north" : __DIR__"zhenting",
				"south" : __DIR__"frontgate",
				"east" : __DIR__"liangongfang",
				"west" : __DIR__"kitchen",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
