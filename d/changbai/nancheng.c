// Code of ShenZhou
// Room: nacheng.c

inherit ROOM;

void create()
{
	set("short", "�ϳ�");
	set("long", @LONG
�������û����̾͵Ľֵ������ϵ����˲��࣬�����������塣ż���м�
������������ε������߹��������������壬����ľ���������һ���Ͱ�
���������ſڹ���һ��д�����ĵĻ��ӣ���������������㣬��������һ��
С���ݡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"muqiao",
		"north" : __DIR__"jishi",
                "west" : __DIR__"xrguan",
	]));

        set("objects",([
      //          __DIR__"npc/juren2" : 1,
      //          __DIR__"npc/juren3" : 1,
                __DIR__"npc/teng" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}

