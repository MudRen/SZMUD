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
������������������Ӷ�����ʦ�������������Ǽ�ֵ���ƵĻ���ϱ��ǰ���
�ۣ������Ǵ��룬���ϱ����������ۡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"gangkou1",
		"southeast" : __DIR__"yongning",
		"south" : __DIR__"anhai",
		"east" : __DIR__"chuanwu",
	]));

        set("objects", ([ 
		__DIR__"npc/biaotou" : 2,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        set("fanhua", 1);
        setup();
	replace_program(ROOM);
}
