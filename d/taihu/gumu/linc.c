// Code of ShenZhou
//GU MU FROM SANTA
//chaoyin.C

inherit ROOM;

void create()
{
	set("short", "��Ӣ������");
	set("long", @LONG
���ǹ�Ĺ�ɴ�����ʦ�ֳ�Ӣ������ѧ�����ڣ�������������һ��
�����Գƣ����ִ����෴��������խǰ����Բ���ǡ�
LONG
	);
	 set("exits", ([
		"north" : __DIR__"linn",
		"south" : __DIR__"lins",
		"east"  : __DIR__"line",
		"west"  : __DIR__"linw",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





