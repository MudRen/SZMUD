// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov55.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
����һ��������ķ��ݡ��˼���������������ɽ�ƿ������ſ�������İ��
��ʯ�󷿣�װ����Ϊ���ף������Ǿ��ĵ��Ƶģ������ա��¡������Ⱦ�����ͼ����
�����������������ļ�����ݡ�
LONG);
	set("exits", ([
		"east" : __DIR__"minov54",
		"enter" : __DIR__"minov56",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
