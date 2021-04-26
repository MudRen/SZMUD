// Code of ShenZhou
// laifu.c

inherit NPC;

string ask_me();

void create()
{
	set_name("������", ({ "laifu er","laifu" }) );
	set("gender", "����");
	set("age", 30);
	set("long",
		"���������ļҶ�����Լ��ʮ����ͣ�����ٹ�����ӡ�\n");
	set("combat_exp", 30000);
	set("shen_type", 0);
	set("attitude", "peaceful");

	set("apply/attack", 30);
	set("apply/defense", 30);

	set_skill("unarmed", 55);
	set_skill("parry", 55);
	set_skill("dodge", 55);

	set("inquiry", ([
		"����"   : "�꣡С���������ү�޼����նεģ�ǧ��Ҫ������ǰ���𡰶Ρ��֣���ȻС��������",
		"�նε�" : "�꣡С���������ү�޼����նεģ�ǧ��Ҫ������ǰ���𡰶Ρ��֣���ȻС��������",
		"����"   : "�����Ҽ�С�㡣���ɵ�Ƥ�ˣ�������ȥ�ǻ���������ү������û�취��",
		"�����" : "�����Ҽ���ү������Ĺ�������Ƣ���ܻ�����С��Щ��",
		"����"   : "�Ҽҷ������иʱ��������˿ɺ��ˣ����������ү�е��Ǹ� ... ...",
		"����"   : "�����Ҽ�С�㡣���ɵ�Ƥ�ˣ�������ȥ�ǻ���������ү������û�취��",
		"����ɽ" : "�ȱ����ǣ�����ûȥ����С����󲻾�ǰȥ��һ�ء�",
		"��·"   : (: ask_me :),
		]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
	object ling, who;
	who=this_player();

	command("look "+getuid(who));
	command("hmm");

	if (objectp(ling=present("zhong ling", find_object("/d/dali/wjg5.c")))
//	if ( !objectp(ling = find_object("/d/dali/npc/zhongling")) )
 //               ling = load_object("/d/dali/npc/zhongling");
		&& ling->query("bm_hints")==9) {
		command("hehe "+getuid(who));
		command("say ����������ͦ�Ƶģ�С����Ȼûȥ������ɽ������ ... ...");
		command("whisper "+getuid(who)+" С���ϻش��Ƕ������Ժ�С��żȻ�����������ϣ������ϣ��� ... ��ũ���ʲô�ġ�");
		who->set_temp("bmquest/got_hint1",1);
		return "С�ľ���������Щ����ľ�ʲôҲ��֪���ˡ�\n";
	}
	else {
		command("shake "+getuid(who));
		return "Զ���ǿͣ�Ҳ�������������˺������ģ�һ����ò��û�С�С����������������ȥ��";
	}
}
