// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ٹȵ�����������һ������������������ʯ�̵ĵأ�����
��ǽ���ŵĵ�ǹ�ܣ�ʮ�˰����������ȫ������һ�Ű�������������
��һյ���Ա��ǹ�������̫ʦ�Ρ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"wjg2.c",
		"east"  : __DIR__"wjg5.c",
	]));

	set("objects", ([
		__DIR__"npc/zhongwanchou": 1,
	]));

	set("cost", 1);
	setup();
}
