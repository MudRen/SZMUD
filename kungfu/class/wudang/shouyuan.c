// Code of ShenZhou
// chenggao.c �ɸ�

#define HOME "/d/wudang/langmei"

inherit NPC;
int auto_perform();
string ask_me(string);

void create()
{
	set_name("�ɸߵ���", ({ "chenggao daozhang", "chenggao", "daozhang", "shouyuan" }));
	set("nickname", "��԰����");
	set("long",
		"���������ʦֶ�������㲻�úܾ���������֮ʱ����������ס��ʮ���꣬\n"
		"��������ըҩ���ֽ��ǿ�����÷԰�ĵ�����\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");

	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 20);
	set("combat_exp", 250000);
	set("score", 8000);
	set("wudang/liangyi", "yin");

	set_skill("force", 100);
	set_skill("wudang-jiuyang", 100);
	set_skill("dodge", 110);
	set_skill("tiyun-zong", 110);
	set_skill("cuff", 60);
	set_skill("chang-quan", 60);
	set_skill("parry", 90);
	set_skill("sword", 135);
	set_skill("wudang-jian", 135);
	set_skill("literate", 80);
	set_skill("taoism", 90);

	map_skill("force", "wudang-jiuyang");
	map_skill("dodge", "tiyun-zong");
	map_skill("cuff", "chang-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	prepare_skill("cuff", "chang-quan");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("�䵱��", 4, "����");
	set("inquiry", ([
		"here" : (: ask_me, "here" :),
		"name" : "ƶ�����ųɸߣ���������÷԰����֪��λ"+
				RANK_D->query_respect(this_player()) +"�кμ��̣�",
		"�䵱" : "ƶ�������䵱�ɵ��ӣ���֪��λ"+ RANK_D->query_respect(this_player())
				+"�кμ��̣�",
		"�䵱��" : "ƶ�������䵱�ɵ��ӣ���֪��λ"+ RANK_D->query_respect(this_player())
				+"�кμ��̣�",
		"�䵱ɽ" : (: ask_me, "here" :),
		"����" : "���Ž���ƶ����δ�����ң������������ۡ�",
		"̫����" : "�š�������Ҳ��������",
		"̫������" : "�š�������Ҳ��������",
		"�䵱��" : "�䵱����",
		"�䵱����" : "���Ž���ƶ����δ�����ң������������ۡ�",
		"���ǽ���" : "���ǽ����Ľ���һ��һ����һ��һ�ᣬ�������ͬʹ��",
		"�䵱���ǽ�" : "���ǽ����Ľ���һ��һ����һ��һ�ᣬ�������ͬʹ��",
		"��ָ�ὣ" : "��·����ƶ��û��ѧ�ᡣ",
		"����ʮ����" : "��·����ƶ��û��ѧ�ᡣ",
		"�䵱��ȭ" : "ȭ�Ź����ƶ��������",
		"����" : "ȭ�Ź����ƶ��������",
		"��ɽ��" : "ȭ�Ź����ƶ��������",
		"��צ������" : "�š�����˵���ɺ���������һ·�书������ƶ�����������",
		"������" : "���ɴ�����ʦ������������չز�������Ҳδ�������Ρ�",
		"������" : "���ɴ�����ʦ������������չز�������Ҳδ�������Ρ�",
		"��Զ��" : "���Ǳ������š�",
		"�δ���" : "���Ǳ������š�",
		"������" : "���Ǳ��ɵ�ǰ����",
		"�����" : "���Ǳ��ɵ�ǰ����",
		"�����" : "���Ǳ��ɵ�ǰ����",
		"������" : "���Ǳ��ɵ�ǰ����",
		"����Ϫ" : "���Ǳ��ɵ�ǰ����",
		"������" : "���Ǳ��ɵ�ǰ����",
		"�Ŵ�ɽ" : "���Ǳ��ɵ�ǰ��������ƶ��δ����Եһ����",
		"������" : "���Ǳ��ɵ�ǰ��������ƶ��δ����Եһ����",
		"����ͤ" : "���Ǳ��ɵ�ǰ����",
		"������" : "���Ǳ��ɵ�ǰ����",
		"Ī����" : "���Ǳ��ɵ�ǰ���������⸽�������ҡ�",
		"Ī����" : "���Ǳ��ɵ�ǰ���������⸽�������ҡ�",
		"������" : "��ʦ�壿�þö�δ�������ˡ�",
		"����" : "���������ƶ����ʦ���������ϵ��������ǳ����뻯������ʦ��ʦ�������˿ɼ���",
		"�������" : "���������ƶ����ʦ���������ϵ��������ǳ����뻯������ʦ��ʦ�������˿ɼ���",
		"����" : "����ʦ��������ɽ�������䵱����",
		"�������" : "����ʦ��������ɽ�������䵱����",
		"����" : "���������ƶ����ʦ�壬����ƶ��һͬ������ס��ʮ���ꡣ",
		"�������" : "���������ƶ����ʦ�壬����ƶ��һͬ������ס��ʮ���ꡣ",
		"����" : "����ʦ�������湬��",
		"�������" : "����ʦ�������湬��",
		"����" : "����ʦ�������湬��",
		"�������" : "����ʦ�������湬��",
		"����" : "����ʦ����ɽ�ţ�����Ӵ���͡�",
		"�������" : "����ʦ����ɽ�ţ�����Ӵ���͡�",
		"֪��" : "����ʦ����ɽ�ţ�����Ӵ���͡�",
		"֪�͵���" : "����ʦ����ɽ�ţ�����Ӵ���͡�",
		"�ɸ�" : "ƶ�����ǳɸߣ���������÷԰����֪��λ"+
				RANK_D->query_respect(this_player()) +"�кμ��̣�",
		"�ɸߵ���" : "ƶ�����ǳɸߣ���������÷԰����֪��λ"+
				RANK_D->query_respect(this_player()) +"�кμ��̣�",
		"��԰" : "��λ"+ RANK_D->query_respect(this_player())
				+"̫�����ˣ�������÷԰���»�����һ�������ɡ�",
		"��԰����" : "ƶ�����ųɸߣ���������÷԰����֪��λ"+
				RANK_D->query_respect(this_player()) +"�кμ��̣�",
		"ըҩ" : "ƶ����������ѧ������ըҩ֮����",
		"��ҩ" : "ƶ����������ѧ������ըҩ֮����",
		"�����ҩ" : "�����ҩ��"+ RANK_D->query_respect(this_player())
				+"��������ըҩ�ɣ�",
		"����ըҩ" : "ըҩ������춾޴��������գ���֪��λ"+
				RANK_D->query_respect(this_player()) +"����������",
		"����" : "�����ȥ������ʦ�塣",
		"��������" : "�����ȥ������ʦ�塣",
	]));

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

string ask_me(string arg)
{
	object home, here = environment();
	
	switch( arg )
	{
		case "here" :
			if( base_name(here) == HOME )
				return "��������÷԰��������ȥ�����䵱���������ҡ�";
			else
			{
				command("say ������"+ here->query("short")
					+"�������ף�����������⡣");
				if( !(home = find_object(HOME)) )
				{
					message("vision", this_object()->name() +"����ææ���뿪�ˡ�\n",
						environment(), this_object());
					move("/d/death/death");
					return "����";
				}
				else
				{
					return_home(home);
					message("vision", this_object()->name() +"����ææ�����˹�����\n",
						environment(), this_object());
					return "�������ܵ�"+ here->query("short") +"ȥ�ˡ�";
				}
			}
			break;
	}
}

int auto_perform()
{
	object partner;

	if( partner = present("qingxu daozhang", environment(this_object())) )
	{
		command("perform liangyi qingxu");
		partner->auto_perform();
	}
}
