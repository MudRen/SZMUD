// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "Сɽ��");
        set("long", @LONG
һ��Сɽ������߻谵��������Щ������õ��������룬����
�����˳�����
LONG
        );
        set("exits", ([
		"out" : __DIR__"hill",
	]));

	set("objects", ([
		__DIR__"obj/tangshi" : 1,
	]));
	set("cost",1);
	setup();
        replace_program(ROOM);
}
