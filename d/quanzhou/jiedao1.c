// Code of ShenZhou
// jiedao1.c �ֵ�
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ֵ�");
	set("long", @LONG
����Ȫ�����涫�����һ���ɵ�����ģ������ȥ�ɴﺣ�⽻ͨʹ�ڸ���
������һ�����ׯ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"silkshop",
		"south" : __DIR__"jiedao2",
		"north" : __DIR__"tumen",
	]));

	set("objects", ([ 
                __DIR__"npc/liumangtou" : 1,
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
