//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���ƶ�");
        set("long", 
"��Ȫ�����ϱ��ǳ��ƶ��������庮�����ɲ⣬ÿ��
�賿���ƻ�ʱ�֣������������������������£����Ƴ��룬��
��Զ�������ġ�������Ѩ����\n"
        );
        set("exits", ([
                "westdown"  : __DIR__"longquanguan",
                "northup"  : __DIR__"hufengkou",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

