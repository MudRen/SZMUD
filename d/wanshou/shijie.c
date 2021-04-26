// Code of ShenZhou
// /d/wanshou/shijie.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����ǰͻȻһ����ԭ�����Ѿ��߳��˴�ɭ�֣�̤��һ������
���ϵ���ʯ�ס�ʯ��������Ȼ�������деز�������ľ�����Ѿ���
�󷽲�������������ɭ�ֲ�����ͷ��ȥ��ɽ���ϰ�ǽ����һ��ɽׯ
һ�������ɼ���
LONG
        );
        set("exits", ([
				"north" : __DIR__"frontgate",
				"south" : __DIR__"forest0",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
