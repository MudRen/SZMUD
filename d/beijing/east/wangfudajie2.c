//Cracked by Roath
// Room: /d/beijing/east/wangfudajie2.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���Ƿ������ֵ�������֣���ֽ����������ˮ��������
����Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�С
�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wangfudajie",
  "south" : __DIR__"wangfudajie3",
  "west" : "/d/beijing/zijin/donghuamen",
  "east" : __DIR__"liulichang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
