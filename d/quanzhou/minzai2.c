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
��������Ȫ�����ġ�������ݡ������Ͽ�ͨ��Դ���á�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"minzai1",
		"south" : __DIR__"minzai3",
                "west" : "/d/wuguan/damen",
		"southwest" : __DIR__"yuanhe",
	]));

        set("objects", ([ 
                __DIR__"npc/oldwoman" : 1,
		__DIR__"npc/xiao-hai" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
