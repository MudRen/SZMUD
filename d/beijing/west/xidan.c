//Cracked by Roath
// Room: /d/beijing/west/xidan.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǳ�����������̺����ܼ��ĵط�������������ϰ������
�ֺŶ�������������̴�֣����Ҵ�Ҳ���ϲ���������ð췿
���������������֣����߾������������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xuanwudajie2",
  "north" : __DIR__"yangliu",
  "east" : "/d/beijing/zijin/xichangan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
