// Code of ShenZhou
// Room: /d/dali/shilin1.c

inherit ROOM;

void create()
{
	set("short", "·��ʯ��");
	set("long", @LONG
�����������洦�ɼ���ʯ���죬ʯ��Լ���ʯ��ͦ����������ʣ��������ˡ�
����ʯ���ܾۣ��罣��ſգ�çç�Բԣ�ٲȻһƬ�ֺ���εΪ׳�ۡ����Ӵ�ɽ֮
�л����ֱк���ɵ�ˮ���ƣ���ɽȪ��ۣ�������������
LONG);
	set("exits", ([
		"northup" : __DIR__"shilin5",
		"south" : __DIR__"cangshan",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
