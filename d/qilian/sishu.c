// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
һ���ª��˽�ӣ��ıڽԿգ������а�����ѧ�����Լ�����̧���ķ�
�������ʡ�һ���鰸�������ӵ�һͷ�����ϰ��ż��������˵ġ����־�����
���ټ��ա���һ�ѽ�ߡ���ʥ��ʦ���Ϸ��ӵ�ʯ����Ƭ�����������鰸��
���档
LONG
        );
        set("exits", ([
                "south" : __DIR__"gulang",
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
