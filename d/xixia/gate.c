// Code of ShenZhou
// Room: /d/xixia/gate.c

inherit ROOM;

void create()
{
	set("short", "�ʹ�����");
	set("long", @LONG
����������Ļʹ����ţ����ȿ����������ţ��������ȭͷ���
ͭ�����ŵ�����վ�������¼���������ʿ���䱸���ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beidajie",
]));
	set("objects", ([
		__DIR__"npc/hgshi" : 4,
	]));
	set("outdoors", "xixia");
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
