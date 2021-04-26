//Cracked by Roath
// Room: /d/beijing/dongzhidajie.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"guloudajie_e",
	  "south" : __DIR__"chaoyangdajie",
	  "north" : __DIR__"shiweiying",
	]));
    } else {
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"guloudajie_e",
	  "east" : __DIR__"dongzhimen",
	  "south" : __DIR__"chaoyangdajie",
	  "north" : __DIR__"shiweiying",
	]));
    }
}

void create()
{
	set("short", "��ֱ�Ŵ��");
	set("long", @LONG
���Ƿ������ֵĶ�ֱ�Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	fix_exits_for_night(0);
	set("outdoors", "beijing");

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}
