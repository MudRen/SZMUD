// Code of ShenZhou
// Room: /d/dali/wlseast2.c
// AceP

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
ɽ���һ����ʯ�ѣ���Χ�������Ŷ�ʮ���ˣ�����һ�����֮��
���˸���С�����ߣ��ߴ����ˣ�����������ũ�����˾�����ˡ�
LONG );

	set("exits", ([
		"down" : __DIR__"wlseast1",
	]));

	set("objects", ([
		__DIR__"npc/snbz": 5,
		__DIR__"npc/sikong": 1,
		]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
