// Code of ShenZhou
// Room: /d/dali/shilin5.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ܳ�Լʮ�������������Σ������������ܵĴ����С�������һ��
���£��������л�ҫ�������ɰس��֣��Դ����Σ��������£�ɫ��Ҷ�ۣ�����ɽ
������׺��䡣��ˮ���̣���һ����΢���ж����Ľ��У��̵ľ�Ө���̵Ļ�Ծ��
�̵����ˡ�
LONG);
	set("exits", ([
		"northeast" : __DIR__"shilin3",
		"southdown" : __DIR__"shilin1",
		"west" : __DIR__"shilin2",
		"enter" : __DIR__"shilin4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
