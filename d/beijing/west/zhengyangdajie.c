//Cracked by Roath
// Room: /d/beijing/west/zhengyangdajie.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
���Ƿ������ֵ����������֣���ֽ����������ˮ����
��������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա���
��С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tianqiao2",
  "north" : __DIR__"zhengyangmen",
  "south" : __DIR__"shizilukou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
