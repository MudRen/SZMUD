// Code of ShenZhou
// Room: /d/xixia/dawu.c

inherit ROOM;

void create()
{
	set("short", "���д���");
	set("long", @LONG
����һ��ԭľ�Ƴɵ�����ߴ���������ȥ����Щ���µ��Լ���쳣���ײ�
����������ľ�ܿգ�һ��ľ��ͨ���¥����¥��¥���Ϲ���һ������һ��������
���죬����ȥ���ƾɲ���������ֻ֪���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"kongdi",
]));
	set("objects", ([
		__DIR__"npc/eshen" : 1,
		__DIR__"npc/ye" : 1,
	]));
	setup();
	replace_program(ROOM);
}
