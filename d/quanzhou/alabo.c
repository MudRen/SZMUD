// Code of ShenZhou
// alabo.c ������լ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������լ��");
	set("long", @LONG
����Ȫ�����������ó��������ఢ�����������˵ؾ�ס���������ö���
֮�γ�����۾ӵء�ԶԶ��ȥ��ɫ��Բ�μⶥͻأ�����Եø������ۡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"citong_s2",
		"south" : __DIR__"qingjing",
	]));

        set("objects", ([ 
		__DIR__"npc/trader" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
