// Code of ShenZhou
// Room: /d/dali/shilin2.c

inherit ROOM;

void create()
{
	set("short", "������ʯ��");
	set("long", @LONG
�ഫ������¡��ң��ʯ��������꣬��ʵ�ʺ죬�����գ�����Ѱ֮��������
�ʳ������䡣���Լһǧ����Ķ��������ʯ�֣�Сʯ�֣�����ʯ�֣���·��ʯ��
�����֮һ��ǧ��ȼ磬��С�߰�����Ϊ�ӽ���Զ�۵���һƬ���ܴشأ���ȱ
�ٱ仯Ծ�������������ͬ��������Ĵ���Ȼ�ľ���ϸ����ʹ����ʯ����׳��
׳�ޣ������ˣ�����������Ф�����滹�١�
LONG);
	set("exits", ([
		"east" : __DIR__"shilin5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
