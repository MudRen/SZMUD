// Room: /d/chengdu/dongdajie2.c
// By xuanyuan

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�����
�����سǹٱ���ߺ�������������񶼴�����Ǳ�һ���ྲ��ԭ������
Ϊ�ᶽ������ͷ���ϱ���һ����ֱ�Ĵ����
LONG );
        set("outdoors", "chengdu");

	set("exits", ([
		"east" : __DIR__"dadongmen",
		"west" : __DIR__"dongdajie1",
		"south" : __DIR__"zijuefumen",
		"north" : __DIR__"eastroad1",
	]));
        set("objects", ([
            "/d/city/npc/liumangtou" : 1,
            "/d/city/npc/liumang"    : 2,
        ]));
	setup();
	replace_program(ROOM);
}

