// Code of ShenZhou
// teller.c

inherit NPC;

int tell_fortune();

int do_forge();
int write_card();

void create()
{
	set_name("������", ({ "li tiezui", "li"}) );
	set("gender", "����" );
	set("age", 48);
	set("long", 
"�������Ǹ������ԵĽ�����ʿ�������д���š�������\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
	set("shen_type", -1);

        set_skill("unarmed", 30);
	set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

	set("attitude", "peaceful");
        set("inquiry", ([
		"����" : (: tell_fortune :),
		"����" : (: tell_fortune :),
		"����" : (: tell_fortune :),
		"����" : (: write_card :),
		"д��" : "������˵��������д�ţ�ÿҳ��ʮ�ġ�\n",
		"д����" : "������˵���������ø����ּ�д������ÿ������������\n",
		"α��" : (: do_forge :),
        ]) );

	setup();
	add_money("silver", 5);
}

int tell_fortune()
{
	object me=this_player();
	int k;

	if (me->query_temp("tell_fortune")) {
	command("say ���ˣ���֪����Ҳ��֪����İ��֣������˭�㶼��֪���ɡ�");
	command("hehe li tiezui");
	k = (me->query_kar()) ;
	if (k < 15) {
	command ("say " + RANK_D->query_respect(me) + "������ʱ�����ǡ�����δ����������ԩ�����ҷ������������档��");
	command("nocry " + me->query("id"));
	}
	else if (k < 20) {
	command ("say " + RANK_D->query_respect(me) + "����ƽ�����������������ܿ��������ջ��ǿ��Գɹ��ġ�");
	command("sigh");
	}
	else if (k < 25) {
	command("say " + RANK_D->query_respect(me) + "����������ã��������󣬰׻����ң���ȸ���������в��ͣ��ܵ�˵�����ǲ���ģ��������ҷ�Դ��");
	command("nod");
	}
	else if (k < 31) { 
	command("say " + RANK_D->query_respect(me) + "ӡ�÷�����˫�����磬��������֮�࣬ǰ;����������");
	command("congra");
	}
	else {
	command("say " + RANK_D->query_respect(me) + "�ɷ���ǣ���������С�˿�������ġ�");
	command("fear");
	}
	me->delete_temp("tell_fortune");
	return 1;
	}
	else	
        switch (MONEY_D->player_pay(me, 0)) {
	case 0:
		command("say ����Ҫ��ʮ�����ӣ������ۡ�");
		return 1;
	case 2:
		command("say ������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		return 1;
        default:
		command("say ���޷��������٣������ջ��ٲ��룬����ƶ��ʯ�縻��������������ʱ��\n");
	        message_vision("����������$Nʮ�����ӣ����ڻ��\n",me);
		command("say ������������ָ����Ұɡ�");
		me->set_temp("tell_fortune",1);
		return 1;
	}
}

int write_card()
{
	say("������˫�ִ��˴��Ц����Ŷ����ݼ���ɽ�������ˡ������ðɣ���\n"
"���������ɡ�\n");
	this_player()->set_temp("card", 1);
	return 1;
}

int do_forge()
{
	say("��������ֻ�۾�����ɨ��ɨ�����ٺٺ١��ĸ�Ц�˼���...\n");
	write(
"��������������˵���������Ҵ�ţ����֤��ĸ�ԭ������һģһ����ÿ����\n"
"	            ��ʮ�������������ۡ�\n");
	this_player()->set_temp("marks/��", 1);
	return 1;
}

int accept_object(object who, object ob)
{
	object letter, wage, card;
	letter = new(__DIR__"obj/letter");

        if (who->query_temp("biao/li") && ob->name()=="����") {
                who->delete_temp("biao/li");
		who->delete_temp("apply/short");
                command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
                wage = new("/clone/money/silver");
                wage->set_amount(4);
                wage->move(who);
                message_vision("�������$N����������Ϊ���ڵĳ��͡�\n", who);
                remove_call_out("destroy");
                call_out("destroy", 1, ob);
                return 1;
        }

	if ((string)ob->query("name")=="��ֽ" && (string)ob->query("id")=="letter paper" && !userp(ob)) {
	        if( who->query_temp("marks/��") ) {
			this_player()->set_temp("marks/��3", 1);
			write(
"���������˵������������ף�������ʮ����������\n");
			this_player()->set_temp("marks/��", 0);
                call_out("destroy", 1, ob);
			return 1;
		} else if( who->query_temp("marks/��2") ) {
                        write(
"������ƤЦ�ⲻЦ�Ķ���˵����α������ſ��ǹ�ϵ�ش󰡣��ö�����ʮ����\n");
                        this_player()->set_temp("marks/��4", 1);
			this_player()->set_temp("marks/��2", 0);
                call_out("destroy", 1, ob);
                        return 1;
                }
//              say("������˵������д���˵��ţ����Ҹ�ʲô?\n");
                return 0;
	}
       
	if( ob->value() >= 5000 ) {
		 if( who->query_temp("marks/��4") ) {
			write(
"���������˵���������������ˣ���" + RANK_D->query_respect(who) + 
"Ҫ�ǳ����£�ǧ������˵����ѽ��\n");
			say("���������" + who->query("name") + "һ�����š�\n");
			this_player()->set_temp("marks/��4", 0);
			letter->move(who);
			return 1;
		}
		if( who->query_temp("marks/��3") ) {
			write(
"������ƤЦ�ⲻЦ�Ķ���˵����α������ſ��ǹ�ϵ�ش󰡣��ö�����ʮ����\n");
			this_player()->set_temp("marks/��4", 1);
			this_player()->set_temp("marks/��3", 0);
			return 1;
		} 
		if( who->query_temp("marks/��") ) {
			write(
"���������˵��������α��ʲô��? �ܵ��ø��������ɡ�\n");
		this_player()->set_temp("marks/��2", 1);
		this_player()->set_temp("marks/��", 0);
		return 1;
		}
                say(
"������һ�漱æ��Ǯ��������һ��Ц����˵����" + RANK_D->query_respect(ob) + 
"������ô�ҵ���\n");
		return 1;
	}
        if( ob->value() >= 500 ) {
		say(
"������Ц����˵��������д���ˣ������������ɣ���л���ա�\n");
		return 1;
	}
	if( ob->value() >= 300 && this_player()->query_temp("card") ) {
		say(
"������˫�ֽӹ����������ϳ��һ�Ŵ�����ӣ�ҡͷ���Ե�д��������\n"
"һ�����������̧��ͷ��Ц�����ؽ���������˵��������д���ˣ����\n"
"�ϻ�ɽȥ�ɣ���л���ա�\n");
		this_player()->delete_temp("card");
		card = new(__DIR__"obj/visitcard");
		card->move( this_player() );
		return 1;
	}
	if( ob->value() >= 50 ) {
		say(
"������Ц����˵������д���ˣ����պ��ˣ���л���ա�\n");
		return 1;
	}
	return 0;
}

void destroy (object ob)
{
        destruct(ob);
        return;
}
