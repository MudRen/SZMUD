// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov65.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ��С·�����ֶ��������Ϸ��������һƬ̨���˾۾ӵĴ��򣬶�����ң
ң����ϲ�ݳǵĳ�ǽ����·��������ï�ܣ�ʱ��̨������������
LONG);
	set("exits", ([
		"northeast" : __DIR__"minov64",
		"southwest" : __DIR__"minov66",
		]));
	set("area", "ϲ�ݳ�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
