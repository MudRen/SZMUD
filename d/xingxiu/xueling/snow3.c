// Code of ShenZhou
// Ssy

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"ѩ��"NOR);
        set("long", @LONG
����羰�ĺã�ɽ�����ߣ�ԭ���������ֵط�����Ӧ���˵���  
����������ȴ������һ��ɽׯ����֪��ʲô���ڡ�
LONG
        );
        set("exits", ([
                "southdown" : __DIR__"snow2",
                "east" : __DIR__"gate",
        ]));
        set("cost", 1);
        set("outdoors", "tianshan");
        setup();
}
