// Code of ShenZhou
//ʯ��· /d/shenlong/shibanlu
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ��·");
        set("long", @LONG
һ���ľ�����ʯ��·��һͷͨ�������һͷͨ�����֣�·�Է��ż��軨
�ܣ����žջ���Ǿޱ�ȣ�ɷ���������������ɸ��ӣ������ǻ﷿��
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
                "south" : __DIR__"xianfuju",
                "north" : __DIR__"huofang",
                "west" : __DIR__"dating",
                "east" : __DIR__"zhulin1",
        ]));

        set("cost", 1);

        setup();
        replace_program(ROOM);
}
