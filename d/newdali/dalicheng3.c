// Code of ShenZhou
// Room: /d/dali/dalicheng3.c

inherit ROOM;

void create()
{
	set("short", "�߹���");
	set("long", @LONG
�߹���λ�ڴ�����ڣ����ڵ��ɽб���嶫�¡��ഫ�����������������١���
��β�����ڣ���ˮ���ģ�����ʿ�γ��ֻ�������������ͬ���ھ������˽�����
��ˮ�ƣ����߹ǻ�����ˮ����Ϣ������һ���ܴ�ʽ����ש����
LONG);
	set("objects", ([
		"/d/village/npc/kid" : 2,
		]));
	set("exits", ([
		"east" : __DIR__"dalicheng2",
		"west" : __DIR__"dalicheng4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
