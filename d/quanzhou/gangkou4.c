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
������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"gangkou3",
		"south" : __DIR__"houzhu",
	]));

        set("objects", ([ 
		__DIR__"npc/tangzi" : 2,
		__DIR__"npc/xunbu" : 1,
                __DIR__"npc/kuli" : 1,
                __DIR__"npc/langren" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
