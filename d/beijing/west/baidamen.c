//Cracked by Roath
// Room: /d/beijing/west/baidamen.c

inherit ROOM;

void create()
{
	set("short", "�׸�����");
	set("long", @LONG
����������ͬ���һ����լ�ӣ���˵�����һ������
���������ˣ��ճ������Ķ��ǲ����Ͽ������ˡ����ڴ���
���գ����������յ��ɫ������������Լ����������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baiqianyuan",
  "south" : __DIR__"yangliu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
