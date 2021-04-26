// Code of ShenZhou
// Room: /d/dali/gaten1.c

inherit ROOM;

void create()
{
	set("short", "����Ǳ�");
	set("long", @LONG
�����Ǹ���·�ڡ��ϱ߾��Ǵ���ǵı����ˣ���·������ֲ���ȥ�ɵ�̫
�ͳǣ�����ͨ���¹سǣ�Ҳͨ��ɽ����ȥ�β�ɽ�ͳ�ʥ�µıؾ�֮·��
LONG);
	set("exits", ([
		"northwest" : __DIR__"esqiao",
		"north" : __DIR__"taihec",
		"south" : __DIR__"northgate",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
