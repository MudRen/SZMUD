// Code of ShenZhou
//GU MU FROM SANTA
//cys.C

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
����ʯ���������ǵ�����������ϰȭ���ĵط���
LONG
	);
	 set("exits", ([
		"north" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}






