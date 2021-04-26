// Code of ShenZhou
// Room: /city/bingqiku.c
// YZC 1995/12/04 
//Jay 2/4/97

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǽ�����ԼĪ���ɼ�����һ���ʯ�ң�ǽ�ںͶ��嶼�Ǵ�ʯ
������ǽ�������һֻ��Ͱ�������ŵ��ľ��ǳ�����ù��������ǽ��
����һ��С��(window)��
LONG
	);

	set("cost", 0);
	set("no_fight", 1);
	setup();
}
void init()
{
	add_action("do_fight", "fight");
	add_action("do_fight", "kill");
	add_action("do_fight", "hit");
	add_action("do_fight", "throw");
        add_action("do_visit", "look");

	if (this_player()->query_condition("embedded")>0)
		this_player()->apply_condition("embedded", 0);
}

int do_visit(string arg)
{
        object env, me = this_player();

        if (arg != "window") return 0;

        if(!( env = find_object("/d/city/bingyin")) )
        env = load_object("/d/city/bingyin");

        tell_room(env, "�㷢����һ˫�۾��ڴ��ӱ���������\n");
        return "/cmds/std/look"->look_room(me, env);
}
int do_fight(string arg)
{
	write("���˫�ȷ�����Ҳ�᲻������\n");
	return 1;
}
