// Code of ShenZhou
//GU MU FROM SANTA
//lins.C

inherit ROOM;

void create()
{
	set("short", "��Ӣ������");
	set("long", @LONG
����ʯ��������խ�����ǵ����ֳ�Ӣ��ϰ�Ʒ��ĵط���

 LONG
	);
	 set("exits", ([
		"north" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





