// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������ľ����������ǡ�һ���³�������ãã��Ұ֮�ϡ��˳�
���ں�������䣬���Ŵ󽫾���ȥ�����ڴ��������꣬��һ��ƽ����������
�������������ﶼ�о��ӳ�פ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"kedian",
		"east" : "/d/huanghe/huanghe3",
                "north" : __DIR__"gulang",
		"southup" : __DIR__"liupan",
        ]));

	set("objects", ([
		"/d/xingxiu/npc/wujiang" : 1,
		"/d/xingxiu/npc/bing" : 3,
	]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
