// Code of ShenZhou
// ganbaobao.c �ʱ���

inherit NPC;

string ask_me();

void create()
{
	set_name("�ʱ���", ({ "gan baobao","gan" }));
	set("nickname", "��ҹ��");
	set("long", 
		"���������ķ��ˣ������ĸ�ף��ʱ�����\n"
		"����ò���㣬��������Լ����ʮ�����ꡣ\n");
	set("gender", "Ů��");
	set("age", 36);
	set("str", 20);
	set("int", 30);
	set("con", 20);
	set("dex", 30);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 15);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("score", 5000);

	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 60);
	set_skill("parry", 60);

	set("inquiry", ([
		"����"   : "�꣬С����������Ӻ޼��˶��ϣ�ǧ��Ҫ������ǰ�ᡰ�Ρ��֡�",
		"�նε�" : "�꣬С����������Ӻ޼��˶��ϣ�ǧ��Ҫ������ǰ�ᡰ�Ρ��֡�",
		"����"   : "�Ǿ���СŮ�����������Ƥ�úܣ��������Ϲ���ǻ�������",
		"����ɽ" : "���Ǳ�����Ƭɽ����ɽ��·�ա��������ǰȥ��һ�أ������˲���Σ�ղŻص�����",
//		"��·"   : (: ask_me :),
		]));

	setup();
	carry_object("/d/dali/obj/gcloth")->wear();
	add_money("gold", 1);
}

string ask_me()
{
	object ling, who;
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (objectp(ling=present("zhong ling", find_object("/d/dali/wjg5.c")))
		&& ling->query("bm_hints")==5) {
		command("sneer "+getuid(who));
		command("say �㿴������ͷ���Եģ�������Щ��ʲô��");
		command("whisper "+getuid(who)+" ��������Ժ�����������ϣ������ϣ���������ʲô��ũ��ȵȡ�");
		who->set_temp("bmquest/got_hint1",1);
		return "����ֻ����Щ�ˣ���ɱ��ȥ��˵����\n";
	}
	else {
		command("shake "+getuid(who));
		return "�������ʶ���������Ȼ�������⣬��ʲôҲ��֪��������֪����Ҳ���������ġ�";
	}
}
