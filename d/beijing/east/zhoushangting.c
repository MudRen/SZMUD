//Cracked by Roath
// Room: /d/beijing/east/zhoushangting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�������ͤ�е�һ�������ܾ�ɫ�����������ˡ�ͤ������
һ��ʯ��������ʯ�ʣ���������Ϣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shandao4",
  "southeast" : __DIR__"shandao6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
