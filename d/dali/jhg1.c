// Code of ShenZhou
// Room: /dali/jhg1.c
// AceP

inherit ROOM;

void create()
{
	set("short", "�������㳡");
	set("long", @LONG
������ǽ������ˡ��˴�����������������Ĺ㳡����������һ����ΰ�Ĵ�����
���洫�������ཻ֮���������������ڽ����С����߲�Զ��һЩ���ᣬ����������
�ӵ�ס����һЩ�������������ڽ������߶����ȴ�������Ľ����
LONG
	);

	set("exits", ([
		"north"    : __DIR__"jhg",
		"eastdown" : __DIR__"wls",
	]));

	set("objects", ([
		__DIR__"npc/gan": 1,
		__DIR__"npc/ge": 1,
	]));

	set("cost", 1);
        set("outdoors", "dali");
	setup();
}
