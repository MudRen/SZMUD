//Cracked by Roath
// haidao_s.c ���˺���


#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���˺���", ({ "shang haidao", "haidao" }));
	set("long", 
                "һ���װͰ͵ĺ�����������ɫ�ݻƣ������������ˡ�\n");
	set("gender", "����");
	set("age", 44);
	set("attitude", "heroism");
        set("shen_type", -1);

        set("chat_chance", 5);
        set("chat_msg", ({
                "�����޺޵�˵���ǰ�һ￴�������ˣ��Ͱ�������������ϣ�\n",
                "�����������ֵ�˵����ү�ҳ�������Ƕ��ɵ���\n",
                "����ҧ���гݵ�˵�������죡\n",
		  }) );

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 140);

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
	        command("nomatch " + me->query("id"));
		me->set_temp(this_object()->query("id"), 1);
	}
}

#include "/d/xiakedao/npc/xkdnpc.h"
