// Code of ShenZhou
// ���� /d/shenlong/shulin1
// ywz 10/10/96

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����ï�ܵ�Ҷ
��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ���߳����е�����
ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG
        );
	i = random (3);
	 switch (i) {
	case 0:
	set("objects", ([
	    "/d/city/obj/branch3" : 1,
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
            "/d/city/obj/branch1" : 1,
	    "/d/shenlong/npc/snake" : 1,
        ]));
        break;
        }

	set("exits", ([
		"north" : __DIR__"shulin2",
		"west" : __DIR__"tiandi2",
		"southup" : __DIR__"shangang",
        ]));
	set("cost", 1);

        setup();
        replace_program(ROOM);
}

