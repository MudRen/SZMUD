// Code of ShenZhou
//GU MU FROM SANTA
//linw.C

inherit ROOM;

void create()
{
	set("short", "��Ӣ������");
	set("long", @LONG
��ʯ�ҳ�Բ�ͣ����ǵ����ֳ�Ӣ��ϰ�����ĵط���

 LONG
	);
	 set("exits", ([
		"east" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







