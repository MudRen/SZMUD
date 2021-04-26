// Code of ShenZhou
// Room: /d/mingjiao/mguangchang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��ľ��㳡");
	set("long", @LONG
�⴦����һƬ���֣����о�ľ����ӿ��Ѷ����������ܣ�����һ��С
��ͨ��ɽǰ���㳡���Ǳ����������Ĳ�ľ��Χ�š��㳡������������ż�
����ľ����ϸһ�������滹װ��������
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shenchu",
  "north" : __DIR__"milin40",
]));
	set("objects",([
		__DIR__"npc/wencangsong" : 1,
	]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
