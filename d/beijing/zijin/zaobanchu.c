//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "��촦");
	set("long",  @LONG
    ������.
LONG
	);

	set("exits", ([
	           "south" : __DIR__"gzxd1",
                      "west" : __DIR__"cininghuayuan",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
