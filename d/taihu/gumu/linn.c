// Code of ShenZhou
//GU MU FROM SANTA
//linn.C

inherit ROOM;

void create()
{
	set("short", "��Ӣ������");
	set("long", @LONG
����ʯ���������ǵ����ֳ�Ӣ��ϰȭ���ĵط���
LONG
	);
	 set("exits", ([
		"south" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}






