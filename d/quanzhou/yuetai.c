// Code of ShenZhou
// yuetai.c ��̨�㳡
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��̨�㳡");
	set("long", @LONG
����ƽ̹�⻬��ʯ��㳡���м�͹��һ̨�棬�����һ�ٵ�¯��̨����Ƕ
����ʮ����ʨ��������ʯ��������Ũ��������ζ����������һ���ֺ��ʯ
����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"ganlu",
		"south" : __DIR__"dxbaodian",
		"east" : __DIR__"dongta",
		"west" : __DIR__"xita",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
