// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov71.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��վ���������ı��������߲�Զ����ϲ�ݳǡ��˺����󣬵���ˮ�峺�����
���У�����̨�Ĵ��������ں��ϲ��㡣��֮�ϺͶ��߰�ɽ�϶���̨�Ĵ���
�е�·�ƺ�������ͨ���ϱߡ�
LONG);
	set("exits", ([
		"southeast" : __DIR__"minov72",
		"eastup"  : __DIR__"minov78",
		"north" : __DIR__"minov64",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
