//Cracked by Roath
// Room: /d/beijing/east/wangfudajie.c

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
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wangfudajie2",
  "north" : __DIR__"zhaoyangdajie2",
  "east" : __DIR__"qianju",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
