// Code of ShenZhou
// Room: /d/dali/tower6.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������е��з��񸡵�����������������ܣ���η�����������죬
����Э���������Ⱦ����������ɣ��������������������������ǵ���ʯ��������
��Ʒ���������ļҽ��ޡ������������˼�ƷҲ����
LONG);
	set("exits", ([
		"up" : __DIR__"tower7",
		"down" : __DIR__"tower5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
