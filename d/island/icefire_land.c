// Code of ShenZhou

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǵ��춫����һ����ƽԭ��Զ����ɽ������ѩ��ƽҰ��ȴ��Ŀ���̣���
�ɴ�أ��ߴ��쳣����������滨��������Ϊ�������ޡ�ƽҰ��һȺ÷��¹��
���еĳԲݣ��������ˡ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"icefire1",
        ]));

        set("objects", ([
                "/d/changbai/npc/deer": 3,
	]) );

	set("outdoors", "island");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

