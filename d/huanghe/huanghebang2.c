// Code of ShenZhou
// huanghebang2.c �ƺӰ�㳡
// qfy Sept 7, 96

inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
�㳡ռ�����󣬲����Ͻ���������ȥ�ɴ�ƺӰ�ġ�����������
��Χ����Щ���ᣬ�����ھ�ס��
LONG
        );

        set("objects", ([
	    __DIR__"npc/wu-qinglie" : 1,
	    __DIR__"npc/qian-qingjian" : 1,	
	]));

        set("exits", ([
                "east" : __DIR__"huanghebang1",
		"west" : __DIR__"xiayiting",
        ]));

	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

