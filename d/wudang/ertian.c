// Code of ShenZhou
// ertian.c ������ 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǡ������š������ӲӵĽ𶥾�����ǰ�ˡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"toutian",
                "southup" : __DIR__"santian",
	]));
	set("cost", 3);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

