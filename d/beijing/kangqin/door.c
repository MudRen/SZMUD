//Cracked by Roath
// Room: /d/beijing/kangqin/door.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ���
�ϸ���һ����ң����顸�����������ĸ����֡��ſ�վ������������
���Ž��£���ִ�ֵ�������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"tingyuan",
  "north" : "/d/beijing/west/lingjing",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
