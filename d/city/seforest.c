// Code of ShenZhou
// room: /d/city/seforest.c
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
	    CLASS_D("gaibang") + "/li-futou" : 1,
	]));
        break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
	    CLASS_D("gaibang") + "/li-futou" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch3" : 1,
            "/d/xingxiu/npc/snake" : 1,
	    CLASS_D("gaibang") + "/li-futou" : 1,
        ]));
        break;
	}

        set("exits", ([
                "southeast" : "/d/forest/clforest2",
                "north" : __DIR__"dongjiao4",
                "west" : __DIR__"nanjiao2",
        ]));
//	set("outdoors","city");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

