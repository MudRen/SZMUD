// Code of ShenZhou
// Room: /d/dali/wlseast.c
// AceP

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "Сɽͷ");
	set("long", @LONG
����������ɽ�е������У�������ľ��ϡ�裬ǰ�治Զ��Щ�̻�
�����������̵����ӡ�
LONG );

	set("exits", ([
		"south" : __DIR__"wls5",
		"north" : __DIR__"wls4",
		"west"  : __DIR__"wls3",
		"east"  : __DIR__"wlseast1",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}
