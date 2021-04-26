//Cracked by Roath
// haidao_s.c С����


#include <ansi.h>
inherit NPC;

void create()
{
	set_name("С����", ({ "xiao haidao", "haidao" }));
	set("long", 
	        "һ��С��������δ���ˣ������۽����Ѿ�¶�������ࡣ\n");
	set("gender", "����");
	set("age", 14);
	set("attitude", "heroism");
        set("shen_type", -1);

        set("chat_chance", 5);
        set("chat_msg", ({
                "С�����޺޵�˵���ǰ��ϼһ�����С���Ͱ�������������ϣ�\n",
                "С�����������ֵ�˵��Сү�ҳ�������Ƕ��ɵ���\n",
                "С����ҧ���гݵ�˵�������죡\n",
		  }) );

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 180);

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
        if (me->query_temp(this_object()->query("id")) == 0 )
	{	
	        command("cold " + me->query("id"));
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
