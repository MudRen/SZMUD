// Code of ShenZhou
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"ѩ��"NOR);
        set("long", @LONG
����������㼫Ŀ��ȥ��Ψ��һƬ��ãã�Ĵ�ѩ���㲻������һ
˿���⡣    
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"snow1",
                "northup" : __DIR__"snow3",
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
		message_vision(HIR"ͻȻ���С�˺ܶ࣬$N�������ܣ������Լ��Ѿ�������ɽѩ��ĵ߷塣\n"NOR, me);

        }
        return 1;
}
