//Cracked by Roath
// Room: /d/beijing/east/guanxiangtai.c

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����̨���������Ͻ�����в��в��ټ�����������ѧ��
����������ǡ��ض���֮�ࡣ������Ա��Ҫ�ƶ�����������
������Ԥ�⼪��Ī��Ҫ��������̨�е������豸��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dongchangan2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
