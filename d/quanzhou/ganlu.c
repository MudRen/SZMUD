// Code of ShenZhou
// ganlu.c ��¶��̳
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��¶��̳");
	set("long", @LONG
�Ӵ����ų������������ܰ˽��ܼ�ʽ�Ľ�̳���Ƿ��ͽ�ܽ����֮����
̳���弶����߲��з�ľ���¬������������������ͼ�Ĳ��𡢰�����
��ǧ��ǧ�۹�����ȡ�̳�����С�����𧡹�͡�����䡹����������λ��ʮ
����������ׯ�ϡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northup" : __DIR__"cangjing",
		"south" : __DIR__"yuetai",
	]));

        set("objects", ([ 
		__DIR__"npc/huijin" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
