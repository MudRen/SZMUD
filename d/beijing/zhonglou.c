//Cracked by Roath
// Room: /d/beijing/zhonglou.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"gulou",
	  "up" : __DIR__"zhonglou2",
	]));
    } else {
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"gulou",
	  "north" : __DIR__"andingmen",
	  "up" : __DIR__"zhonglou2",
	]));
    }
}

void create()
{
	set("short", "��¥");
	set("long", @LONG
��������¥�߾������࣬��ȫשʯ�ṹ������Ԫ����Ԫ��
�䡣��¥�ϵĴ�ͭ��һ�������죬�ͻ������һ�������������
��˵����һ�������������������˵��
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
