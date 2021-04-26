// Code of ShenZhou
// seller.c
// ryu added garbage collecting on 3/20/1997
// Mongol modifed him to be a charactor of Jin's novels.
// xbc added remove ���� on 1/21/99

inherit NPC;
inherit F_VENDOR;
int do_sell(string);
int do_removelian(string);
string ask_liancost();
void create()
{
	set_name("������", ({ "wang tiejiang", "wang" }) );
	set("gender", "����" );
	set("age", 40);
	set("long",
		"�����ųಲ����ʵ�ļ���߸߷�������΢�ף���Ȼ������˪��������ů��"
		+ "\n��ԭ�Ƕ�ͥ��һ����һ���������ڳ����صİ����±��˶Խ���ɽ�򸾵ĳ��ӵ����\n");
	set("combat_exp", 3000);
        set("str", 25);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/clone/weapon/caidao",
		"/clone/weapon/tiebang",
		"/clone/weapon/dafu",
		"/d/taohua/obj/xiaotiefu",
	}) );
        set("inquiry", ([
		"����ɽ" : "����ɽ�����Ӹ��������ݣ���������������߹ǣ��������ģ�",
		"Ѧȵ" : "����ɽ�����š�\n",
		"����" : "�ڶ�ͥ���ϡ�\n",
                "��ͥ��" : "�ҿɲ���ȥ�ˡ�\n",
		"������" : "�̹���������µ�һ���ˡ�\n",
		"����" : "���õ��������ɵû�һ������ask ������Ǯ����\n",
                "������Ǯ" : (:ask_liancost:),
	]));	

	set("chat_chance", 5);
        set("chat_msg", ({
	"������������С���Ӵ����� ���� �����\n",
	"��������������Ī���������� ���� һ���顣\n",
        "�������������������ʱ ���� Ҫ�����á�\n",
        "�������������㲻������ʱ ���� ����Ҫʮ�߰˱�����ģ�\n",
        }) );

	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
	
	setup();
        carry_object(__DIR__"obj/cloth")->wear();
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
	add_action("do_sell", "sell");
	add_action("do_removelian", "removelian");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say ��ӭ��λ"+RANK_D->query_respect(ob)+"���٣������ιۡ�");
}
int do_sell(string arg)
{
    object ob;

	if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

	if (ob->query("material") != "steel" && ob->query("material") != "iron")
		return notify_fail("������ֻ�շ�����\n");

	else {
                message_vision("$N������һ" + ob->query("unit") +
                ob->query("name") + "��$n��\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), ob->query_weight()/70);
                        destruct(ob);
        }
        return 1;
}

int do_removelian(string arg)
{
        object ob;
	object me = this_player();

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ�õ�ʲô��\n");

	if (ob->query("name") != "����" && ob->query("id") != "tie lian") 
                return notify_fail("����Ҳ����á�\n");

	if (!me->query_temp("lianpaid"))
		return notify_fail("�����Ҫ����һ��Ǯ�ģ�ask liancost����\n");

        else {
                message_vision("$n��$N�����Ա����ô���˺�һ�������õ���������\n", 
			this_player(), this_object());
                destruct(ob);
		me->delete_temp("liancost");
		me->delete_temp("lianpaid");
        }
        return 1;
}

string ask_liancost()
{
	object me = this_player();
	int liancost;

	liancost = me->query("PKS")*2;
	me->set_temp("liancost", liancost);

	return "����¿�ҪС�Ĳ��С������ɣ������ " + liancost +
		" ���ƽ���͵͵�����õ���\n";

}

int accept_object(object who, object ob)
{

        if (!ob->query("money_id")) {
                command(":(");
                command("say �����������ʲô��");
                return 0;
        }

        else if (ob->value() < who->query_temp("liancost")) {
                command("hmm");
                command("say ��Щ�������²��ܰ���������");
                return 0;
        }

        command("look " + who->query("id"));
        command("secret " + who->query("id"));
        command("whisper " + who->query("id")+ "�ã�ˬ�죡���£�����������֣�removelian tie lian����");
	who->set_temp("lianpaid", 1);

        return 1;
}

