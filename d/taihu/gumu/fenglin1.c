// Code of ShenZhou
//GU MU FROM SANTA
//fenglin1.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰ�ľ���������һ���������ǵض����۷䣬��ͷ��
Ѱ���۷�������һ�������Ҿ�Ө͸������ټ��ʯ�������㾪��
���ǣ���Щ����ھ�ֹ����֮�䣬�ƺ������·����������˶���
һλ���֡�

LONG
	);

	set("exits", ([
		"south" : __DIR__"fenglin2",
		"north" : __DIR__"shulin2",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





