// Code of ShenZhou
// Room: /d/dali/shilin4.c

inherit ROOM;

void create()
{
	set("short", "��С֥�ƶ�");
	set("long", @LONG
���Ż��۽��붴�ڣ��ػ����У����ã�����һ����Ȼ���ʣ�ʯ���飬ʯ��
ʯ����������͸��������ʤ�����ձ�Ӱ�����´����ң�Ϫ�ƽ�ˮ�������ֺ���ʯ
��δ䣬���Ŀɰ���
LONG);
	set("exits", ([
		"out" : __DIR__"shilin5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
