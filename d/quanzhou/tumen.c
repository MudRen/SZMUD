// Code of ShenZhou
// tumen.c Ϳ�ż�
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Ϳ�ż�");
	set("long", @LONG
����Ȫ�����涫�����һ���ɵ�����ģ�����ϱ���Ȫ�������ĺ�����
ׯ�������Ǹ����У����߱���ȥ���ۿڵ���Ҫͨ����Ϳ��ˮ�ء���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"qingjing",
		"south" : __DIR__"jiedao1",
		"east" : __DIR__"shuiguan",
		"west" : __DIR__"jishi",
	]));

        set("objects", ([ 
        ]));
        set("fanhua", 1);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
