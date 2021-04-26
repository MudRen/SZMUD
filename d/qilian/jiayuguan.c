// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���ǳ��������Ĺذ������²�ɣ�����ڲ�ס���ķ�ɡ�Ⱥɽ����֮��������
���ۻ롣�������򰲶�������ս�£��߹��ؾ��Ѵ�Ϊ���١�һ�����������ͨ
����ԭ���������������˵�ɽ�����������ġ�˿��֮·����
LONG
        );
        set("exits", ([
                "west" : __DIR__"danshan",
                "northeast" : __DIR__"yumen",
                "east" : __DIR__"tanglang",
		"southwest" : __DIR__"shalu",
        ]));

        set("objects", ([
		"/d/xingxiu/npc/wujiang" : 1,
		"/d/xingxiu/npc/bing" : 1,
	]));
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
