//Cracked by Roath
// Room: /d/beijing/east/guanmiaoting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�������ͤ�е�һ�������ܾ�ɫ�����������ˡ�ͤ������
һ��ʯ��������ʯ�ʣ���������Ϣ���Ա���һ���Ჱ�������ഫ��
��ĩ�ʵ۳�������֮����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shandao6",
  "southdown" : __DIR__"xiaojing3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
