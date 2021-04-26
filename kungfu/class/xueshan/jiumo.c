// Code of ShenZhou
// Summer 9/26/1996.

inherit NPC;
int auto_perform();

void create()
{
	set_name("�Ħ��", ({ "jiumozhi", "jiu" }));
	set("nickname", "��������");
	set("long", 
"����һ������ɮ�ˣ�������һ��ׯ�ϱ������΢Ц������ǳ�����ġ�\n"
"��������ެ��������������ѩɽ�����µ����֡� \n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("class","lama");
	set("shen_type", -1);
	set("str", 37);
	set("int", 37);
	set("con", 30);
	set("dex", 35);
	set_temp("apply/armor", 100);
	
	set("max_qi", 3500);
	set("max_jing", 3500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 100);
	set("combat_exp", 3600000);
	set("score", 5000);

	set_skill("force", 360);
	set_skill("dodge", 360);
	set_skill("parry", 360);
	set_skill("staff", 360);
        set_skill("lamaism", 400);
	set_skill("strike", 360);
	set_skill("cuff", 360);
	set_skill("jingang-chu", 360);
	set_skill("longxiang-banruo", 360);
	set_skill("huoyan-dao", 400);
	set_skill("sword", 360);
	set_skill("mingwang-jian", 360);
	set_skill("necromancy", 400);
	set_skill("shenkongxing", 400);
	set_skill("xiaowuxiang", 360);
	set_skill("yujiamu-quan", 360);

	map_skill("force", "xiaowuxiang");
	map_skill("parry", "huoyan-dao");
	map_skill("sword", "mingwang-jian");
	map_skill("staff", "jingang-chu");
	map_skill("strike", "huoyan-dao");
	map_skill("dodge", "shenkongxing");
	map_skill("cuff", "yujiamu-quan");
	
	prepare_skill("strike", "huoyan-dao");

	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	create_family("ѩɽ��", 6, "������");

	setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "ѩɽ��"
        && ob->query("family/family_name") != "Ѫ����"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
	if ((int)ob->query_skill("longxiang-banruo", 1) < 60
	&& (int)ob->query_skill("xiaowuxiang", 1) < 60) {
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����ڹ���Ϊ�϶��µ㹦��");
	return;
	}
	if (ob->query_con() < 30) {
		command("say " + RANK_D->query_respect(ob) +
			"������ϰ���׵����ǵ���Ҫ���ϳ˵ĸ�������
������������");
	return;
	}
//	command("chat ����������������");
 //       command("chat �벻���Ϸ�ү�Ҿ�Ȼ���ٵ�һ��ѧ���浶֮�ţ����ǿ�ϲ�ɺء�");
        command("recruit " + ob->query("id"));
}
#include "/kungfu/class/xueshan/auto_perform.h"
