//ROOM: /d/shaolin/shanlu2.c
// jiuer 08/2001

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�����ԫ����ʯͷ�����ݡ����ߴ�Ϊ���㡣������������飬
���ȷ�����Ҫ֧�Ų�ס�ˡ����ﳣ����Щ�����µĺ�����ɽ��ˮ��
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"northeast" : __DIR__"xiaojing1",
		"southdown" : __DIR__"shanlu1",
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}