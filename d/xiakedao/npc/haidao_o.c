//Cracked by Roath
// haidao_s.c �Ϻ���


#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�Ϻ���", ({ "lao haidao", "haidao" }));
	set("long", 
	        "һ�����ϵĺ�������Ȼ����һ����ˣ��������װͰ͵ġ�\n");
	set("gender", "����");
	set("age", 74);
	set("attitude", "heroism");
        set("shen_type", -1);

        set("chat_chance", 5);
        set("chat_msg", ({
                "�Ϻ����޺޵�˵���ǰ�С���������ϣ��Ͱ�������������ϣ�\n",
                "�Ϻ����������ֵ�˵�������ҳ�������Ƕ��ɵ���\n",
                "�Ϻ���ҧ���гݵ�˵�������죡\n",
		  }) );

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 230);

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
	        command("sneer " + me->query("id"));
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
