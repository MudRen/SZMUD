// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov24.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�н�����گ��᫵�ɽ���С���ɽ����������ï�ܷ�ʢ����ľ��֦辺�����
����·�����������ѡ�����ɽ�񾭳����߲ſ��������ĵ�·����������ˣ�����
��Ȼ��ҪЮ����������ʱ׼������·����ľ������ϰ���
LONG);
	set("exits", ([
		"southwest" : __DIR__"minov23",
		"eastup" : __DIR__"minov25",
		]));
	set("area", "������");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
