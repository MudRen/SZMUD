// Code of ShenZhou
// Room: /d/dali/tower1.c

inherit ROOM;

void create()
{
	set("short", "��һ��");
	set("long", @LONG
���Ĵ������񣬸�Լ�ĳߣ����״��У��ֳָ��ᣬ����ׯ�ء�������̤��ū��
һ��ū���Ⱪ���������ߣ�����������ū����������ū���͡�һ����������
�ˣ��м�һ������˫�ָ�������һ�㡣����֮�������ķ𾭡�
LONG);
	set("exits", ([
		"up" : __DIR__"tower2",
		"out" : __DIR__"minov5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
