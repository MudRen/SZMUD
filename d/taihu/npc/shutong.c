// Code of ShenZhou
// Npc: 
// Date: 

inherit NPC;

string ask_me_1(string);
string ask_me_2(string);

void create()
{
	set_name("��ͯ", ({"shu tong","tong",}));
	set("long","����ׯ����������ͯ��ƽ�ؿ��ܲ��顣\n");

	set("gender", "����");
	set("attitude", "friendly");

	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 40);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 30);
	set_skill("strike", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
      set_temp("apply/attack", 20);
      set_temp("apply/defense", 20);

        set("inquiry", ([
		"�׾�����ƪ" : (: ask_me_1, "yijing1" :),
            "�׾�˵��ƪ" : (: ask_me_2, "yijing2" :)
        ]));

	set("yijing1_count", 9);
	set("yijing2_count", 9);

	setup();

        carry_object("/d/taihu/obj/cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�һ���")
		return RANK_D->query_respect(this_player()) + 
		"���ׯ������������֪�˻��Ӻ�̸��";

	if (  present("yi jing", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ���������ô����Ҫ�ˣ� �������ģ�";

	if (query("yijing1_count") < 1)
		return "��Ǹ�������ò���ʱ�����ѱ�ȡ���ˡ�";

	ob = new("/d/taohua/obj/" + name);
	ob->move(this_player());

	add("yijing1_count", -1);

	message_vision("��ͯ��$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�С�ı�Ū���ˡ�";
}

string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�һ���")
		return RANK_D->query_respect(this_player()) + 
		"���ׯ������������֪�˻��Ӻ�̸��";

	if (query("yijing2_count") < 1)
		return "��Ǹ�������ò���ʱ�����ѱ�ȡ���ˡ�";

	ob = new("/d/taohua/obj/" + name);
	ob->move(this_player());

	add("yijing2_count", -1);

	message_vision("��ͯ��$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�С�ı�Ū���ˡ�";
}
