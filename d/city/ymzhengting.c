// Code of ShenZhou
// Room: /city/ymdongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���϶����������ס������һ������������������ϸ������ǽ������һ����
�ң����顰����������ĸ���������Ĵ��֡��ᶽ�������İ����������飬ʦү
�����ں�
LONG
	);

	set("exits", ([
		"east" : __DIR__"dongting",
		"west" : __DIR__"xiting",
		"south" : __DIR__"neizhai",
		"north" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/kexiu" : 1,
		__DIR__"npc/gaozhi" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

