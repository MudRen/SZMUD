// Code of ShenZhou
// /d/shenlong/ship.c
// ywz 09/18/96
#include <room.h>

inherit ROOM;
void create()
{
       set("short","����");
       set("long", @LONG
���������ĺ��棬���硸������������ߴ���������һ������һ�������ô�
������ͻȻһ�����˴��������������˵Ĵ��Ʒ������Ҫ��������������ˣ�
���Ǵߴ����Ͻ�ҡ���߳��Ź�ط��ɡ�
LONG
     );
	set("cost", 5);

//	set("exits", ([
//		"east" : __FILE__,
//		"west" : __DIR__"dahai2",
//		"south" : __DIR__"dahai3",
//		"north" : __DIR__"dahai4",
//	]));
        setup();

}

/*
int valid_leave(object me, string dir)
{
        if ( dir == "west")
            me->add_temp("mark/steps",1);
        if ( dir == "east")
            me->add_temp("mark/steps",-1);
	if ( dir == "north")
	    me->add_temp("mark/nsteps",1);

        if (me->query_temp("mark/steps") == 10)
         {
	    me->move("/d/shenlong/tanggukou");
            me->delete_temp("mark/steps");
	     return notify_fail("�����㿴����ǰ����½�أ�����л��л�� ��\n");
         }

     if (me->query_temp("mark/steps") == -10)
            {
	       me->move("/d/shenlong/haian");
           me->delete_temp("mark/steps");
	     return notify_fail("�����㿴����ǰ����½�أ�����л��л�� ��\n");
	}

      if (me->query_temp("mark/nsteps") == 10)
         {
	    me->move("/d/shenlong/lushunkou");
	    me->delete_temp("mark/nsteps");
	     return notify_fail("�����㿴����ǰ����½�أ�����л��л�� ��\n");
         }


        return ::valid_leave(me,dir);
}

void init()
{
	object me = this_player();

	if( interactive(me = this_player()) )
	{
	    remove_call_out("arrive");
	    call_out("arrive", 10);
	}

}

void arrive()
{
	message("vision", "���˵������½�������ϰ��ɡ���\n",this_player());
	this_player()->move("/d/shenlong/tanggu");
}
*/

int valid_leave(object me, string dir)
{
        object room;

        if ( !::valid_leave(me, dir) )
                return 0;

        if(!(room = find_object(__FILE__)) )
                room = load_object(__FILE__);
        if(objectp(room))
        {
                room->add_temp("person_inside", -1);
                if ((int)room->add_temp("person_inside", -1) <= 0)
                        room->delete_temp("person_inside");
        }

        return 1;
}

