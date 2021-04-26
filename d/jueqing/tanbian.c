// /d/jueqing/tanbian.c ̶��
// By jiuer

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"̶��"NOR);
	set("long",@LONG 
����ɽ����Χ�����ƣ������������ڻ��У�������һ�ڴ�֮��
��ͷ���������ȣ��Ѽ����ա���̶���龰��ֻ����������������ʮ��
�䳲��һ������(suo)�ӹȿ�ֱ�������� ˮ̶����������ݺ���ӵĽ�
ӡ��̶������һ����ѣ����δϨ��
LONG);
	set("outdoors","jueqing");
	set("item_desc", (["suo" : 
	                 "����һ������Ƥ��ɵ�����(climb)��\n"])); 
	set("cost",1);
	setup();
}
void init()
{
	add_action("do_jump","jump");
	add_action("do_climb","climb");
}
int do_jump(string arg)
{
	object me = this_player();
	if(!arg)
		return 0;

	if(arg == "tan") 
	{
		message_vision("$N������̶��ֱ���Ǳȥ��\n",me);
		me->add("jingli",-50);
		message_vision("$N�������£��͵���ֻ��һ�ɼ�������ȥ����������Ȼ��һ����\n",me);
		set("exits/up",__DIR__"bingyao");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;
	}
}

int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return notify_fail("��Ҫ���Ķ�����\n");

        if (me->query_busy())
                return notify_fail("����æ���ء�\n");

        if( arg=="suo")
        {
        message_vision("$N����ץ��������΢һ�˶��������Ѵ����������ࡣ\n", me);
        me->start_busy(5);

        if (random(me->query_skill("dodge")) < 50){
        remove_call_out("drop_down");
        call_out("drop_down", 5, me);
        return 1;
        }
        
        message("vision", me->name()+"һ�������ʧ���������ˡ�\n", environment(me), ({me}) );
        remove_call_out("climb_up");
        call_out("climb_up", 5, me);
        return 1;
        }
}
void drop_down(object me)
{
        tell_object(me, "ͻȻ��һʧ�֣����ͱ��ϵ���������ƨ�����ص�ˤ�ڵ��ϡ�\n");
        message("vision", me->name() + "ͻȻһʧ�֣����ͱ��ϵ���С����ƨ�����ص�ˤ�ڵ��ϡ�\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 50, "���ͱ��ϵ�������ˤ����");
        me->receive_wound("qi",  50, "���ͱ���������ˤ����");
}
void climb_up(object me)
{
        tell_object(me, "����ץ�����������Ṧ�������ϣ�����ʱ����������ȡ�\n");
        me->add("jingli", -50);
        me->move(__DIR__"duanchang");
        message("vision", me->name() + "���������ش���������������\n",
                             environment(me), ({me}) );
}
