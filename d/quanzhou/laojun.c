// Code of ShenZhou
// laojun.c �Ͼ���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�Ͼ���");
	set("long", @LONG
����ɽ���߶��������ƣ���Χ�����������̲����𣬷羰���ˡ����е���
�����Ͼ�ʯ�񣬹ʳ��Ͼ��ҡ�����һ��Ȼ��ʯ�������ɡ�ʯ��������ϥ������
ƾ��������ƽ�ӣ�˫�����磬����Ц�ݣ����׷ɶ���һ�����˴��飬���ֵ���
̬�������ƣ��������Ͼ��ǣ��Ե�һ�ٶ�����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"eastup" : __DIR__"nantai",
		"southdown" : __DIR__"qianshou",
	]));
        set("fjing", 1);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 5);
        setup();
}

void init()
{
	add_action("do_touch", "touch");
	add_action("do_touch", "mo");
}

int do_touch(string arg)
{
	object me = this_player();
	int karma;

	if ( !arg || arg == "" ) return 0;

	if ( arg == "nose" || arg == "bi" ) {
		if ( me->query_temp("marks/laojun") ) {
			write("�㻹û������\n");
			return 1;
		}

		message_vision("$N�Ÿ߽ż⣬Ц�����������ȥ�������Ͼ���ı��ӡ�\n", me);

		karma = random(40 - me->query("kar"));
		if ( karma < 0 ) karma = 0;
		me->set_temp("apply/karma", karma);
		me->set_temp("marks/laojun", 1);
		return 1;
	}

	return 0;
}
