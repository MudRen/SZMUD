// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov72.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��վ���������Ķ��������µ���·�ƺ��������ϱ��Ĵ�����������ֻ����
�۵�㣬���ǲ����̨���񷤡�·�߾����������֣�̨�ĵ���¥�����֡���·
����ͨ�����������Բ�������ȥ�Ĳ�·ֱ�����ڳǡ�
LONG);
	set("exits", ([
		"northwest" : __DIR__"minov71",
		"southeast" : __DIR__"minov77",
		"south" : __DIR__"minov73",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
