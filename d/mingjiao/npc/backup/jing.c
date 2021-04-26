// Code of ShenZhou
// jing.c ������ͽ

#include <ansi.h>
inherit NPC;
string check();

void create()
{
	set_name("������ͽ", ({"jing jiaotu","jiaotu"}));
	set("long", 
		"\n"
		"\n");
	set("age",  random(20)+25);
	set("gender", "����");
	set("long", "\n");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 0);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
        set("inquiry", ([
                "����" : (: check :),
                "�ɸ���" : (: check :),
        ]) );

        set("chat_chance_combat", 10);
	setup();
	carry_object(__DIR__"obj/duanfu")->wield();
//	carry_object(__DIR__"obj/")->wear();
}

string check()
{
	object ob = this_player();
	object me = this_object();
        mapping fam;
        if (mapp(fam = ob->query("family")) 
		&& fam["family_name"] != "����" )
        {
		return RANK_D->query_respect(ob) + "�����ҽ����ˣ�������ѧ�ҵȰ���";
        }
	if (ob->query_skill("feifu-zhen") < 50)
	{	
		return RANK_D->query_respect(ob) + "�ķɸ���ѧ�Ĳ�������û�������أ����ȥ��ѧѧ�ɣ�\n";
	}
	if (!(present("bai qi", ob)))
	{	
		return RANK_D->query_respect(ob) + "û���������ܰ���ɱ���أ���ȥ�ðɣ�\n";
	}
	//ob->command("team invite jing");
        ob->add_team_member(me);
     	command("follow " + ob->query("id"));
        return "�����߰գ�\n";
}
void destroy_it(object obj)
{
        destruct(obj);
}
