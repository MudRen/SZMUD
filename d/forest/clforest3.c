// Code of ShenZhou
// /d/forest/clforest3.c
// by aln 2 / 98

inherit ROOM;

void create()
{
        int i;
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG
        );

        set("objects", ([
                __DIR__"npc/cl_fan" : 1,
                __DIR__"npc/cl_lu" : 1,
        ]));

        set("exits", ([
                "northwest" :  __DIR__"clforest2",
		"east" : __DIR__"clforest4",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

