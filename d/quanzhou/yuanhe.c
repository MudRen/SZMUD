// Code of ShenZhou
// yuanhe.c Դ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Դ����");
	set("long", @LONG
����Զ���������۽������̣���ɫˮ���������ǵļӹ����ζ���أ����
���壬�̶������������ɬ���ֿ��Գ��ڱ��棬Զ�������⡣
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"minzai2",
		"east" : __DIR__"minzai3",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
