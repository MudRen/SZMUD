// Code of ShenZhou
// xinmen.c ���ż�
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ż�");
	set("long", @LONG
����Ȫ�����涫�����һ���ɵ�����ģ�����ϱ��мҲ�ӣ�����������
���ţ����������м���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"xmqiao",
		"east" : __DIR__"jishi",
		"south" : __DIR__"taoran",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
