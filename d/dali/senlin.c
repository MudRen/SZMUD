// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "大森林");
	set("long", @LONG
此去向北是无量山区和大森林，这里已经林木茂密人迹
罕至了，南面是大理到中原的官道大路。
LONG
	);

	set("exits", ([
		"north" : __DIR__"heisenlin.c",
		"south" : __DIR__"dian1.c",
	]));

	set("cost", 2);
        set("tjjob", 2);
	set("outdoors", "dali");
	setup();
}
