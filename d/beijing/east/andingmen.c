//Cracked by Roath
// Room: /d/beijing/east/andingmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǳ������ڳǾŴ�����г��������������֮һ--����
�š���ǽ������������䣬ȫ����ש�������ɣ����Ŷ�ҲΪש
��Ͳ�ǣ�ʮ�ּ�����ۡ������ǵ�ʤ�ţ����������ǵ�̳�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"zhongtianlou",
  	"up" : __DIR__"andingmenlou",
//	"north" : __DIR__"ditan",
	]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
