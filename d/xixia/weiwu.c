// Code of ShenZhou
// Room: /d/xixia/weiwu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ĺ�����������פ���ر�����¥�ߴ����ɣ��ſ������Źٱ�����
������̲�������ˣ����ſڵĸ�ʾ�ϻ������ͨ���Ľ�������ͼ�Σ�����ͷ
����ȥ��ͦ���֡����Ͼ���ȥ���ǵķ����ˣ��������������ɽ����
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wsling",
  "north" : __DIR__"tumenzi",
]));
	set("objects", ([
		__DIR__"npc/xxbing" : 3,
	]));
	setup();
	replace_program(ROOM);
}
