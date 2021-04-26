// Code of ShenZhou
// dunan.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();
string ask_me();
string ask_damo();

void create()
{
	object *obs;
	set_name("����", ({ "du nan", "nan" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ��ڣ������������ɡ�\n");

	set("attitude", "peaceful");
	set("combat_exp", 1500000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("max_qi", 3000);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);

	create_family("������", 35, "����");
	set("class", "bonze");
	assign_apprentice("����", 0);

	set_skill("force", 180);
	set_skill("cuff", 180);
	set_skill("whip", 170);
	set_skill("parry", 170);
	set_skill("dodge", 160);

	set_skill("buddhism", 150);
	set_skill("jingang-quan", 180);
	set_skill("hunyuan-yiqi", 160);
	set_skill("riyue-bian", 170);
	set_skill("shaolin-shenfa", 160);

	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff",  "jingang-quan");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	prepare_skill("cuff", "jingang-quan");

	set("chat_chance", 80);
	set("chat_msg", ({
		(: auto_perform :),
	}) );

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("inquiry", ([
		"������"     : (: ask_me :),
		"ɨ��ɮ"   : (: ask_damo :),
		"��Ħ��ʦ"   : "������ԭ����֮�棬Ҳ�������µĴ�����ʦ��\n",
                "Բ��" :
                "Բ��ʦֶ�����ڱ������ж��ﾲ�ޣ����˲�Ҫ���š�\n",
                "Բ���ʦ" :
                "Բ��ʦֶ�����ڱ������ж��ﾲ�ޣ����˲�Ҫ���š�\n",
                "���ж�" :
                "���Ǳ�������֮һ��ֻҪ��Ϥ�������˱仯�ȿɳ���\n",
	]));

	set("count", random(10)-8);

	setup();

        obs = filter_array(children("/d/shaolin/obj/heilong-bian"),
                                (: clonep :));

        if(sizeof(obs) < 3)
                carry_object("/d/shaolin/obj/heilong-bian")->wield();
        else carry_object("/clone/weapon/changbian")->wield();
}

#include "/kungfu/class/shaolin/du.h"

void halt()
{
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("puti zi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"������ֻ��һ�ţ����Ҿ��������ϣ�����̰�����У�";

	if ( present("puti zi", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"������ֻ��һ�ţ����Ҿ�����������ȡ�ߣ�����̰�����У�";

	if (query("count") < 1)
		return "�����������֮����ɼ������ޱȣ����������ڿ�û�С�";

	ob = new(DRUG_D("puti-zi"));
	ob->move(this_player());

	add("count", -1);

	message_vision("\n���Ѳ�ȻһЦ�����ų�̾һ������������ȡ���������ƿ�����������ӵݸ�$N��\n\n", this_player());

	return "�ҵ������ڷ�����ǰ���º�Ը��ÿʮ������ɽ�󴨣��������գ�\n" +
	       "���ɵ����������ӣ�������Ե�ˣ��ܵô��컯���������Ϊ֮��";
}
