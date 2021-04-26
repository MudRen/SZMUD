// Code of ShenZhou
// kongkong.c

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	seteuid(getuid());
	set_name("�տն�", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "������ؤ");
	set("gender", "����" );
	set("age", 53);
	set("long", "һ��������˪֮ɫ������ؤ��\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);

	set("rank", 8);

	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);

        set("startroom","/d/city/lichunyuan");

	set("thief", 0);
	set("combat_exp", 50000);

	set_skill("force", 40); 
	set_skill("hand", 40);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("stealing", 100);
	set_skill("begging", 100);
	set_skill("checking", 80); 
	set_skill("huntian-qigong", 40); 
	set_skill("shexing-diaoshou", 40);
	set_skill("xiaoyaoyou", 50); 

	map_skill("force", "huntian-qigong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "�˴�����");

	set("chat_chance", 20);
	set("chat_msg", ({
		"�տն�˵��: ���ĵĴ�ү�ġ� ����Ҫ���ļ���ͭ��ɡ�\n",
		"�տն�������ش��˸���Ƿ��\n",
		"�տն�����׽ס�����ϵ�ʭ�ӣ����: ��������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n",
		(: random_move :)
	}) );

	setup();

	carry_object("/clone/food/jitui");
	carry_object("/clone/food/jiudai");
	carry_object("/d/gaibang/obj/budai")->set_amount(7);
	carry_object("/d/gaibang/obj/budai")->wear();
	add_money("silver", 10);        

	::create();
}

void attempt_apprentice(object ob)
{
	if( ob->query("class")=="bonze" && ob->query("gender")=="Ů��" )
		command ("say ʦ̫���ǳ����ˣ��Ͻл��ɲ��������㡣");

	if( ob->query("family/family_name") != "ؤ��" )	
	{
		if( ob->query("rank") > 1 ) {
			command("say ����������Ϊ�ȣ����ݲ�����������������ļһ");
			return;
		} else {
			command("say ������͵����������ǲ���Կ����������ĺ��ˣ�");
			command("recruit " + ob->query("id"));
			ob->set("rank", 1); 
			ob->set("title", "ؤ��һ������");
		}
	} else {
		command("say ������͵����������ǲ���Կ����������ĺ��ˣ�");
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
                ob->set("title", ob->query_temp("title"));
                ob->delete_temp("title");
	}

	return;
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "ؤ��")
                || (int)ob->query_skill("taoism", 1) > 30
                || ob->query_int() > 30
          ) return;

	seteuid(getuid());

	switch( random(5) ) {
		case 0:
                       command("hehe " + ob->query("id"));
                       command("beg coin from " + ob->query("id"));
                       command("buy jitui");
		       break;
		case 1:
                       command("grin " + ob->query("id"));
                       command("steal silver from " + ob->query("id"));			
                       command("eat jitui");
		       break;
		case 2:
                       command("hi " + ob->query("id"));
                       command("steal gold from " + ob->query("id"));			
                       command("drink jiudai");
		       break;
		case 3:
                       command("pat " + ob->query("id"));
                       command("beg jiudai from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("walkby " + ob->query("id"));
                       command("beg jitui from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
        	 command("smile");
	         command("say ��л�� ! ��ʵ�һ����е�Ǯ�ģ����ֻ������������� !");
        	 command("give 10 silver to " + me->query("id"));
	}
        else {
        	 command("shake");
	         command("say ���ֶ������Ҫ ! ��һ��ȥ !");
	         command("give " + obj->query("id") + " to " + me->query("id"));
//               obj->move(this_player());
        }

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
	return 0;
}
