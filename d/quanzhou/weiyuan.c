// Code of ShenZhou
// Room: /d/quanzhou/weiyuan.c

inherit ROOM;

void create()
{
	set("short", "��Զ¥");
	set("long", @LONG
����Ȫ�ݵı��ų�¥����ʯ��������¥̨����쳣��Ρ������Ĺ��γ���
�Ϸ����š�Ȫ�ݡ�����������֡���ǽ������һ�Źٸ���ʾ(gaoshi)�����˴�
�ž��Ǳ���������᫵���Դɽ���ˡ�
LONG
	);
	set("item_desc", ([ ]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/bing" : 2,
  __DIR__"npc/wujiang" : 1,
]));
	set("cost", 1);
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanlu6",
  "south" : __DIR__"citong_n1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
