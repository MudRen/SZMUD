// August 1 31,2000
// Code by April
// /gumu/mushi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","Ĺ��");

        set("long",@LONG
��һ���������ɵô��˸����䡣�տտ�����һ�������ϲ��з������
ʯ��(coffin)������ʯ�׹׸������ܸ��������泤���Ź�Ĺ�ɵ����ˡ���
�����ߵĹ׸�ȴֻ����һ�룬Ҳ��֪��������ʬ�塣
LONG);

	  set("item_desc",(["coffin" : "�׸��ڲ����֣�����Ů�ľ�����ѹȫ�档����һ����������ˡ�����ʮ����
����Ũī���飬�����Ծ�����������
\n"]));

	  set("exits",(["east" : __DIR__"mudao22"
			 ])
			  );

	create_door("east","���ص�ʯ��","west", DOOR_CLOSED);

	  set("cost",1);

		  setup();
}

void init()
{
        add_action("do_lift","lift");
}

int do_lift(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg == "" ) return 0;

        if( arg == "coffin") 
        {
        message_vision("$N����Ծ����У�������������Ȼ����������һ�ֵİ�������ǽ�����ס��ת�����ᣬֻ������һ�죬�׵�ʯ��Ӧ�ֶ���...... 
		\n\n",me);
        set("exits/enter", __DIR__"mishi");
        remove_call_out("shut_door");
        call_out("shut_door",15,me);   
                return 1;
        }
        else
                return notify_fail("��Ҫ��ʲô��\n");
}

void shut_door()
{
        tell_room(this_object(),"��һ������׵�ʯ����������ˡ�\n");
        delete("exits/enter");
}
