//Cracked by Roath
// Room: /d/beijing/youandajie.c

inherit ROOM;

void fix_exits_for_night(int is_night);

void create()
{
	set("short", "�Ұ��Ŵ��");
	set("long", @LONG
���Ƿ������ֵ��Ұ��Ŵ�֣���ֽ����������ˮ������������Ϣ����Ⱥ��
�������������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}

void fix_exits_for_night(int is_night)
{
    object me = this_object();
    if (is_night) {
	me->set("exits", ([ /* sizeof() == 3 */
	      "north" : __DIR__"caishikou",
	]));
    }else{
	me->set("exits", ([ /* sizeof() == 4 */
	      "north" : __DIR__"caishikou",
	      "south" : __DIR__"youanmen",
	]));
    }
}
