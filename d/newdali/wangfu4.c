// Code of ShenZhou
// Room: /d/dali/wangfu4.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ�������ܵ�Բ�δ���ɫ�����߶���ȫשľ�ṹ��û�д������ݣ�
ȫ����ʮ�˸�ľ������ʮ��������֧�š���������ĸ���������������һ���ļ���
�в�ʮ������������ʮ�����£���Ȧʮ����������ʮ����ʱ������������ʮ����
�����ʮ�ĸ���������ƾ��ɣ�Ԣ�����ء�
LONG);
	set("objects", ([
		__DIR__"npc/weishi3" : 2,
		"/kungfu/class/dali/weishitou" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"wangfuroad1.c",
		"south" : __DIR__"wangfu3.c",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
