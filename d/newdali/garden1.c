// Code of ShenZhou
// Room: /d/dali/garden1.c

inherit ROOM;

void create()
{
	set("short", "�軨԰���");
	set("long", @LONG
��һ����ɫ��ʯǽ���棬�������Կ���һ���ŵĴ����������ŵ����Ư����
�����軨��ζ�����в���һ��������
LONG);
	set("exits", ([
		"west" : __DIR__"wangfu5.c",
		"enter" : __DIR__"garden2.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
