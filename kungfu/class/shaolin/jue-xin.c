// Code of ShenZhou
// Npc: /d/shaolin/npc/jue-xin.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("����", ({
		"juexin dashi",
		"juexin",
		"saodi seng",
	}));

	set("long",
		"����һλ�����ü����ɮ������ĸߴ�ȴ�������\n"
		"����һλרְ������¥��ܣ��������������ɮ�ˡ�\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("title", "ɨ��ɮ");
	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 6000);
	set("max_jing", 5000);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 300);
	set("combat_exp", 4000000);
	set("score", 500000);

	set_living_name("damo");

	set_skill("force", 400);
	set_skill("hunyuan-yiqi", 400);
	set_skill("dodge", 400);
	set_skill("shaolin-shenfa", 380);
	set_skill("parry", 380);

	set_skill("cuff", 400);
	set_skill("strike", 390);
	set_skill("hand", 380);
	set_skill("claw", 390);
	set_skill("finger", 380);
	set_skill("blade", 400);
	set_skill("sword", 380);
	set_skill("whip", 400);
	set_skill("club", 400);
	set_skill("staff", 390);

	set_skill("jingang-quan", 380);
	set_skill("luohan-quan", 380);
	set_skill("banruo-zhang", 390);
	set_skill("sanhua-zhang", 380);
	set_skill("qianye-shou", 380);
	set_skill("fengyun-shou", 400);
	set_skill("longzhua-gong", 380);
	set_skill("yingzhua-gong", 380);
	set_skill("yizhi-chan", 400);
	set_skill("nianhua-zhi", 380);
	set_skill("cibei-dao", 400);
	set_skill("xiuluo-dao", 380);
	set_skill("fumo-jian", 400);
	set_skill("damo-jian", 390);
	set_skill("zui-gun", 400);
	set_skill("weituo-gun", 390);
	set_skill("pudu-zhang", 380);
	set_skill("wuchang-zhang", 400);
	set_skill("riyue-bian", 400);

	set_skill("buddhism", 400);
	set_skill("literate", 101);
//	set_skill("yiwei-dujiang", 400);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("finger", "yizhi-chan");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("whip", "riyue-bian");
	map_skill("club", "weituo-gun");
	map_skill("staff", "pudu-chang");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	create_family("������", 34, "����");

	set("inquiry", ([
		"����"     : (: ask_me :),
		"���Ĵ�ʦ"     : (: ask_me :),
		"ɨ��ɮ"   : "�ǰ����Ҿ��ǹܹ�¥��ɨ�صģ���ǰ�ڲؾ�����ɡ�\n",
		"��Ħ��ʦ"   : "������ԭ����֮�棬Ҳ�������µĴ�����ʦ��\n",
	]));

	setup();

	carry_object("/clone/armor/seng-cloth")->wear();
	carry_object("/clone/armor/sengxie")->wear();
	carry_object("/clone/weapon/saoba")->wield();
}
void init()
{
	object me;

	::init();
	if( interactive(me = this_player()) ) 
	{
		if( (me->query("family/family_name") != "������"
		||  me->query("family/generation") > 36
		||  me->query_temp("win_times") < 3)
		&& me->query( "family/master_name") != "����" )
		destruct(this_object());
	}
}
string ask_me()
{
	object me = this_player();	

	if( (me->query("family/family_name") != "������"
	||  me->query("family/generation") > 36
	||  me->query_temp("win_times") < 3)
	&& me->query( "family/master_name") != "����" )
	command("dunno");

	command("haha");
	return "�Ҿ��Ǿ��ġ���������������ϵ��̳�������λ���Ӱɣ�\n" +
	           "���Ȼ�Ѿ�ͨ�������ǵĿ��飬�Ҿ����������ͽ���ˣ�";
}
	
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] < my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) && name[0..1] == "��" )
	{
		if ( ob->query_temp("win_times") >= 3 )
		{	
			command("say ������Ϊ�������ϣ����ڰ���֮�䣬�ô��²����ˣ���ν����֮��Ҳ��");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �����ķ�������" + new_name + "����ϲ���Ϊ�����ɶ��ֱ����ϣ�");
			command("say �������ľʹ���һέ�ɽ�֮�����Ӵ�����ɶ���ǵ�������ĺ����ɻ�������");
			message_vision(HIY "\n\n" + me->name() + 
				"������ƽ����$N���ģ�ֻ��һƬ���ƽ��£�����׹���ת����$N�������С�\n" + 
				"���˰��ã����ƲŽ�����ɢ��\n\n" NOR, ob);
			
		//	ob->set_skill("yiwei-dujiang", 100);
			ob->delete_temp("win_times");

			command("recruit " + ob->query("id"));

			command("say ��ȥ�գ��Ҿȼ����ˣ������޶�����������Ե�����ڴ���ᡣ");
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + 
				"��������ͽ���ϣ��㻹û���ʸ����ҵ�ͽ�ܡ�");
			return;
		}
	}

	return;
}
