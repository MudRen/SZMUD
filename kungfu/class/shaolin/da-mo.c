// Code of ShenZhou
// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("��Ħ", ({
		"damo",
		"damo zushi",
		"zushi",
	}));

	set("long",
		"����һλ�����ü����ɮ������ĸߴ�ȴ�������\n"
		"ֻ������¶΢Ц��ȫ��������һƬ���������֮�С�\n"
	);

	set("title", "������ʦ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 300);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_living_name("damo");

	set_skill("force", 200);
	set_skill("hunyuan-yiqi", 200);
	set_skill("dodge", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("parry", 200);

	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("claw", 200);
	set_skill("finger", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("club", 200);
	set_skill("staff", 200);

	set_skill("jingang-quan", 200);
	set_skill("luohan-quan", 200);
	set_skill("banruo-zhang", 200);
	set_skill("sanhua-zhang", 200);
	set_skill("qianye-shou", 200);
	set_skill("fengyun-shou", 200);
	set_skill("longzhua-gong", 200);
	set_skill("yingzhua-gong", 200);
	set_skill("yizhi-chan", 200);
	set_skill("nianhua-zhi", 200);
	set_skill("cibei-dao", 200);
	set_skill("xiuluo-dao", 200);
	set_skill("fumo-jian", 200);
	set_skill("damo-jian", 200);
	set_skill("zui-gun", 200);
	set_skill("weituo-gun", 200);
	set_skill("pudu-zhang", 200);
	set_skill("wuchang-zhang", 200);
	set_skill("riyue-bian", 200);

	set_skill("buddhism", 200);
	set_skill("literate", 200);
	set_skill("yiwei-dujiang", 200);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("finger", "yizhi-chan");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("club", "weituo-gun");
	map_skill("staff", "pudu-chang");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");

	create_family("������", 34, "����");

	setup();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
	carry_object("/d/shaolin/obj/chanzhang")->wield();
}

void init()
{
	::init();
	if( interactive(this_player()) ) 
	{
		if( this_player()->query("family/family_name") != "������"
		||  this_player()->query("family/generation") > 36
		||  this_player()->query_temp("win_times") < 3 )
		destruct(this_object());
	}
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
			command("say �����ִ����֣����ڰ���֮�䣬�ô��²����ˣ���ν����֮��Ҳ��");

			name = ob->query("name");
			new_name = "��" + name[2..3];
			ob->set("name", new_name);
	
			command("say �����ķ�������" + new_name + "����ϲ���Ϊ�����ɶ��ֱ����ϣ�");
			command("say �������ľʹ���һέ�ɽ�֮�����Ӵ�����ɶ���ǵ�������ĺ����ɻ�������");
			message_vision(HIY "\n\n" + me->name() + 
				"������ƽ����$N���ģ�ֻ��һƬ���ƽ��£�����׹���ת����$N�������С�" + 
				"���˰��ã��Ž�����ɢ��\n\n" NOR, ob);
			
			ob->set_skill("yiwei-dujiang", 100);
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
