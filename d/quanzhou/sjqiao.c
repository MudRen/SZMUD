// Code of ShenZhou
// sjqiao.c ˳����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "˳����");
	set("long", @LONG
���Ǻ����ӵ�һ��ʯ���š��ſ�ˮ�ˮ½��ͨ��ݣ�����ȥ��Ψһ��
�ڡ�һ�ӹٱ�פ�������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"hjting",
		"south" : __DIR__"gangkou1",
		"southeast" : __DIR__"shijiefu",
	]));

        set("objects", ([ 
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
