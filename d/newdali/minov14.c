// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov14.c

inherit ROOM;

void create()
{
	set("short", "�سص̰�");
	set("long", @LONG
��ط羰���ˣ��ص̰�����������к��У����ϱ��Ա�ˮ������̲����ݺ�
֮�࣬�����ڵ�أ����ֻ����£���������ɽ֮�������к��У�ң������ɽɫ��
��ӳ�ز��䣬������ˮ��������̣���Ȼ��ʤ��
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov13",
		"north" : __DIR__"minov15",
		"east" : __DIR__"minov16",
		]));
	set("area", "��٤��");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
