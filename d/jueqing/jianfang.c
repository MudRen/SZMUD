// Filename:   /d/jueqinggu/jianfang.c ����
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <condition.h>
inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
�������ϡ����ϡ����ϡ����о����������У�ʽ�����࣬����
�߳ߣ���̽����磬�е�����߲����еĺ�����ˣ�ֱ�������ۻ���
�ң������Ϲ���һ���� ��hua��������ȥ�е㲻�ɸ�֡�����һֻ��
ƿ�в��ŵ�һ�Ի���flower����ֻ�ǲ�����߰��㣬�㲻��˳����ȥ
����order��һ�¡����ţ�door�������š�
LONG);
    /*    set("exits",([ 
                "north" : __DIR__"shishi1",
                ]));
*/
		set("item_desc", ([
			"hua" :    "һ�޷�ɽˮ���ʾ��\n",
			"door" :   "һ�Ƚ����ŵķ��š�\n",
			"flower" : HIM"һ�Խ������Σ������쳣���黨��\n"NOR,
			]));
        
		set("cost",1);
        setup();
}

void init()
{
	add_action("do_order","order");
	add_action("do_pull","pull");
//	add_action("do_burn","burn");
}

int do_order(string arg)
{
	object me = this_player();
	
	if ( !arg || arg != "flower" && arg != "hua")
		return 0;

	if (arg=="flower"||arg=="hua") 
	{	
		message_vision("$N��һ����ץ��֦����ָȴ�����̴������¡�\n", me);	
		me->apply_condition("qh_poison",100);
		message_vision("$N�����黨������\n", me);
		return 1;
	}
	else
		return notify_fail("�廨���������ģ�\n");
}

int do_pull(string arg)
{
        object me = this_player();
        if(!arg)
                return 0;
        if(arg = "door") 
        {
                message_vision("$N��������һ�����š�\n",me);
                message_vision("�š�֨ѽ����һ�����ˡ�\n\n",me);
                set("exits/out",__DIR__"shishi1");
                remove_call_out("close_door");
                call_out("close_door",10,me);
        }
        return 1;
}
void close_door()
{
        tell_room(this_object(),"�š�֨ѽ����һ���ֹ����ˡ�\n");
        delete("exits/out");

}
/*
int do_burn(string arg)
{
	object ob , me = this_player();
	if(!arg || arg != "hua")
		return notify_fail("��Ҫ��ʲô��\n");
	if( !present("fire",me)) return 0;
	if( present("fire",me) && (arg == "hua"))
	{	write("���ȼ�˻��ۣ����ֹ�ȥ��ȼ�˻���һ�ǡ�\n");
	    write("��̼䣬�����ջ��˴��أ���ǽҲ���ճ�һ��Ƭ���ۡ�\n");
	    write("��ػ���֮��¶��һ�ε�������\n");
	   	write("���һ����һ�ѽ𵶴Ӱ�ػ�����ѵ����ϡ�\n");

		ob = new("/d/jueqing/obj/jindao");
		ob->move("/d/jueqing/jianfang");
		ob->set_temp("marks/��", 1);
		
	    add("jindao_count", -1);	
	}
		return 1;
}
*/