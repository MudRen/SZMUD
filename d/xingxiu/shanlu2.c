// Code of ShenZhou
// shanlu1.c
// maco
inherit ROOM;

void create()
{
    int i;
	set("short", "ɽ·");
	set("long", @LONG
�˴�����ȺɽΧ�ƣ��м�һ������߷�������ֻ�����
�������ʣ��������ס�
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan5",
		"west" : __DIR__"chalu1",
	]));
	set("outdoors","xingxiu");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}
