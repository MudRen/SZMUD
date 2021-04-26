
// Filename:   /jueqinggu/duanchang.c
// by jiuer 08/2001

#include <ansi.h>
inherit ROOM;
string look_cliff();
string look_zi();
int do_jump(string arg);

void create()
{
	set("short",YEL"�ϳ���"NOR);

	set("long",@LONG
����ǰ��羰���ģ��������վ���ɽ��������Ԩ����Ԩ����������
���������ס�����(cliff)�����������֣� ��̦ʯ��������ԼԼ��
����һ��С��(zi)��ɽʯ��������׵�����Ԩ�����ھ��������㣬
�������书�����µ���Ҳ���ײ������ˡ�
LONG);
    set("exits",([ 
		"southdown" : __DIR__"houshan",
		]));    
	set("item_desc", ([
		"cliff" : (:look_cliff:),
		"zi" : (:look_zi:),
		]));
	
	set("cost",6);          
	set("outdoors","jueqing");
	setup();      
}

string look_cliff()
{
        return
        "\n"
        "    ********        \n"
        "    *  ��  * \n"
        "    *      * \n"
        "    *  ��  * \n"
        "    *      * \n"
		"    *  ��  * \n"
        "    ******** \n"
		             "\n\n";
}

string look_zi()
{
        return
                "\n"
				"   =================          \n"
                "   |   ʮ     ��   |          \n"
                "   |   ��     ��   |          \n"
                "   |   ��     ��   |     С ��\n"
                "   |   ��     ��   |     �� ��\n"
                "   |               |     Ů ǧ\n"
                "   |   ��     ��   |     �� ��\n"
                "   |   ��     ʧ   |     ��   \n"
                "   |   ��     ��   |     �� ��\n"
                "   |   ��     Լ   |     �� ��\n"
                "   |===============|     �� ��\n"
                "                         �� ��\n\n";
}

void init()
{
  add_action("do_climb","climb");
  add_action("do_climb","pa");
  add_action("do_jump","jump");
}

int do_climb(string arg)
{
        object me = this_player();
        
        if( !arg )
                return notify_fail("�������أ��㲻����������\n");
        if(me->query_busy())
                return notify_fail("������!\n");
        if ( arg != "up" ) 
           return notify_fail( "��ֻ����������\n" );

        if(arg =="up")
        {
        message_vision("$N�ֽŲ���˳���ͱ����嶥����ȥ��\n\n\n", me);
        me->start_busy(5);
		
		if(random(me->query_skill("dodge")) <= 70) 
		{
			remove_call_out("drop_down");
			call_out("drop_down",5,me);
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
        tell_object(me, "ͻȻ����һ�������ͱ��ϵ���������ˤ�˸��������ס�\n");
        message("vision", me->name() + "ͻȻ����һ�������ͱ��ϵ���������ˤ�˸��������ס�\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 100, "���ͱ��ϵ�������ˤ����");
        me->receive_wound("qi",  100, "���ͱ��ϵ�������ˤ����");
}

void climb_up(object me)
{
        tell_object(me, "������һ��������Ծ�𣬼�������䣬�����˾���嶥��\n\n");
        me->add("jingli", -50);
        me->move(__DIR__"jueqingfeng");
        message("vision", me->name() + "���������ش���������������\n",
                             environment(me), ({me}) );
}

int do_jump(string arg)
{
	object me = this_player();
    
	if(!arg||arg!= "cliff")
		return 0;

	if(arg == "cliff")
	{
		message_vision("$N�е����˳��ϣ���Ӵ�һ�˰��ˣ���������Ծ��ȵס�\n\n\n", me);

		if ( me->query("dex",1) <= 15 ) {
			message_vision("$N������ˤ���±��ϣ����˼�������׹���̶ˮ�\n", me);
			message_vision("һ���Һ���$N��̶ˮ�����ˡ�\n", me);
		//	me->receive_damage("qi", 100, "���ͱ��ϵ���̶ˮ�������ˡ�");
		//	me->receive_wound("qi",  100, "���ͱ��ϵ���̶ˮ�������ˡ�");
			me->receive_wound("qi", me->query("max_qi")+100, "��̶ˮ��������");
		}
		if ( me->query("dex",1) > 15) {
			me->start_busy(10);
			message_vision("ͻȻ��ͨһ�죬$N����ˤ����һ��ˮ̶֮�С�\n",me);
			me->unconcious();			
			me->move("/d/jueqing/bishuitan");
		}
		return 1;	
	}
}