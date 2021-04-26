// Code of ShenZhou
#include <room.h>

inherit ROOM;
void create()
{
       set("short","ս��");
       set("long", @LONG
���������ĺ��棬���硸������������ߴ���������һ������һ������
�ô������ͻȻһ�����˴��������������˵Ĵ��Ʒ��� 
LONG
     );

	set("invalid_startroom", 1);
	set("cost", 5);
        set("outdoors", "quanzhou");
        setup();
}

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

