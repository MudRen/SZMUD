// Code of ShenZhou
// Room: /d/xixia/yamen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ݸ������ڵأ���ɫ����ƽʱ�������ţ���ǰ�ĸ����������
����û����ɵ�����ˮ���վ�š������и���ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie",
]));
	set("objects", ([
		"/d/xixia/npc/yayi" : 4,
	]));
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
