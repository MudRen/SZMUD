// Code of ShenZhou

// kane: 98/3/025

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǵ��ϻ�ɽ�����緢��Ȼ�γɵ�һ��ʯ�壬ɽ�Ŵ���һ��ʯ����������
��һ�����������֮����ֻ�ǿ������ƺ���һ����ζ��
LONG
        );
        set("exits", ([
                "enter" : __DIR__"icefire_cave",
		"southeast" : __DIR__"icefire2",
        ]));

        set("objects", ([
		"/d/island/npc/bear" : 2,
	]) );

	set("outdoors", "island");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

