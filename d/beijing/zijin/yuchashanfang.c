//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "�����ŷ�");
	set("long",  @LONG
    �������ŷ�.
LONG
	);

	set("exits", ([
        "west" : __DIR__"jianting",
	]));

	setup();
	replace_program(ROOM);
}
