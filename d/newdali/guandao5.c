// Code of ShenZhou
// Room: /d/dali/guandao6.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������᫵���·��Խ���ϵ�ɽ�������ϱ��������Ѿ������ƹ󣬺��ɽ����
������������һ����Ȼ���ϸ������Ѻ����С����������ϴ���ɽ�����ɴ����
��ȥ��ɽ�����츮֮������·���Զ���һ���޼ʵĳ�ɽ����(mountain)��������
�����Ĵ�ɭ��(forest)��
LONG);
	set("item_desc", ([
		"forest" : "    ���ɽ���������ľ������ԭʼɭ���ˡ����ڵ���̫��᫣����Բɷ���ǧ��\n�Ĳ����ľ��������Ƭɽ����",
		"mountain" : "    �й������ϵĺ��ɽ����ɽ�ƶ��ͣ�����ǧ�ʵ��׳�գ�",
		]));
	set("exits", ([
		"northeast" : __DIR__"guandao6",
		"southwest" : __DIR__"guandao",
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
