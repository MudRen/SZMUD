// Code of ShenZhou
// gangkou1.c �ۿ�·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ۿ�·");
	set("long", @LONG
�����ô�黨��ʯ�̳ɵĿ������ƽ̹��ʵ��·���������ų��صĻ�
������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ���������Ǻ�
�⽻ͨʹ�ڸ������߽���˳���š�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"sjqiao",
		"southeast" : __DIR__"gangkou2",
		"northeast" : __DIR__"shijiefu",
	]));

        set("objects", ([ 
		__DIR__"npc/biaotou" : 1,
		__DIR__"npc/tangzi" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");
        set("fanhua", 2);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
