// Code of ShenZhou
// Room: /d/dali/sangong3.c

inherit ROOM;

void create()
{
	set("short", "˾ͽ��");
	set("long", @LONG
һ���徲�����ã���ɨ�øɸɾ�����˾ͽһ�㸺�����ѡ�ε���
�鹤�������������ľ�ѻ���ʱ�й�Ա���˰���ӡ�����ĵ��ǰ��
����ǲ���εع��ɡ�
LONG
	);
	set("objects", ([
		__DIR__"npc/hua-hegen" : 1,
		]));

	set("exits", ([
		"north" : __DIR__"sangong",
		]));

	set("cost", 1);
	set("no_clean_up", 0);
	set("wangfu", 1);

	setup();
}
