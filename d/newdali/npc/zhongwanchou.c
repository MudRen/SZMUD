// Code of ShenZhou
// zhongwanchou.c �����

inherit NPC;

string ask_me();

void create()
{
	set_name("�����", ({ "zhong wanchou","zhong","wanchou" }));
	set("nickname", "������");
	set("long", 
		"����������ٹȵĹ����ˣ����ź��£����μ��߼��ݣ�һ˫С���Ӱ�Ĵ��ִ������ԡ�\n"
		"����������¶�ţ�����������ʮ�����ˣ���òƽƽ��\n");
	set("gender", "����");
	set("age", 45);
	set("str", 30);
	set("int", 20);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 20);
	set("combat_exp", 300000);

	set_skill("force", 80);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 90);

	set("inquiry", ([
		"����"   : "�������������նεģ�������ɱ���㣡",
		"�նε�" : "�������������նεģ�������ɱ���㣡",
		"����"   : "����СŮ����Ƥ�úܣ����������Ϲ�ܣ���������",
		"����ɽ" : "������Ƭɽ���ǣ�ɽ�߹��СŮ����ǰȥ��һ�أ������˲���Σ�ղŻص�����",
//		"��·"   : (: ask_me :),
		]));

	setup();
	carry_object("/d/dali/obj/bcloth")->wear();
	add_money("gold", 1);
}

string ask_me()
{
	object ling, who;
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (objectp(ling=present("zhong ling", find_object("/d/dali/wjg5.c")))
		&& ling->query("bm_hints")==3) {
		command("sneer "+getuid(who));
		command("say �㿴������ͷ���Եģ�������Щ��ʲô��");
		command("whisper "+getuid(who)+" ��ֻ�ǵ�СŮ�����Ժ�����������ϣ������ϣ������������ũ���йء�");
		who->set_temp("bmquest/got_hint1",1);
		return "�Ҿ�֪����Щ�ˣ��㲻Ҫ�ٷ��ң�����ɡ�\n";
	}
	else {
		return "����һ��ͷ���ԣ��ʶ����������ʲô����������ò��죬����ɱ���㣡";
	}
}
