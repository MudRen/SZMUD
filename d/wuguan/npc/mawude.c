//Cracked by Kafei
// mawude.c �����
// qfy August 1, 1996

inherit NPC;
//string random_chat();
void create()
{
	set_name("�����", ({ "ma wude", "ma", "wude" }));
	set("long", "��������º����ÿͣ������ϳ�֮�磬��Ե���ѡ�\n");
        set("title", "������ݹ���");
	set("gender", "����");
	set("age", 55);

	set_skill("literate", 50);

	set_skill("hand", 70);
	set_skill("dodge", 60);
	set_skill("force", 75);
	set_skill("parry", 70);
        set_skill("literate", 10);
	set_skill("blade", 75);
	set_skill("wuhu-duanmen",55);
	set_skill("taixuan-gong",50);
	set_skill("liuxing-bu",65);
	set_skill("qinnashou",65);
	map_skill("hand","qinnashou");
	map_skill("blade","wuhu-duanmen");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	prepare_skill("hand","qinnashou");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"ѧ��" : "ѧ��ֻ�븶�������ӣ�����ס������",
		"ѧ��" : "ֻ�븶�������ӡ�",
		"���" : "���Ƕ����ң����ڰ���(stick)���ȷ�(staff) ��ȭ��(cuff)��",
		"����" : "���ǵ��в���ͷ���Ե���(blade)��צ��(claw)���ơ�",
		"������" : "���ǽ�����ͷ���Խ���(sword)������(strike)������",
		"����" : "���ǰ�������ͷ�����ڰ���(throwing)��ָ��(finger)��",
	]) );

        /*
        set("chat_chance", 50);
	set("chat_msg", (: random_chat :));
        */

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("mark/��")){
		if (me->query("family/family_name") && (int)me->query("combat_exp") > 30000) {
			command( "say "+RANK_D->query_respect(me)+"�������и��ף��������������ѧ���˶��ٶ�����������Ͷ��ʦ�ɡ�");
			me->delete_temp("mark/��");
		}
	
		if (!me->query("family/family_name") && (int)me->query("combat_exp") > 8000) {
			command( "say "+RANK_D->query_respect(me)+"�������и��ף��������������ѧ���˶��ٶ�����������Ͷ��ʦ�ɡ�");
			me->delete_temp("mark/��");
		}	
	}
/*	if ( me->query("wuguan/pass") )
	{
		remove_call_out("get_out");
		call_out("get_out", 1, me);
	}*/
}

int accept_object(object who, object ob)
{
	object wage;

	if (who->query_temp("biao/ma") && ob->name()=="����") {
                who->delete_temp("biao/ma");
		who->delete_temp("apply/short");
                command( "say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
                wage = new("/clone/money/silver");
                wage->set_amount(5);
                wage->move(who);
                message_vision("����¸�$N����������Ϊ���ڵĳ��͡�\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	if (who->query("family/family_name") && (int)who->query("combat_exp") > 30000) {
		command( "say "+RANK_D->query_respect(who)+"�������и��ף��������������ѧ���˶��ٶ�����������Ͷ��ʦ�ɡ�");
		return 0;
	}

	if (!who->query("family/family_name") && (int)who->query("combat_exp") > 8000) {
		command( "say "+RANK_D->query_respect(who)+"�������и��ף��������������ѧ���˶��ٶ�����������Ͷ��ʦ�ɡ�");
		return 0;
	}
	
	if (!(int)who->query_temp("mark/��")) who->set_temp("mark/��", 0);

	if (ob->query("money_id") && ob->value() >= 500) {
		command( "say "+RANK_D->query_respect(who)+"��Զǧ����������������������ѧϰ����ϲ���Ĺ���ɡ�");
		who->set_temp("mark/��", 1);
		return 1;
	}

	return 0;
}

void destroy_it(object obj)
{
	destruct(obj);
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0;
        return 1;
}

/*int random_chat() {

    switch (random(200)) {
    case 0:
        command("say ��ӭ����������ݡ�");
	return 1;
    case 1:
        command("say ѧ��ֻ�븶�������ӣ�����ס������\n");
	return 1;
    case 2:
        command("say ��������ݵİ�������ͷ��������ָ����");
	return 1;
    case 3:
        command("say ����������ݵĽ�����ͷ��ͬʱ���°ܽ�������");
	return 1;
    case 4:
        command("say �����ǵ��в���ͷ���Ե�����צ�����ơ�");
	return 1;
    case 5:
        command("say �����ҳ���ǰ��Ȳ���ͷ��ȭ������һ����");
	return 1;
    case 6:
        command("say �ڴ˿�ѧ���ڹ���ȭ�ţ��������Ṧ���мܡ�");
	return 1;
    case 7:
        command("say ��ӭ������������");
	return 1;
    case 8:
        command("say ���߽������Ĳ����书�������ѣ��ཻ���Ѷ�����кܶ�İ�����");
	return 1;
    case 9:
        command("say ����֪�������ʱ����ʣ�ask <npc����> about all����õİ취��");
	return 1;
    case 10:
        command("say ��������������(silver)��û��Ҫ����Լ�(get)������");
	return 1;
    case 11:
        command("say ����ˣ���Ǯ����Щ������ûǮ�������ҪһЩ��");
	return 1;
    case 12:
        command("say �óԷ��ˣ��ף���ô�ԣ��ޣ�eat <ʳ��>��drink <������>��");
	return 1;
    case 13:
        command("say ��ȥ�Ǳ����ƣ���ô��ѽ��look ,������ʲô�����ڣ��߾ͳ��ˡ�");
	return 1;
    case 14:
        command("say nothwest̫������ʮ�ֵĲ��ô���������nw��ÿ�����������ͷһ����ĸ���档");
	return 1;
    case 15:
        command("say ����������������list��������û�ж�����������buy <��Ʒ��>��");
	return 1;
    case 16:
        command("say ����ѧ����������Ȱ�(bai)ʦ����ѧ��");
	return 1;
    case 17:
        command("say ʦ�������㣿�����������鷿��Ҳ������ؼ�ʲô�ġ�");
	return 1;
    case 18:
        command("say ��û���ؼ�������xue <ʦ��ID> <������>��");
	return 1;
    case 19:
        command("say �㲻֪������ʲô����������skills�����һ���ô��Ĺ���");
	return 1;
    case 20:
        command("say �㲻��������Ĺ�������еĻ����ȼ���һ��(help enable)��");
	return 1;
    case 21:
        command("say ����֪���������״����hp �������Լ��ж�ǿ��");
	return 1;
    case 22:
        command("say �㿴����hp��ʾ�Ķ������ð�����������");
	return 1;
    default:
	return 0;
    }
    return 1;
}

void get_out(object me)
{
	command("hmm");
	command("say " + RANK_D->query_respect(me) + "��ô������ݣ�");
	message_vision("����´���һ�ӣ���$N�ϵ������ˡ�\n", me);
	me->move("/d/wuguan/cheku");
	return;
}*/
