// Code of ShenZhou
// Npc: /kungfu/class/shaolin/qing-fa.c
// Date: YZC 96/01/19
// xQin 8/00
// xiaojian Jan 19,2001 for fixing chujia bug

inherit NPC;
inherit F_MASTER;

string ask_for_huansu();
string ask_for_join();

void create()
{
	set_name("�巨����", ({
		"qingfa biqiu",
		"qingfa",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ������û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("inquiry",([
		"���"	: (: ask_for_join :),
		"����"	: (: ask_for_join :),
		"����" : (:ask_for_huansu:),
	]));

	set("age", 30);
	set("shen_type", 1);
	set("str", 25);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 40000);
	set("score", 100);

        set_skill("force", 30);
        set_skill("hunyuan-yiqi", 30);
        set_skill("dodge", 50);
        set_skill("shaolin-shenfa", 50);
        set_skill("cuff", 50);
        set_skill("luohan-quan", 50);
        set_skill("jingang-quan", 50);
        set_skill("club", 50);
        set_skill("weituo-gun", 50);
        set_skill("parry", 30);
        set_skill("buddhism", 30);
        set_skill("literate", 30);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff",  "luohan-quan");
        map_skill("club",  "weituo-gun");
        map_skill("parry", "weituo-gun");

        prepare_skill("cuff",  "luohan-quan");

        set_temp("apply/damage", 30);
        set_temp("apply/attack", 20);

        prepare_skill("cuff", "jingang-quan");

        create_family("������", 40, "����");

	setup();

        carry_object("/clone/weapon/qimeigun")->wield();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("quit/bonze"))
	{
		return "�����ӷ�ʩ����Ȼ�Ѿ�����������������֮�£�";
	}
	if( (string)me->query("class")=="bonze" )
		return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";
	if ( (string)me->query("class") =="taoist" )
		return "�����ӷ�ʩ���Ѿ��ǵ����ˣ��ιʸ�ƶɮ�������Ц��\n";

	if( (string)me->query("gender") != "����" )
		return "�����ӷ����գ����գ�Ůʩ������������ҷ𣬿�ȥ��ɽ�����ܽ䡣\n";

	me->set_temp("pending/join_bonze", 1);

	add_action("do_kneel", "kneel");
	return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "��", "��", "��", "��" });
	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N˫�ֺ�ʮ�����������ع���������\n\n"
		"$n������ƣ���$Nͷ�������Ħ���˼��£���$N��ͷ��������ȥ��\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));

	return 1;
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( ob->query("family/family_name") == "������" 
        && ob->query("generation") <= this_object()->query("generation") )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if( ob->query("family/family_name") != "������"
	&&  (ob->query("combat_exp") >= 10000 || ob->query("rank") >= 2)        )
	{
		command ("say �����ӷ� ʩ���Ǳ��ɵ��书���֣����¿ɲ���������");
		return;
	}

	if( (string)ob->query("gender") == "Ů��" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	}
	else    command ("say �����ӷ����գ����գ�");

	command("recruit " + ob->query("id"));
}

string ask_for_huansu()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	
	if (me->query("gender") != "����" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"������ƶɮ��������Ц��";
	}
	if (me->query("class") != "bonze" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"���Ƿ������ˣ�����д�һ�ʣ�";
	}
	if (me->query("family/family_name") != "������" )
	{
	return "�����ӷ�"+RANK_D->query_respect(me)+"�Ǳ������ˣ�����һ��ƶɮ����������";
	}
	if (me->query("family/master_id") == ob->query("id"))
	{
	add_action("do_jueding", "�������");
	me->set_temp("pending/quit_bonze", 1);
	command("sigh "+me->query("id"));
	return "��Ȼ�������Ե��ΪʦҲ����ǿ�󣬵����㽫�����ʦ�ǣ����Ҫ������ˡ�\n"
	       "(type �������)";
	} 
	else {
	return "����һ�»�����Ϊ"+RANK_D->query_respect(me)+"�ͱ��������������飬ƶɮ����������\n";
	}
}

int do_jueding()
{
	object ob,me;
	me=this_player();
	ob=this_object();
	
	if (!me->query_temp("pending/quit_bonze"))
	return 0;
	
	command("sigh "+me->query("id"));
	message_vision("$N���������Ĺ��£�����˵��������ˡͽ����Ф����\n",me);
	message_vision("$n��$N�����������ָ���$Nһ�����¡�\n",ob,me);
	command("say ʩ�����أ�������Ϊ֮��");
	me->delete_temp("pending/quit_bonze");
	me->set("quit/bonze", 1);
	me->delete("class", "bonze");
	ob=new("/clone/misc/cloth.c");
	ob->move(me);
	command("expell "+me->query("id"));
	return 1;
}

	
