// Code of ShenZhou
// Room: /d/dali/dalicheng1.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������������ڴ�
�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��ʳ��
���޲�������ԭ��̫ѧ���ǵ�����֮��͸�ҿ��š�������ƽ�������������Ƕ���
��������������йٵ�ͨ��ԭ��
LONG);
	set("exits", ([
		"north" : __DIR__"northgate",
		"south" : __DIR__"dalicheng2",
		"west" : __DIR__"wangfu1",
		"east" : __DIR__"dinganfu",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
