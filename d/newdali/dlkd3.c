// Code of ShenZhou
// Room: /d/dali/dlkd3.c

inherit ROOM;

void create()
{
	set("short", "˯��");
	set("long", @LONG
����һ��ܴ�Ŀͷ���������һƬ�����֣������ӷ���ʮ�����񴲣����ٿ�
�������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���������ŵ���
�˹�ȥ��
LONG);
	set("exits", ([
		"out" : __DIR__"dlkd2",
		]));
	set("cost", 2);
	set("hotel",1);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
