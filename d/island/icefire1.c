// Code of ShenZhou
// kane: 98/3/025
// modified by aln 4 / 98

inherit HARBOR;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǳ���������һ�����죬��ΧһƬ���̲ݵأ������������Ǽ�ʯ���
��ɽ�壬���ι�����Ī����״������ȴ��һƬ��������ͷ��ƽҰ�����������
�ͳ���ɽ��������һ�����ơ�
LONG
        );
        set("exits", ([
		"east" : __DIR__"icefire_land",
                "west" : __DIR__"icefire_hill",
		"north" : __DIR__"icefire2",
        ]));

/*
        set("objects", ([
                __DIR__"npc/cow": 1,
		__DIR__"npc/xiexun" : 1,
	]) );
*/
	set("outdoors", "island");

        set("island", "����");
        set("shape", "�ƺ���һ��������");
        set("navigate/locx", 100);
        set("navigate/locy", 600);

	set("cost", 1);
        setup();
}

