//Cracked by Roath
// Room: /d/beijing/east/fulanting.c

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
  "eastup" : __DIR__"shandao2",
  "southwest" : __DIR__"shandao5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
