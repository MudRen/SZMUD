// Code of ShenZhou
// shisun.c ʯ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
	set("long", @LONG
����Ȫ�������һ����ò��ۣ���ǧ���ʴ�γɵ�ʯ��ǧ��ٹ֣��ƽ���
�Ƶ�����׶����̬���졣�����ݺᣬ��֪���ա������ɽ������һ�����֡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"luanshi",
		"south" : __DIR__"caoan1",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
