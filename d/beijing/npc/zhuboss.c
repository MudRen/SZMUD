//Cracked by Roath
// zhuseller ���ƹ�

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("���ƹ�", ({ "yang zhanggui", "yang" }));
        set_color("$YEL$");
	set("title", "�鱦���ƹ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 35);
	set("long", "���ƹ�һ�������ܸɵ����ӣ���ʽ�����鱦��һ�۱���˵����Ǯ����\n");
	set("combat_exp", 20000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		  "/d/city/obj/mirror",
		  "/d/city/obj/pring",
                  "/d/city/obj/necklace",
	}));
            	
	setup();
        add_money("silver", 20);
	add_money("coin", 100);
}

void init()
{
	object ob;

        ::init();
        if ( interactive(ob=this_player()) ) {
                remove_call_out("greeting");
		call_out("greeting", 1, ob);
        }

        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("say ��ӭ���٣���λ"+RANK_D->query_respect(ob)+"�����ιۡ�С�걣֤�����ʵ��");
}
