// Code of ShenZhou
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "�뷿");
        set("long", @LONG
����������С��Ĺ뷿�������������¹�ү�Ķ����ˡ�
LONG
        );

        set("objects", ([
	    __DIR__"npc/zhonghui" : 1,
	    __DIR__"npc/guannan" : 1,
	]));

        set("exits", ([
		"west": __DIR__"huayuan",
        ]));

	set("cost", 0);
        setup();
	replace_program(ROOM);
}

