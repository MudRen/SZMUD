// Code of ShenZhou
// room: bshantan.c ��ˮ��̶

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ˮ��̶");
        set("long", @LONG
�˴�ֻ��һ����̶��̶ˮ�ʱ���ɫ����ش�ɽ�������걱��ι���ֻ
��̶��һվ����Ȼ�������ˡ�����̶ˮ���ѽ�ɺ����ֻ�м����˹���ȥ
��ȱ�ڣ�����ȥ�̳����أ�����ס�
LONG );

        set("exits", ([
		"east" : __DIR__"shanquan",
        ]));
        set("outdoors", "mingjiao" );
	set("cost", 3);

        setup();
        replace_program(ROOM);
}