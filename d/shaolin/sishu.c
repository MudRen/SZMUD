// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
һ����ӵ�˽�ӣ����������һЩ���Σ�ǽ�Ϲ�����ʥ��ʦ�׷�
����һ���鰸�������ӵ�һͷ�����ϰ��ż��������˵ġ����־�����
���ټ��ա���һ�ѽ�ߡ�
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"nanyang",
        ]));
	set("objects",([
                "/d/city/npc/xiucai" : 1,
        ]));

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        me->set_temp("mark/��", 0);
        return 1;
}
