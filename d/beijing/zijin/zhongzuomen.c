//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
���������Ǻ����ţ�������̫�͵�ǰ�Ĵ�㳡�����̫�����
������ҴҶ�����
LONG
	);

	set("exits", ([
        "north" : __DIR__"xiaodao2",
        "southwest" : __DIR__"guang1"
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
