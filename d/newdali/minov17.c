// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov17.c

inherit ROOM;

void create()
{
	set("short", "��٤��");
	set("long", @LONG
�����ǵ�صĶ��ϣ���ôЩ������٤����۾ӵĵط���ôЩ���������ġ���
��ϲ��ƽԭ��ˮ������ˮ��ƽԭ���ӣ���Ϊ���顱���������������֣���ȱ��ס�
��٤��һ�����䣬��٤���Ǹ��൱������ӣ�����������������θ���
LONG);
	set("exits", ([
		"northwest" : __DIR__"minov16",
		"southwest" : __DIR__"minov18",
		"east" : __DIR__"minov20",
		]));
	set("area", "��٤��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
