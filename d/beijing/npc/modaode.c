//Cracked by Roath
// modaode.c

inherit NPC;
inherit F_VENDOR;

#include "/d/beijing/npc/bjnpc.h"

string ask_mo();

void create()
{
        set_name("ĥ����", ({ "modao jiang","jiang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "���Ǹ�������˪�ĺ��ӣ���ͷ����ĥ���Ĺ��ߣ��ִ߽���ߺ���š�\n");
        set("combat_exp", 3000);
        set("str", 26);
        set("dex", 20);
        set("con", 17);
        set("int", 17);
        set("attitude", "friendly");
        set("chat_chance", 40);
        set("chat_msg", ({
                  "ĥ��������������ĥ�����ϣ�ꨲ˵���\n",
		  (: random_walk :)
	}) );

        set("vendor_goods", ({
                "/clone/weapon/caidao.c",
	}) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 100);

	set("inquiry", ([
	       "modao" : (: ask_mo :),
	       "ĥ��" :  (: ask_mo :),
        ]));
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

string ask_mo()
{
        object me = this_player();
	object obj;
        if (query_temp("busy"))
                return "Ӵ����Ǹ�����������æ���ء��������Ժ�\n";
        if (me->query_temp("allow_modao")!=1)
                return "��λ"+RANK_D->query_respect(me)+"�����ȸ�һ��������\n";
        me->delete_temp("allow_modao");

        if( !objectp(obj = present("cai dao", me)) )
                return "��û�в˵���ĥʲô����\n";

        set_temp("busy",1);
        start_busy(2);
        obj = new("/d/beijing/obj/caidao2");
        obj->move(me);

        remove_call_out("enough_rest");
        call_out("enough_rest", 2);

        return "ĥ�������˲��������������ˣ���ѵ�����ǰ����ˣ���\n";
}

void enough_rest()
{
        delete_temp("busy");
}

int accept_object(object me, object ob)
{     
        if(ob->query("money_id") && ob->value() >= 100)
	  {
	    remove_call_out("enough");
	    call_out("enough", 1, 1,me);
	  }
	else 
	  {
	    remove_call_out("enough");
	    call_out("enough", 1,0,me);
	  }
        remove_call_out("destroy_ob");
        call_out("destroy_ob", 1, ob);

        return 1;
}

void enough(int i, object me)
{
        if (i==1)
	  {
	    command("bow");
	    command("say ��л" + RANK_D->query_respect(me) + "���� ��");
	    me->set_temp("allow_modao", 1);
	  }
	else
	  command("say ��Ǹ��������Ҫ��һ��������");
}

void destroy_ob(object ob)
{
        if (ob) destruct(ob);
}
