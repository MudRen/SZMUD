// Code of ShenZhou
// dianban.c ���

inherit NPC;
inherit F_DEALER;

string ask_me(string);

void create()
{
        set_name("���", ({ "dian ban", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ������������ϴ��\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С��");
        set("vendor_goods", ({
                "/clone/food/jiudai",
                "/d/heimuya/obj/peanut",
                "/d/heimuya/obj/candou",
                "/d/heimuya/obj/niurou",
        }));

        setup();
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
        switch( random(2) ) {
                case 0:
                        say( "���Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "����ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        say("\n�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);
        
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/heimuya/northstreet1");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴�����¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
int accept_kill(object obj)
{
        command("chat ��λ�͹پ������� " + obj->name() + "���" 
        + RANK_D->query_rude(obj) + "Ҫɱ���ң�");
}


