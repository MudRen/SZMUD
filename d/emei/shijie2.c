// Code of ShenZhou
// shijie2.c ��ʯ��
// Shan: 96/06/23

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
�쵽����ɽ�ˡ�����һ��ͨ������ɽ����ʯ�ף�����������Σ�����ʮ��
���¡�ʱ���ܼ���Щ������͡�
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"shijie1",
                "north" : __DIR__"emroad1",
                "northdown" : "/d/chengdu/tulu1",
        ]));

        set("objects", ([
                __DIR__"npc/woman": 1,
		__DIR__"npc/puren": 1,
	]) );

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

