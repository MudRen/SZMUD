//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",  @LONG
����������̫�͵�����Ǿſװ����š�
LONG
	);

	set("exits", ([
        "north" : __DIR__"youyimen",
        "southeast" : __DIR__"guang2",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
