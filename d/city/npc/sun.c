// Code of ShenZhou
// sun. ���ϰ�

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_DEALER;

string ask_me();

void create()
{
	set_name("���ϰ�", ({ "sun laoban", "sun" }));
        set_color("$YEL$");
	set("title", "�챦���ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 20);
	set("long", "���ϰ�һ�ִ�����챦�������ݿ��Ǵ��ĳ�����\n");
	set("combat_exp", 10000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/changchun",
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

        command("say ��ӭ���٣���λ"+RANK_D->query_respect(ob)+"�����ιۡ�");
}

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
