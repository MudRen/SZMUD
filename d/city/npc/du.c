// Code of ShenZhou
//Maco 1999/12/28
// xQin 7/00

#include <ansi.h>
inherit NPC;
inherit F_DEALER;
string ask_me();


void create()
{
        set_name("���ϰ�", ({ "du laoban", "du", "laoban" }));
	set("title", "�ƹ��ϰ�");
	set("shen_type", 1);
	set("str", 20);
	set("con", 20);
	set("dex", 20);
	set("gender", "����");
	set("age", 45);
	set("long",
		"���ݸ����ƹݵ��ϰ壬������̩֮����\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/niurou",
		__DIR__"wine/huadiao",
		__DIR__"wine/nuerhong",
		__DIR__"wine/zhuangyuan",
		__DIR__"wine/zhuyeqing",
		__DIR__"wine/longyan",
		__DIR__"wine/xiangxue",
	}));
	set("inquiry", ([
	]));  
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "ؤ��"
		&& environment(ob)==find_object("/d/city/jiuguan2.c"))
		{
			remove_call_out("greeting");
			call_out("saying",1,ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
//	add_action("do_list", "list");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	command("say ��λ"+RANK_D->query_respect(ob)+"��������");

}


int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
void saying(object ob)
{
        if (!ob || environment(ob) != environment()) 
        return;
	command("hmm");
	command("say ��������������Ҫ����������ʲô��");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}
void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/city/jiuguan");
	message("vision","���ϰ�Ҵ�ææ�İ�" +  ob->query("name") +
		"����������\n", environment(ob), ob);
}
