// Code of ShenZhou
// Room: /d/dali/tower3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������������������֮������������һ�顣ʶ��ν�����۹�����
����Ϊ�ز��������������Ŀ�Ͱ�����̾�ϸ������������
LONG);
	set("exits", ([
		"up" : __DIR__"tower4",
		"down" : __DIR__"tower2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
