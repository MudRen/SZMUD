// Code of ShenZhou
// Room: /d/dali/yuxuguan1.c

inherit ROOM;

void create()
{
	set("short", "�����ǰ");
	set("long", @LONG
����һ����ۣ���ǰ����д�š�����ۡ��������֣�����һ��
��ˮ������С����������������ʵ���������Եĺõط���
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 2);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/daogu" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuxuguan2.c",
  "south" : __DIR__"quan2",
]));

	setup();
	replace_program(ROOM);
}
