// Code of ShenZhou
// Room: /d/heimuya/shuitan1.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit FERRY;

void create()
{
        object room;

        set("short", HIC"ˮ̲�ϰ�"NOR);
        set("long", @LONG
ǰ����һ��ˮ̲��ˮ���ļ���ˮ̲(river)�ν���
ʯ���ľ�ͷ������ͣ�����м���С����
LONG
    );

        set("exits", ([
                "south" : __DIR__"stonechannel2",
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
