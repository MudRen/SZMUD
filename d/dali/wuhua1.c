// Code of ShenZhou
// Room: /d/dali/wuhua1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������廪¥��ǰ�������쳣������������һ�������ȫ����
ʯ�̵أ��ڰ���䣬����������ɶ�����ǧ�ˡ�ʱʱ�ɼ�����������
����ʳ�������ߡ�
LONG
	);
	set("exits", ([
		"out" : __DIR__"shanlu7.c",
		"north" : __DIR__"wuhua2.c",
		]));

	set("objects", ([
		__DIR__"npc/waiter" : 3,
        ]));

	set("no_clean_up", 0);
	set("cost", 1);
	setup();
}
