// Code of ShenZhou
// shijiefu.c �в�˾
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�в�˾");
	set("long", @LONG
���Ǹ���Ӵ�����ʹ�ڼ��ﱸ���������Ҫ�����ĵط����ſ��������߸�
��һ����ʯʨ�ӣ���̬�ý�������ߺ�������ͨ��˳���ţ����ϱ�ͨ���ۿ�
·�����ߵĽֵ���ͷ����Ϳ�ż���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"jiedao2",
		"northwest" : __DIR__"sjqiao",
		"southwest" : __DIR__"gangkou1",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "quanzhou");
        set("fanhua", 2);

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
