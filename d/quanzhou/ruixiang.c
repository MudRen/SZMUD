// Code of ShenZhou
// ruixiang.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
���������ڰ�ɽ����СϿ���е�һ��ʯƺ�����ϴ˴������ɼ�һ��Ư����
��ľʯ�ҡ�ʯ�Һ���ʵĴ���ʯ�����������塹����ʱһλ�ɽ������ɡ���
��Ĳ�᡹��������״������ׯ�ϴ󷽣�ά��άФ��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"shanlu3",
		"southup" : __DIR__"wangzhou",
	]));

        set("objects", ([
                "/clone/beast/smonkey" : 1,
        ]));
        set("cost", 4);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 4);
        setup();
	replace_program(ROOM);
}
