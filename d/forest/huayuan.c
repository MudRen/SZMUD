// Code of ShenZhou
// yanting.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "��԰");
        set("long", @LONG
�����ǽ�����������ͼҵ��Ứ԰��԰���滨����鲼���������
����С��Ĺ뷿���ϱ��Ǵ�����
LONG
        );

        set("objects", ([
	    __DIR__"npc/ren" : 1,
	    __DIR__"npc/lin" : 1,
	    "/d/wudang/npc/bee" : 1,
	]));

        set("exits", ([
                "south" : __DIR__"dating",
		"east": __DIR__"guifang",
        ]));
	set("outdoors","city");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

