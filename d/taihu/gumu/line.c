// Code of ShenZhou
//GU MU FROM SANTA
//line.C

inherit ROOM;

void create()
{
	set("short", "��Ӣ������");
	set("long", @LONG
��ʯ�ҳʽ�״�����ǵ����ֳ�Ӣ��ϰ�ڷ��ĵط���
 LONG
	);
	 set("exits", ([
		"west" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}






