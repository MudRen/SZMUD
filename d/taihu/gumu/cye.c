// Code of ShenZhou
//GU MU FROM SANTA
//cye.C

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
��ʯ�ҳ�Բ�ͣ����ǵ�����������ϰ�����ĵط���
LONG
	);
	 set("exits", ([
		"west" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}






