// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;
int do_rowing();
void create()
{
        set("short", "ľ����");
        set("long", @LONG
��վ��ľ����ҡҡ�ڰڵ�������ǰ��(rowing)����ˮ��ʱ����������������
��Ūʪ�ˡ�
LONG
        );

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
}
void init()
{
   add_action("do_rowing","rowing");
}
int do_rowing()
{
    object ob, me = this_player();
    int check, wait_time = 0;
    remove_call_out("open_up");
    message_vision("$Nʹ���ذ�ľ����ǰ��ѽ����ѽ��\n", me);
    me->receive_damage("jingli", 15, "��ˮ������");
    me->set_temp("marks/��", 1);
    if ( me->query_temp("marks/��") && interactive(me) && !me->is_fighting()) {
           call_out("open_up", random(10)+10, me);
        }
    return 1;
}
int open_up(object me)
{
        message_vision("$N���˰��죬ľ����춿����ˡ�\n", me);
        set("exits/up", __DIR__"sulew");
	call_out("close_up", 3, me);
           remove_call_out("open_up");
	this_player()->delete_temp("marks/�� ");
	return 1;
}
int close_up(object me)
{
        message_vision("ľ���ֱ��嵽������ȥ�ˡ�\n", me);
        delete("exits/up");
        this_player()->delete_temp("marks/�� ");
	remove_call_out("open_up");
        return 1;
}
