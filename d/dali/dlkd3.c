// Code of ShenZhou
// dali kedian

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ���������һƬ�����֣������ӷ���ʮ������
�������ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ���
�յģ���������ŵ����˹�ȥ��
LONG
	);

	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);

	set("exits", ([
		"out" : __DIR__"dlkd2",
	]));

	set("cost", 1);
	setup();
}
