// Code of ShenZhou
//GU MU FROM SANTA
//shidao.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ͨ�������İ�Χ��������һ������ȴ���ֽ���̤����һ��
��խ��ʯ��

LONG
	);

	set("exits", ([
		"south" : __DIR__"shidao",
		"north" : __DIR__"fenglin1",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







