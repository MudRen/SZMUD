// Code of ShenZhou
// jiulao2.c ���϶�
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "���϶�");
        set("long", @LONG
����Ƕ��ҵ�һ�󶴣���������ޱȣ������Ѳ⡣��һ�߽������㷢����
�в涴�����Թ�������Ī�⣬�ƺ�����޵ס����ǿ���뿪�ɡ�
LONG
        );

        set("exits", ([
        "north" : __DIR__"jiulao3",
        "south" : __DIR__"jiulao3",
        "west" : __DIR__"jiulao3",
        "east" : __DIR__"jiulao3",
	"out" : __DIR__"jiulao1"
        ]));

        set("objects", ([
                __DIR__"npc/bat": 4]));

        set("no_clean_up", 0);

	set("cost", 4);
        setup();
	replace_program(ROOM);
}

