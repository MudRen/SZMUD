// Code of ShenZhou
// xiayiting.c �ƺӰ��������
// qfy Sept 7, 96

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���ǻƺӰ����µĴ��������Ϲ��š��������������Ҷ���￿
�����Ϸ���һ�Ż�Ƥ���Σ����߰����ż�����ľ���Σ��ǳ������ɡ�
ǽ�ϸ�ӹ���ŵع��˼��������鷨��
LONG
        );

        set("objects", ([
	    __DIR__"npc/sha-tongtian" : 1,
	    __DIR__"npc/peng-lianhu" : 1,
	    __DIR__"npc/liang-ziweng" : 1,
	]));

        set("exits", ([
                "east" : __DIR__"huanghebang2",
        ]));

	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

