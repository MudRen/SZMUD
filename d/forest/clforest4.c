// Code of ShenZhou
// room: /d/city/seforest2.c
// Jay 7/4/96

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ��
͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ��Ұ�޵�Х��ʹ�˲���
��ԥ��ǰ���ĽŲ���
LONG
        );

	i = random (3);
	switch (i) {
	case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
	    "/d/city/npc/maque" : 1,
	]));
        break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
  //          "/d/city/npc/laohu" : 1,
        ]));
        break;
	}

        set("exits", ([
                "south"  : "/d/taihu/road",
                "west"  : __DIR__"clforest3",
                "north" : __DIR__"cldamen",
        ]));
//	set("outdoors","city");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

