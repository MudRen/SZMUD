//Cracked by Roath
// Room: /d/beijing/zhengyangdajie.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�����Ǿ��Ƿ������ֵĵضΣ��������ǵ�Ҫ����Щ��������ȺҲ����������
�ֱ�����ˣǹ���յġ�Ҳ��ЩС̯������������֮���С�ԡ��������Կ�����
���ŵĳ�¥�������������ŷ���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zhengyangmen",
  "south" : __DIR__"shizilukou",
  "west"  : __DIR__"tianqiao",
  "east"  : __DIR__"chongwendajie",
]));

	set("objects", ([
	__DIR__"npc/foodseller" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}
