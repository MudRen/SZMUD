// Code of ShenZhou
// xiaolu2.c �ּ�С��
// by Xiang
// Modified by xQin 2/00
// xQin 11/00

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", GRN"�ּ�С��"NOR);
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ����������ƺ���һ����ɽС·��
LONG
        );

        set("exits", ([
                "south" : __DIR__"zhulin",
                "northeast" : __DIR__"xiaolu1",
        ]));
/*                set("objects", ([
                CLASS_D("wudang")+"/qingfeng": 1,
                CLASS_D("wudang")+"/mingyue": 1,
        ]));
*/

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
