// Code of ShenZhou
// Room: /dali/chadao.c
// AceP

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����Ǵ���ԭ������ٵ��ϵ�һ����������������ֵ��С������ǹٵ�
����·�������ͽ������ϴ��������ɽ���ˣ���������᫣���·�ѱ棬�Դ�
��������Ϥ���ˣ��Ǹ����Ҳ���·�ġ�
LONG
	);

	set("exits", ([
		"west"  : __DIR__"wls1",
		"east"  : __DIR__"guandao",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
