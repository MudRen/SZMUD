//Cracked by Roath
// Room: /d/beijing/fuchengdajie_n.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĸ��������֣���ֽ����������ˮ������������Ϣ����Ⱥ
���������������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ
�ߡ��ֶ����Ǿ���������Ǯׯ����ԴǮׯ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"fuchengdajie",
	  "north" : __DIR__"xizhidajie",
	  "east"  : __DIR__"baoyuan",
	]));
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}


