// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov15.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������ܵ�ɽ����������ɽϵ������ɽ���Ķ�֧�������£��ܳ�����ɽ����
��С��ʮ��ɽ�塣���������ɽ���£�ɽ��ˮ���������Ӱ��������Ȼ��ͼ����
��صġ��ᡱ�������м��Ǵ���ӣ���˾��Ǩ�ġ�ʷ�ǡ��������д������أ���
�Ŵ�������һ���������Ĳ������ƣ�������ء�
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 2,
		]));
	set("exits", ([
		"northup" : __DIR__"senlin",
		"south" : __DIR__"minov14",
		]));
	set("area", "��٤��");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
