//Cracked by Roath
// Room: /d/beijing/west/fuchengmenjie2.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĸ����Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ����߾��Ǹ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"lingjing",
  "south" : __DIR__"xuanwudajie",
  "west" : __DIR__"fuchengmen",
  "north" : __DIR__"baozhu",
  "east" : __DIR__"fuchengmenjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
