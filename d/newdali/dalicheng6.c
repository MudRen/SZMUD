// Code of ShenZhou
// Room: /d/dali/dalicheng6.c

inherit ROOM;

void create()
{
	set("short", "Ѧ�ǳ�����");
	set("long", @LONG
����һ�����ֺŵĹ���ׯ����������˸�ʽ����������񡢾˿������
Ƥ������춷��л������ȹ��ˮ��ɫ�ް�������ɫ�Ż���������һ���㡣
LONG);
	set("objects", ([
		__DIR__"npc/bossxue" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"dalicheng5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
