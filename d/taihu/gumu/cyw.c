// Code of ShenZhou
//GU MU FROM SANTA
//cyw.C

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
��ʯ�ҳʽ�״�����ǵ�����������ϰ�ڷ��ĵط���
LONG
	);
	 set("exits", ([
		"east" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}






