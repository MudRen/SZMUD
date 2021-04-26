// Code of ShenZhou
// kungfu/class/misc/santa.c
// sdong, 12/24/98

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
string ask_gift();
void greeting();

void create()
{
	seteuid(getuid());
	set_name(HIR"ʥ������"NOR, ({ "shengdan laoren","santa","laoren"}) );
	set("gender", "����" );
	set("age", 63);
	set("long", HIR"һλ������棬Ц�Ǻǵİ׺�����үү��\n"NOR);
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 100);
	set("kar", 100);

	set("max_qi", 50000);
	set("max_jing", 100);
	set("neili", 50000);
	set("max_neili", 50000);
	set("shen_type", 1);
   set("env/yield","yes");

	set("startroom","/d/city/wumiao");

	set("combat_exp", 100000);

	set_skill("force", 400);
	set_skill("hand", 40);
	set_skill("sword", 50);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("huntian-qigong", 400);

	map_skill("force", "huntian-qigong");

	set("chat_chance", 20);
	set("chat_msg", ({
		"ʥ������Ц�Ǻ�˵��: ʥ�����֣����֣�~~\n",
		"ʥ�����˿��س���: ��������������������춣��~~\n",
		"ʥ������Ц�Ǻ�˵��: ��Ҫ�������Ҿ�����������ʥ������ġ� \n",
		"ʥ������Ц��: ֻҪ�ǹԺ��ӣ�����ʥ����� \n",
		(: random_move :),
		(: greeting :),
	}) );

	set("inquiry", ([
					 "gift" : (: ask_gift :),
					 "ʥ������" : (: ask_gift:),
					 "����" : (: ask_gift:),
				  ]) );



	setup();

	::create();
}


void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1);
	}
}

string ask_gift()
{
	object ppl = this_player();
	object santa = this_object();
	object ob;

	if( ppl->query_condition("santa") )
	{
		message_vision("$N����$nЦ��������õ����������Ҫ����\n",santa,ppl);
		random_move();
		return "�ǺǺ�\n";
	}

	if( ppl->query("combat_exp") < 300 )
	{
		random_move();
		return "DUMMY�ǲ���Ҫ�����:)";
	}

	seteuid(getuid());

	if (random(8) == 1) {
		 ob = new("/clone/drug/lingzhi");
		 ob->move(santa);
	}
	else if (random(16) == 1) {
		 ob = new("/clone/drug/puti-zi");
		 ob->move(ppl);
	}
	else if (random(16) == 1) {
		 ob = new("/clone/drug/sheli-zi");
		 ob->move(santa);
	}
	else if (random(6) == 1) {
		 ob = new("/clone/drug/xueteng");
		 ob->move(santa);
	}
	else if (random(6) == 1) {
		 ob = new("/clone/drug/xuelian");
		 ob->move(santa);
	}
	else if (random(6) == 1) {
		 ob = new("/clone/drug/cb_renshen");
		 ob->move(santa);
	}
	else if (random(6) != 1) {
		 ob = new("/clone/drug/renshen_guo");
		 ob->move(santa);
	}
	else
	{
		 ob=new("/clone/money/gold");
		 ob->set_amount( 3 + random(5) );
		 ob->move(santa);
	}

	command("pat "+ppl->query("id"));
	if( ppl->query("env/no_accept") )
	{
		command("hmm");
		command("say "+ppl->name()+"��������κζ�����");
	}
	else
		command( "give "+ob->query("id")+" to "+ ppl->query("id")  );

	ppl->apply_condition( "santa",20+random(10) );

	return "ף��ʥ�����֣����֣�~~\n";
}

void destroy_me(object me)
{
	destruct(me);
}

void greeting()
{
	object me = this_object();

	command("say ף��ʥ�����֣�����~~\n");

	if( strsrch(base_name(environment()), "/d/city/") == -1 )
	{
		message_vision(HIY"$N"+HIY"�����糵��շ�ȥ��ת�۾Ͳ�����.\n"NOR,me);
		me->move("d/city/wumiao");
		message_vision(HIG"ֻ������һ���������죬$N"+HIG"�����糵��շ���.\n"NOR,me);
	}

	if( strsrch(ctime(time()), "Dec 25") == -1 )
	{
		message_vision(HIY"$N"+HIY"�����˵��ʥ���ڽ����ˣ���Ҳ�û�������.\n"NOR,me);
		command("goodbye");
		message_vision(HIY"$N"+HIY"�����糵��շ�ȥ��ת�۾Ͳ�����.\n"NOR,me);
		call_out("destroy_me",1,me);
	}

	if( random(150) == 0 )
	{
		message_vision(HIY"$N"+HIY"�����糵��շ�ȥ��ת�۾Ͳ�����.\n"NOR,me);
		call_out("destroy_me",1,me);
	}
}

int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1) {
			 command("smile");
			 command("say ��л�� ! ����ı��кñ��� !");
	}

	return 0;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "����ͷ�����ǲ���ܵ�:)��\n");
	return 0;
}

int accept_kill(object victim)
{
		  object me = this_object();
		  object player = this_player();
		  int flag;

		  command("say " + RANK_D->query_respect(player) + "����ô��ô�ף����ò���ѽ��\n");
		  command("benger " + player->query("id") );
		  if (player->query("env/immortal"))
				flag=1;
		  player->delete("env/immortal");
		  player->unconcious();
		  if (flag) player->set("env/immortal",1);
        command("halt");
		  random_move();
		  return 0;
}



