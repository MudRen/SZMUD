//Cracked by Roath
// Room: /d/beijing/west/jingsanjie.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ��λ�ڹ�¥������ı��֣�ʮ��Ƨ�����䣬·�ϼ�������
��ʲ�����ˣ��������¥�����������ʱ�������������ֶ�����һ��
С�����м������֡���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"gulou",
  "east" : __DIR__"huoshenmiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
