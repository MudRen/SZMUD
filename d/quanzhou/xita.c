// Code of ShenZhou
// xita.c ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������������붫�����ֲ����������⣬�������������ͬ��ǡ��
һ��������á������������������������Ÿ��ֻ����񡢳桢�޺�װ��ͼ����
Ҳ��������������̬���棬����һ�����á��泩�����С�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"yuetai",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
