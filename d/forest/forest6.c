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
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ�������һ�����(river)
�������졣
LONG
        );

        set("objects", ([
	    __DIR__"npc/xiaoyaozi" : 1,
            __DIR__"npc/chang" : 1,
            __DIR__"npc/hua" : 1,
            __DIR__"npc/gaiyiming" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"forest5",
        ]));

	set("item_desc", ([
		"river" : "�����ļ����ɴ��ѹ������������������������֦�������\n",
	]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

