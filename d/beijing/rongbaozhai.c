//Cracked by Roath
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ٱ�ի");
    set("long", @LONG
�����Ǿ��������������ֻ��ꡣ���������ϰ����ʶ�㣬�ղص��ֻ�Ҳ�Ĳ�
�٣����˵����������ֱʣ���ʱ����Щ���ֻ�����Ʒ������Ҳ����һЩ��īֽ��
֮��ġ�
LONG
	);

    set("exits", ([
        "northeast" : __DIR__"changanjie_e",
    ]));

    set("objects", ([
	__DIR__"npc/liulaoban":1,
    ]));

    setup();
}
