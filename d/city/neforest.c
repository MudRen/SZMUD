// Code of ShenZhou
// room: /d/city/neforest.c
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

	i = random (4);
	switch (i) {
	case 0:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/city/obj/branch4" : 1,
	    "/d/quanzhou/npc/wuya" : 1,
	]));
        break;
	case 1:
        set("objects", ([
            "/d/city/obj/branch2" : 1,
            "/d/wudang/npc/yetu" : 1,
        ]));
        break;
        case 2:
        set("objects", ([
            "/d/city/obj/branch3" : 1,
            "/d/xingxiu/npc/snake" : 1,
        ]));
        break;
        case 3:
        set("objects", ([
            "/d/city/obj/branch1" : 1,
            "/d/gaibang/npc/zhangzi" : 1,
        ]));
        break;
	}

        set("exits", ([
                "west" : __DIR__"beijiao2",
                "south" : __DIR__"dongjiao2",
        ]));
//	set("outdoors","city");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

