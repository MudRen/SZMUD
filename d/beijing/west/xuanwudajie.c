//Cracked by Roath
// Room: /d/beijing/west/xuanwudajie.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵ������Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"lingjing",
  "south" : __DIR__"xuanwudajie2",
  "north" : __DIR__"fuchengmenjie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
