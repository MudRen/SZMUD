//Cracked by Roath
// Room: /d/beijing/xuanwudajie.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵ������Ŵ�֣���ֽ����������ˮ������������Ϣ����Ⱥ��
�������������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([
		  "north" : __DIR__"xuanwumen",
		  "south" : __DIR__"caishikou",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
