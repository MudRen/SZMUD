// Code of ShenZhou
// yanting.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
�����ǽ�����������ͼҵ����������ڸ����������׵��ϵ���ʿ���ڵ�
�ϵĺ��͡�ǰ�����ޡ������½�����������������ͱ�����ʶ��ȴ��Ľ��
���¾���֮������͡�
LONG
        );

        set("objects", ([
	    __DIR__"obj/yaohua" : 1,
	    __DIR__"obj/tipang" : 1,
	    __DIR__"obj/liji" : 1,
	    "/d/shaolin/obj/mala-doufu" : 1,
	    "/d/shaolin/obj/mizhi-tianou" : 1,
	    "/d/shaolin/obj/furong-huagu" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"dating",
        ]));

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

