// Code of ShenZhou
// kaiyuan.c ��Ԫ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ԫ��");
	set("long", @LONG
����һ����ģ����ǧ���ɲ����������������𣬴�ͩ��ӳ�����Ŵ�
������δ����ǰ��ԶԶ�ɼ�����ʯ����ն��𣬴�����ǧ¥����֮�ϡ�����
������������꣬ȫ��ռ���Ӵ��Ǹ������ķ�̽���֮һ�������������
�棬������ʯ���ˣ���ֲ��ͩ�����ſ��������������ﲻ��������͡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"tianwang",
		"south" : __DIR__"citong_w2",
	]));

        set("objects", ([ 
		__DIR__"npc/guest" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
