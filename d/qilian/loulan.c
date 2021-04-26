// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "¥������");
        set("long", @LONG
����¥������������أ��޵�����¥���ǡ�����¥����ֹͣ�򺺳���
�������ǲ��ȥ��ƽ֮����ʱ�������࣬����¥��֮������ͳ���һ��
���ǡ���������꣬¥���Ǿ���ʧ�ˡ��ݴ�����ɳ�£���֪�Ƿ���ʵ��
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"sulee",
                "northeast" : __DIR__"jiuquan",
		"west" : "/d/qilian/yueerquan",
        ]));
	set("objects", ([
		"/d/xingxiu/npc/shachong" : 2,
	]));

	set("cost", 3);
        set("tjjob", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
