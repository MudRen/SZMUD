//Cracked by Roath
// Room: /d/beijing/west/baixixiang.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
���ǰ׼Ҵ�լ�����᷿�������ɨ���˳���Ⱦ���ɾ�
�ó��档��ǽ������һ�������ľ�ܣ�����������µİ�
����һЩ�Ŷ����Ӵ�������ȥ�����Կ���ǰԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"baiqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
