// Code of ShenZhou
inherit NPC;
inherit F_VENDOR;

void create()
{   
  set_name("南彝商人", ({ "nanyi shangren", "shangren", "iron smith" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
"他穿了一身染蜡财袍，看起来一副精明强干的样子。\n");
        set("combat_exp", 3000);
        set("str", 25);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/clone/weapon/caidao",
                "/clone/weapon/hammer",
        }) );

        set_skill("dodge", 25);
        set_skill("parry", 25);
        set_skill("unarmed", 30);

        setup();
        carry_object("/d/dali/obj/ccloth")->wear();
        add_money("coin", 200);
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        command("say 
欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。");
}

