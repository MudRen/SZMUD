// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�������С�������洫����˻˻�������졣�����и����
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"barn",
		"south" : __DIR__"btyard",
		"east" : __DIR__"barn1a",
	]));
	
	create_door("east", "ľ��", "west");

	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
