// Code of ShenZhou
// Room: /d/dali/crossing.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
���Ǵ�����ڵ���Ҫ��ó����������ɫɫ�Ľ������ڶ��ߴ����
�������಻����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ������
���Ը���������¥�ƣ����������־���פ�أ�����������ӡ�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"west" : __DIR__"dahejie.c",
		"north" : __DIR__"taihejie2.c",
		"south" : __DIR__"southgate.c",
		"east" : __DIR__"dahejie1.c",
		]));
	set("no_clean_up", 0);

	setup();
}








