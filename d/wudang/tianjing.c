// Code of ShenZhou
// tianjing.c �쾮
// xQin 11/00

inherit ROOM;

void create()
{
	set("short","�쾮");
	set("long", @LONG
��������������Ժ�Ե��쾮������ʮ���ľ���ֻ��ǽ�ߵ�һ�ô�����֦
Ҷʮ��ïʢ�����ϲ�ʱ��������֮������ʯС��ͨ�����ߵĺ�Ժ��
LONG
	);
	set("outdoors", "wudang");
	set("exits", ([
		"west" : __DIR__"houyuan",
		]));
	
	setup();
	replace_program(ROOM);
	
}