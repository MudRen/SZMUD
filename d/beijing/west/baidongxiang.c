//Cracked by Roath
// Room: /d/beijing/west/baidongxiang.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
���ǰ׼Ҵ�լ�Ķ��᷿�������ɨ���˳���Ⱦ���ɾ�
�ó��档��ǽ������һ�������ľ�ܣ�����������µİ�
����һЩ�Ŷ����Ӵ�������ȥ�����Կ���ǰԺ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baiqianyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
