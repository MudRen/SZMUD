// Code of ShenZhou
//GU MU FROM SANTA
//SHULIN2.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����Խ�����Խ�Ƕ���������ҲԽŨ��ֻ���ǲ�
֪��������ҲԽ��Խ�졣���ǵ���һ��ĺá�
LONG
	);

	set("exits", ([
		"south" : __DIR__"fenglin1",
		"north" : __DIR__"shulin1",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}




