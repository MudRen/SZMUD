// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
�����Ƕ�����
LONG
        );

        set("exits", ([
		"northwest" : __DIR__"sea2",
		"southeast" : __DIR__"diaoyu",
        ]));

	set("outdoors","forest");
	set("cost", 5);
        setup();
	replace_program(ROOM);
}

