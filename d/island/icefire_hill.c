// Code of ShenZhou

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǳ���������ɽ��ش������ι�״��ɽ���洦�ɼ����ұ����ʯ��
�˴�����ǻ�ɽ�����緢��������ɣ������״��˹��죮����ǰ�߾���
һ����ð���̵Ļ�ɽ�ˡ�
LONG
        );
        set("exits", ([
		"east" : __DIR__"icefire1",
        ]));

/*
        set("objects", ([
                __DIR__"npc/cow": 1,
		__DIR__"npc/xiexun" : 1,
	]) );
*/
	set("outdoors", "island");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

