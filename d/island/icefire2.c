// Code of ShenZhou

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǵ��ϵ�һ��Ƭ���֣����˵������֮�⣬��������滨���ݴ�֮
�У�ż������һЩ�в�����Ŀ�Ĵ���С�ޣ�����Ҳ���޺����ˡ�����������
һ��ʯɽ��ɽ����¶��һ��ʯ����
LONG
        );
        set("exits", ([
                "south" : __DIR__"icefire1",
		"northwest" : __DIR__"icefire3",
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

