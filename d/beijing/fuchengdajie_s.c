//Cracked by Roath
// Room: /d/beijing/fuchengdajie.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĸ��������֣���ֽ����������ˮ������������Ϣ����Ⱥ
���������������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ
�ߡ�������������ҩ��ش��ã��ֶ�����һ�ҵ��̡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"xuanwumen",
	  "north" : __DIR__"fuchengdajie",
	  "west"  : __DIR__"huichun",
	  "east"  : __DIR__"dangpu",
	]));
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
