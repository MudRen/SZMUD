//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
���������Ǻ����ţ�������̫�͵�ǰ�Ĵ�㳡�����̫�����
�������ﾭ����
LONG
	);

	set("exits", ([
        "north" : __DIR__"xiaodao1",
        "southeast" : __DIR__"guang1",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
