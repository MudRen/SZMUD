// Code of ShenZhou
// shandong2.c �����
// qfy 96/6/30

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ��Сɽ���������и�СȪ�ۣ�������������һ�ɺ��Ȫ�����
���Ƕ���������磬�ƺ�Դ���ǹ�Ȫˮ�����Ȫ���Ա��и�ڼڼ��������
����װ��ʯ��(statue)���������ػ���Ȫ��������һƬ��ɽҰ�֡�
LONG
        );

	set("exits", ([
                "out" : __DIR__"yelin1",
        ]));

        set("resource/water", 1);

	set("item_desc",([
	    "���Ȫ"	:
            "һ�����ľ�Ȫ(wine)��ɢ����Ũ���ķ��㡣����Ǻ���ǲɼ��ٹ�\n"
            "������ɵĺ���ơ�\n",
	    "ʯ��"	:
	    "һ���ɶ��칤��ʯ����󣬲�֪��λ��ڴ˻�ɽ����֡�\n",
	    "statue"	:
	    "һ���ɶ��칤��ʯ����󣬲�֪��λ��ڴ˻�ɽ����֡�\n"
        ]));

	set("cost", 2);
        setup();
}

void init()
{
        add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_pat", "pat");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me = this_player();

        if( !arg || arg!="wine" ) 
       	    return notify_fail("��Ҫ����ô����\n");

        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if ( current_water<max_water && me->query_temp("marks/��") < 20 ) {
            me->set("water", current_water+30);
    	    me->add("neili", 10);
	    me->receive_damage("jing", 20);	
	    me->add_temp("marks/��", 1);
            message("vision", me->name()+"����һ�Ѻ���ƺ�����ȥ��\n"
            , environment(me), ({me}) );
            write("������һ�Ѻ���ƺ�����ȥ����һ���ظ����������ۣ��ʷ��ޱȡ�\n");
	    write("��ͻȻ����һ������ֱ����ͥ��ԭ���˾ƾ�������С�в��档\n");
	    write("ͬʱ������һ�ɾ���ð������������ЩƮƮȻ�ĸо���\n");
        }
        else if ( me->query_temp("marks/��") >= 20 ) {
	    write("���Ѻ��˺ö����ƣ���������������˰ɡ�\n");
	}
	else write("��֮ǰ�Ѻ��˺ö࣬�Ѿ���Ҳ�Ȳ����ˡ�\n");

        return 1;
}

int do_fill(string arg)
{
	object me = this_player();

	message("vision",me->name()+"��ȡЩ����ƴ��ߡ�\n", environment(me), ({me}));
	if ( me->query_temp("marks/ȡ") ) {
	   message_vision("ֻ����һ��ŭ��һ��Ⱥ���ӷ�ŭ�س��˽�����Χ��$N�����֡�\n", me);
	   message("vision","���"+me->name()+"����ñ������ˣ��������ر��������⡣\n", environment(me), ({me}));
	   write("����㱻��ñ������ˣ��������ر������������ڻ�ɽҰ���\n");
	   me->add("eff_qi", -40);
	   me->add("qi", -40);
	   me->delete_temp("marks/ȡ");
	   me->set_temp("marks/��", 6);
	   me->move(__DIR__"yelin2");
	   me->unconcious();
	}
	else {
           message_vision("һֻ���ӳ��˹�������$Nҡ�ָ߽У�ʾ��$N��Ҫȡ�ߺ���ơ�\n", me);
           me->set_temp("marks/ȡ", 1);
	}

	return 1;
}

int do_pat(string arg)
{
	object me = this_player();

	if( !arg || arg != "statue" ) 
	   return notify_fail( "��Ҫ��ʲô��\n" );

	message_vision("$N��ʯ��ͷ��������һ�¡�ͻȻʯ���Ҳ��¡¡����һ��¶����������\n", me);
	set("exits/enter", __DIR__"yunuci");
        remove_call_out("close");
        call_out("close", 5, this_object());

	return 1;
}

void close(object room)
{
    message("vision","С�ź�¡¡�ؽ����������ַ�ס����ڡ�\n", room);
    room->delete("exits/enter");
}
	
