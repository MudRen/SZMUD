// Code of ShenZhou
// dujie.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();
string ask_me();
string ask_damo();
string rumor(object place, object holder);

string* places = ({
	"/d/qilian/mine",
	"/d/quanzhou/liang",
	"/d/forest/mty1",
	"/d/xingxiu/btgate",
	"/d/qilian/shiku2",
	"/d/xingxiu/icecave2",
	"/d/taishan/baozang",
	"/d/xixia/hut",
});

void create()
{
	object *obs;
	set_name("�ɽ�", ({ "du jie", "jie" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�Ұף���һ��ֽһ����\n");

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

	set_skill("force", 150);
	set_skill("cuff", 180);
	set_skill("whip", 180);
	set_skill("parry", 160);
	set_skill("dodge", 170);

	set_skill("buddhism", 150);
	set_skill("hunyuan-yiqi", 180);
	set_skill("jingang-quan", 180);
	set_skill("riyue-bian", 180);
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
		"�����"     : (: ask_me :),
		"ɨ��ɮ"   : (: ask_damo :),
		"��Ħ��ʦ"   : "������ԭ����֮�棬Ҳ�������µĴ�����ʦ��\n",
                "Բ��" :
                "Բ��ʦֶ�����ڱ������ж��ﾲ�ޣ����˲�Ҫ���š�\n",
                "Բ���ʦ" :
                "Բ��ʦֶ�����ڱ������ж��ﾲ�ޣ����˲�Ҫ���š�\n",
                "���ж�" :
                "���Ǳ�������֮һ��ֻҪ��Ϥ�������˱仯�ȿɳ���\n",
	]));

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
	int r, i;
	object place, *holder, ob, me = this_player();
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("jingang zhao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�������Ҿ��������ϣ�����̰�����У�";

	if ( present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�������Ҿ�����������ȡ�ߣ�����̰�����У�";

	if ( present("fumo dao", this_player()) || present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"ȡ�˷�ħ�����Ͳ������ý���֣�ĪҪ̰�����У�";

	r = random(6);
	if(!( place = find_object(places[r])) )
	place = load_object(places[r]);

	if(holder = all_inventory(place)) {
		for(i=0; i<sizeof(holder); i++) {
			if( living(holder[i]) && holder[i]->query("race") == "����" && !userp(holder[i]) ) {
				if(ob = new("/d/shaolin/obj/jingang-zhao")) {
					ob->move(holder[i]);
					call_out("rumor", 5, place, holder[i]);
					return "���Ѿ��ѽ���ֽ�����"
						+ place->query("short") + "��" 
						+ holder[i]->query("name") + "�����б��£���ȥȡ�ɣ�";
				}
				else return "������˷�����Ψ��Ե�ߵ�֮����ʱ�ںδ�������Ҳ��֪����";
			}
			else continue;
		}
	}

	if(ob = new("/d/shaolin/obj/jingang-zhao")) {
		ob->move(place);
		call_out("rumor", 5, place);
		return "���Ѿ��ѽ���ַ�����"	+ place->query("short") + "�����б��£���ȥȡ�ɣ�";
	}
	else return "������˷�����Ψ��Ե�ߵ�֮����ʱ�ںδ�������Ҳ��֪����";
}

string rumor(object place, object holder)
{
	if(objectp(holder))
	command ("rumor ��˵����ֺ�������"
		+ place->query("short") + "��" 
		+ holder->query("name") + "�����ˣ�");
	else
	command ("rumor ��˵����ֺ������" + place->query("short") + "��");
}
