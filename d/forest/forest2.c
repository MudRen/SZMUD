// Code of ShenZhou
// Jay 7/11/96

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

/*        set("objects", ([
            "/d/city/obj/branch" : 1,
	    "/d/quanzhou/npc/wuya" : 1,
	]));
 */
        set("exits", ([
		"north" : __DIR__"forest4",
                "west"  : __DIR__"schemeroom4", 
                "east" : __DIR__"forest1",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

