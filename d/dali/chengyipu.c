// Code of ShenZhou
// Room: /d/newdali/chengyipu.c

inherit ROOM;

void create()
{
	set("short", "Ѧ�ǳ�����");
	set("long", @LONG
����һ�����ֺŵĹ���ׯ����������˸�ʽ���������
�񡢾˿������Ƥ������춷��л������ȹ��ˮ��ɫ
�ް�������ɫ�Ż���������һ���㡣
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bossxue" : 1,
]));
	set("cost", 1);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
