// Code of ShenZhou
// minzai.c լ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "լ��");
	set("long", @LONG
����Ȫ�ݾ�����������С���ݺᣬ��ͨ�˴һʽ��ʯ�����ݣ��춥��ǽ��
�����Գƣ�����������ɫ����ν�������£�С�����硣���ߺ��ϱ߶���լ����
�ֵ��������������мҳ������۽������̡�Դ���á���������һ���ưܵ�լ�ӡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"minzai2",
		"south" : __DIR__"laozhai",
		"east" : __DIR__"citong_s2",
		"west" : __DIR__"yuanhe",
	]));

        set("objects", ([ 
                __DIR__"npc/girl" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
