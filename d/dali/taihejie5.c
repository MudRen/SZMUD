// Code of ShenZhou
// Room: /d/newdali/taihejie5.c

inherit ROOM;

void create()
{
	set("short", "̫�ͽֿ�");
	set("long", @LONG
̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������
������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ
�ӣ�ϰ�׸��죬��ʳ�����޲�������ԭ��̫ѧ���ǵ�����֮��͸�ҿ�
�š�������ƽ�������������Ƕ�����������������йٵ�ͨ��ԭ��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"taihejie4.c",
		"north" : __DIR__"northgate.c",
//		"enter" : __DIR__"taixueyuan",
		"west" : __DIR__"wangfu1.c",
		"east" : __DIR__"dinganfu.c",
		]));

	set("no_clean_up", 0);

	set("objects", ([
//		__DIR__"npc/collector" : 1,
		]));

	setup();
}







