// Code of ShenZhou
// xiaolu1.c ��ɽ��ɽС·
// qfy 7/9/1996

inherit ROOM;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
����һ��ͨ��ɽ��ɽ��С·����;�羰��֮���ģ�����������ε�
�������԰ٻ����ޡ���������������
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"yunu",
		"southdown" : __DIR__"xiaolu2",
	]));

	set("outdoors","huashan");

	set("cost", 2);
	setup();
}


