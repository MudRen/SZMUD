// Filename:   /d/jueqinggu/shishi1.c ʯ��1
// Code:       Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ʯ��");
	set("long",@LONG
����һ�䲻���ʯ�ң�����ֻ�ڷ�һ�Ŵ�ľͷ���ӡ�ʯ�ҵĶ���
�ǳ��ȣ��ٹ�ȥ���Ǵ����������ǽ��������Ƿ���(door)ȴ�����š�
LONG);
	set("exits",([ 
		"east" : __DIR__"changlang2",
		]));

	set("item_desc", ([
			"door" :   "һ�Ƚ����ŵķ��š�\n",
		  ]));
	set("cost",1);
	setup();	
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me= this_player();
	if(!arg)
		return 0;
	
	if(arg=="door"|| arg =="men")
	{
		message_vision(HIY"$N�������������죬��ǰ�׹��������˱������Է�����������ͦ����\n"NOR,me);
			
			if((int)me->query_dex()> (20+random(5))) 
			{
				message_vision("$N����̤���ż�֮�⣬�������ż����ذ���һ�㣬�����������ء�\n",me);
				message_vision("�š���֨��һ�����ˡ�\n",me);	
				set("exits/enter",__DIR__"jianfang");

				remove_call_out("close_door");
				call_out("close_door",10,me);
				return 1;
			}
			else if ( (int)me->query_dex() > (20+random(1))) 
			{
                message_vision("$N������ܿ���ȴ�ѱ�����һ�������ᴩ�ұۣ���һ���ҽС�\n", me);
                me->add("qi", -50);
                me->unconcious();
                return 1;
			}

        else {
                message_vision("$N��ܲ������˱����������϶Դ����������ڵ��ϡ�\n", me);
                me->receive_damage("qi", 50, "������������");
                me->die();
                return 1;
		}
	}
	return 0;
}

void close_door()
{
   tell_room(this_object(),"����һ��������֡���֨��һ�¹����ˡ�\n");
   delete("exits/enter");
}