// Code of ShenZhou
// Room: /d/dali/dalicheng5.c

inherit ROOM;

void create()
{
	set("short", "̫�Ͷ���");
	set("long", @LONG
̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������������ڴ�
�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��ʳ��
���޲�������ԭ��������Ѧ�ϳ����̣�������ҩ�̡�
LONG);
	set("exits", ([
		"north" : __DIR__"dalicheng6",
		"south" : __DIR__"dalicheng8",
		"west" : __DIR__"dalicheng2",
		"east" : __DIR__"dalicheng7",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
