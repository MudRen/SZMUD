// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "�ƺ�");
        set("long", @LONG
�����ǻƺ���
LONG
        );

        set("exits", ([
		"northwest" : __DIR__"sea1",
		"southeast" : __DIR__"sea3",
        ]));

	set("outdoors","forest");
	set("cost", 5);
        setup();
	replace_program(ROOM);
}

