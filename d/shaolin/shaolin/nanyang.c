// Code of ShenZhou
// Room: /d/shaolin/nanyang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǵ�����������Ĺʾӡ������ǲ�����Ϊ�س�Ҫ�壬
���������Ŀ����ر�࣬����Ҳ�����ȫ����¥����ջ����꣬
�����Ӷ��ǡ������˿����٣�����������ɫ�ҴҵĽ������ˡ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-fan" : 1,
]));
	set("cost", 1);
	set("outdoors", "shaolin");
	set("exits", ([ /* sizeof() == 6 */
  "southeast" : __DIR__"majiu",
  "west" : __DIR__"jiulou1",
  "north" : __DIR__"yidao3",
  "south" : __DIR__"hanshui2",
  "east" : __DIR__"kedian1",
  "southwest" : __DIR__"sishu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
