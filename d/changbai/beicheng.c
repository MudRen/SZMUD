// Code of ShenZhou
// Room: beicheng.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������û����̾͵Ľֵ������ϵ����˲��࣬�����������塣ż���м�
������������ε������߹��������������壬����ľ���������һ������
��С���֪ͨ��δ���
LONG
	);

	set("exits", ([
		"south" : __DIR__"jishi",
                "west" : __DIR__"xiaoxiang",
	]));

        set("objects",([
        //        __DIR__"npc/juren2" : 1,
        //        __DIR__"npc/juren3" : 1,
                 __DIR__"npc/xiucai" : 1,
        ]));

        set("outdoors", "chanbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

