// Code of ShenZhou
// Room: /d/heimuya/shuitan2.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit FERRY;

void create()
{
        object room;

        set("short", HIC"ˮ̲����"NOR);
        set("long", @LONG
ǰ����һ��ˮ̲��ˮ���ļ����԰���ɽ����ˮ̲ǰ
����һ����ɽ������ͣ�����м���С���������м�����
�½̽������ܰ��ء�
LONG
    );

        set("exits", ([
                "eastup" : __DIR__"hillroad1",
        ]));

        set("item_desc", ([
                "river" : "Ҳ��(yell)һ����ˮ̲�Ĵ��Ҿ���������\n",
        ]));

        set("resource/water", 1);
        set("outdoors", "heimuya");
        set("cost", 2);

        set("name", "��");
        set("boat", __DIR__"xiaochuan");
        set("opposite", __DIR__"shuitan2");
    
        setup();
}
