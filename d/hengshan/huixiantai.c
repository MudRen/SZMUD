// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
�߳���������ܿ���һ��ʯ�ߣ������ھ����������һ��С
�ң����ǻ���̨��̨������Ⱥ�ɵ����������飬����ʤ����
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastdown"  : __DIR__"beiyuedian",
        ]));
		set("cost", 2);
        setup();
        replace_program(ROOM);
}

