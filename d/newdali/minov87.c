// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov87.c

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
���ǲ�ɽ��´��һ�����ĳ��򡣴˵�����ɽ�ڣ����߳�ɽ����������������
·���У�Ψ�д���������ɽ������Ǵ�����������ľ���Ҫ�壬������ڴ���
�е�¥����������פ�����йٱ������վ��Ѳ�ߣ��̲�������ˡ�
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));
	set("exits", ([
		"northup" : __DIR__"minov88",
		"south" : __DIR__"minov86",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
