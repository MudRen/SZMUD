// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov4.c

inherit ROOM;

void create()
{
	set("short", "��֭����");
	set("long", @LONG
����λ����֭���ϣ�ԭ������һ���ز��£������Ժ��ϡ�Ψ��һ��ʯ�̾�
���������С�
LONG);
	set("exits", ([
		"eastup" : __DIR__"minov13",
		"north" : __DIR__"minov5",
		"west" : __DIR__"minov2",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
