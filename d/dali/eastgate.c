// Code of ShenZhou
// Room: /d/dali/eastgate.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ǵ���ǵĶ��ţ���ʯ��ǽ�Ͽ��ˡ�������������
��׭�֡��ſ�վ�˼����¼������ı�ʿ����ɫĮȻ�ؿ���������
���ˡ�
LONG
	);
	set("outdoors", "dali");
	set("cost", 1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dahejie1",
  "east" : __DIR__"guandao9",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dalishibing" : 3,
  __DIR__"npc/dalijunguan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
