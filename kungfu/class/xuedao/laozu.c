// Code of ShenZhou
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;
int auto_perform();
string ask_me();
void create()
{
	set_name("Ѫ������", ({ "xuedao laozu", "xuedao", "laozu" }));
	set("long", 
"���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š� \n");
	set("gender", "����");
	set("age", 80);
	set("attitude", "friendly");
	set("class","lama");

	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3000);
	set("max_jing", 2500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("apply/armor", 100);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
        set_skill("lamaism", 300);
	set_skill("cuff", 300);
	set_skill("yujiamu-quan", 300);
	set_skill("xue-dao", 300);
	set_skill("xueshitiao", 300);
	set_skill("shenkongxing", 300);
	set_skill("longxiang-banruo", 300);

	map_skill("force", "longxiang-banruo");
	map_skill("blade", "xue-dao");
	map_skill("dodge", "xueshitiao");
	map_skill("parry", "xue-dao");
	map_skill("cuff", "yujiamu-quan");

	prepare_skill("cuff", "yujiamu-quan");
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );	
	set("inquiry", ([
	"Ѫ����" : "������һ������������е�һ֧������Ѫ���š�����ʦү\n"
		   "ү������һ�ŵĵ��Ĵ��ƽ̣���ú�ѧ���򣬵�����ƽ̾�˵�������������ϡ�\n",
        "Ѫ��" : "�������ÿ����Բ֮�ʣ������ͷ������������ټ����뵶��������\n",
	"Ѫ���ܽ�" : "�ұ�������Ҫȥ��\n",
	"����" : (: ask_me:),
	]) );

	create_family("Ѫ����", 4, "������");

	set("blade_count", 1);
	setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
 	if (clonep()) carry_object("/clone/unique/xuedao"); 
}
void attempt_apprentice(object ob)
{
        if (ob->query("gender")=="Ů��") {
                command ("say ���ɲ���Ů���ӣ����ȥ�ɡ�");
                return;
        }

	if( ob->query("family/family_name") != "ѩɽ��"
        && ob->query("family/family_name") != "Ѫ����"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
        if ((int)ob->query("shen") > -100000) {
                command("say С�ֵ������Ǻڵ�����¶������ÿɲ���ѽ��");
                return;
        }
        else if ((int)ob->query_skill("longxiang-banruo", 1) < 60
	&& (int)ob->query_skill("xiaowuxiang", 1) < 60){
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ���ڼ���һ���ڹ���Ϊ��");
                return;
        }
        command("say �ðɣ������Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam;
	object ob, me = this_player(); 

/*
        if (!(fam = this_player()->query("family")) ||
	fam["family_name"] !="Ѫ����")
                return RANK_D->query_respect(this_player()) +
                "���������ɵĻ��ܸ�ʲ�᣿";
*/  
	if (!present("xue dao", this_object()))
                return "ʱ��δ����������";

if(present("liu chengfeng", environment(me)))
	{ 
if  (present("lu tianshu", environment(me))) 
		{
if  (present("hua tiegan", environment(me))) 
			{ 
      if (present("shui dai", environment(me))) 
	{
        add("blade_count", -1);
	me->add_temp("jidao", 4);
	command ("drop dao");
	command ("rumor "+this_player()->query("name")+"Ū����һ��Ѫ����");
	return "��������С���Ӿ�ȻҲ֪�����Ϸ���ļ���֮�£��ɼοɼΣ� �ã���������Ѫ�����ҵ��������˰ɡ�";
	}
	else
	return "ʱ��δ����������";
	}
	else
        return "ʱ��δ����������";
        }
	else
        return "ʱ��δ����������";
        }
else
        return "ʱ��δ����������";
        }

#include "/kungfu/class/xuedao/auto_perform.h"	
int accept_kill(object me)
{
        command("say �Ϸ�ү����������ɱ�ţ��������㵹ù��\n");
        if (present("xue dao", this_object())){
        command("wield dao");
        }
        kill_ob(me);
        return 1;
}
