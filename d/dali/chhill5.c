// Code of ShenZhou
// /d/dali/chhill5.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�軨ɽ��");
        set("long", @LONG
����ǲ軨ɽ�����棬��Ȼ�д����Ĳ軨ʢ���š�����Ȼ����ɽ�ϵ�
Ʒ�ֺ��ˣ����Ƿ�Ʒ��
LONG
        );

        set("exits", ([
                "westup" : __DIR__"chhill3.c",
                "southeast" : __DIR__"shilin6.c",
        ]));

        set("cost", 2);
        set("fengamount", 3 + random(3));
        set("outdoors", "dali");
        setup();
        replace_program(ROOM);
}
