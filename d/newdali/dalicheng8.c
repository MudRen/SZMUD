// Code of ShenZhou
// Room: /d/dali/dalicheng8.c

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ�����ص�ҩ�̣������ڴ�ͽֺ������ĵĽ���֮������ͨ���������
�ƣ��ַ��Ƕ�˵���ҩ�̵�ҩ����ĺܡ���ҩ���ϵļ��ٸ�С������ɢ��������
һ��ŨŨ��ҩζ�����㼸����Ϣ����˵��ҵ�����һ�ֺ����ܵ�ҩ�
LONG);
	set("objects", ([
		__DIR__"npc/hongyao" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"dalicheng5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
