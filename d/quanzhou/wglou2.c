// Code of ShenZhou
// wglou2.c �������¥
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�������¥");
	set("long", @LONG
¥�Ͼ������������Ͳ������ƴ�Զ�������⵴����ˮ�����������ʤ�գ�
Ҳ�������������ȫ�����صĿ��̣��ο���������Ʒ�����ֳ�ʦ�����ա���
�����µ�һ�˵ġ�����ǽ����������¥�ľ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"down" : __DIR__"wglou1.c",
	]));

        set("objects", ([ 
		__DIR__"npc/wu" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
