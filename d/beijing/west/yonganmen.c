//Cracked by Roath
// Room: /d/beijing/west/yonganmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ��������������������ĳ��ţ�����ĳ�ǽ�����ƾɣ������ڳ�
���ʣ����ŵĹٱ�ͨ��������Ӫ�������졣���ű�����һ�Ÿ�ʾ (gaoshi)��
���ߵ���·ͨ�����ź��Ұ��š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east"  : __DIR__"tulu_yaza1",
  "west"  : __DIR__"tulu_yaya1",
  "north" : __DIR__"shizilukou",
  "south" : __DIR__"dadao_yas1",
]));

	set("objects", ([
	"/d/beijing/npc/bj_bing":2,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
