// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov35.c

inherit ROOM;

void create()
{
	set("short", "���ƺ���");
	set("long", @LONG
���ƺ�����С��������Բ��ʮ���������ϼɽ����ˮ�峺��������ģ���
�Ǵ���������������֮ҹ������¹�ӳ�պ��棬���ˮ����ҡҷ���ˣ��緱
��������У��������ƣ�����֮���ڴ�Զ����֮���ϰ����ɼ�����������з�
���������С�
LONG);
	set("exits", ([
		"eastup" : __DIR__"minov36",
		"north" : __DIR__"minov34",
		]));
	set("area", "���۲�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
