// Code of ShenZhou
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG
�ɴ˱��ϱ�����ɽѩ�룬�ഫ�в���;���˴�����ѩ��������
��������Ϊʯ��һ����ʵ���ϴ��������칤���ɣ����������������
�ġ�������ֻ��һƬçç����֪�ܷ����ǰ�С�
LONG
        );
        set("exits", ([
                "southdown" : "/d/xingxiu/tianchi",
                "northup" : __DIR__"snow1",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northup") {
                me->add("jing", -30);
                me->add("jingli", -30);
		message_vision(HIR"$N����ðѩ��Ŭ�������ʵǡ�\n"NOR, me);

        }
        return 1;
}


