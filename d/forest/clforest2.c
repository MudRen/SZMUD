// Code of ShenZhou
// /d/forest/clforest2.c
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
                __DIR__"npc/cl_feng" : 1,
                __DIR__"npc/cl_gao" : 1,
        ]));

        set("exits", ([
                "southeast" : __DIR__"clforest3",
                "west" :  __DIR__"clforest1",
		"northwest" : "/d/city/seforest",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

