// Code of ShenZhou
//GU MU FROM SANTA
//cyn.C

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
����ʯ��������խ�����ǵ�����������ϰ�Ʒ��ĵط���

LONG
	);
	 set("exits", ([
		"south" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





