// Code of ShenZhou
//GU MU FROM SANTA
//fenglin2.C

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Խ��Խ�ܣ���Щ�����������ͷ����������������δչ����
��������û�����˵���������ǲ������׹����˵ġ�ǰ����Լ�ɼ�
һ���޴�ķ�Ĺ�������Լ�д�����������һ�����Ƿ�Ĺ�ѵ���
ס���˵�!?

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






