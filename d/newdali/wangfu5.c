// Code of ShenZhou
// Room: /d/dali/wangfu5.c

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
����һ���㳡�������и�ˮ�أ�����ββ���������е����Ρ�ˮ�����п��
�����ɵ�̫��ʯ������ˮ���Ӷ������������г�һ����СС���ٲ���
LONG);
	set("exits", ([
		"east" : __DIR__"garden1.c",
		"west" : __DIR__"wangfu3",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
