// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov90.c

inherit ROOM;

void create()
{
	set("short", "��ɺӱ�");
	set("long", @LONG
��ɺ��������������Ӵ���խ��ˮ���ļ������Ѷɹ���ֻ��Զ�����β��к�
������������д��ɺӡ��˴��Ǻӹ�ת���ǳ̲��ˮ���Ի��������Կɼ����Ϻ�
ˮ��ӿ��ȥ���԰����������ɼ����ϱ�ɽ������ʯ�ǡ�
LONG);
	set("exits", ([
		"southup" : __DIR__"minov89",
		]));
	set("area", "��Ū��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
