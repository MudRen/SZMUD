// Code of ShenZhou
// Room: /d/dali/hongshengt.c

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", @LONG
��ʥ����������һ�����������ڲ�ɽ֮´�����������Ϊ������������֮һ��
��ʥ����Ϊ�ķ��ο���שʯ�����������֮����ש������ɬ����ʹ���ĽǷ��̡�
�������������������ߣ�����������
LONG);
	set("exits", ([
		"west" : __DIR__"cangshan",
		"enter" : __DIR__"hongtj.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
