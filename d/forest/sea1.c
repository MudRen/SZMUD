// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
�����ǲ�����
LONG
        );

        set("exits", ([
		"west" : __DIR__"bank8",
		"southeast" : __DIR__"sea2",
        ]));

	set("outdoors","forest");
	set("cost", 5);
        setup();
	replace_program(ROOM);
}

