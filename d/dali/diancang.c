// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "���ɽ");
	set("long", @LONG
���ɽ�Ǵ������ɽ��ɽ����׳���������ơ���������ɽ·ͨ�����档
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shanlu1.c",
		"north" : __DIR__"tlsgate.c",
	]));


	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
