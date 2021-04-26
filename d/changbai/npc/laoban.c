// Code of ShenZhou
// laoban.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�ƹ��ϰ�", ({ "lao ban"}) );
	set("gender", "����" );
	set("age", 50);
	set("long",
		"����һ�������ˣ�ͷ��һ����ë����������Ц�ݡ�\n");

	set("combat_exp", 3000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");

	set("vendor_goods", ({
                "/d/changbai/obj/cbs_map",
		"/d/changbai/obj/grtang",
                "/d/changbai/obj/gourou",
	}) );

	setup();

        carry_object("clone/misc/cloth")->wear();
	add_money("silver", 2);
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
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("�ƹ��ϰ�����˵��������ô����죬���빷����������ů�����ӵģ�\n");
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        say("\n�ƹ��ϰ���һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/changbai/nancheng");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴��������һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}

int accept_kill(object obj)
{
        command("chat ��λ�͹پ������� " + obj->name() + "���" 
        + RANK_D->query_rude(obj) + "Ҫɱ���ң�");
}
