//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�ѵ���");
	set("long",  @LONG
����������̫�͵�����Ǿſװ����š�
LONG
	);

	set("exits", ([
        "north" : __DIR__"zuoyimen",
        "southwest" : __DIR__"guang2",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
