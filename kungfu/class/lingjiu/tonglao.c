// /NPC tonglao.c
// Modified by xuanyuan 10/19/2001
// add quest by firefox 

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_shengsi();
string ask_job();
string ask_escape();
string ask_wulaoda();
string ask_shenxun();
string ask_xiongshewan();
string ask_dahui();
int accept_object(object who, object ob);
mapping query_namelist(int i);
int auto_perform();

void create()
{
	set_name("��ɽͯ��", ({ "tong lao", "tong", "lao" }));
	set("long",
	    "�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
	    "էһ���ƺ��Ǹ�ʮ�߰����Ů��,������ȴ����������.\n"+
	    "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");

	set("title", "���չ�����");
	set("gender", "Ů��");
	set("per", 33);
	set("age", 96);
	set("nickname", "Ψ�Ҷ���" );
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 35);
	set("con", 30);
	set("dex", 30);

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 200);

	set("combat_exp", 3600000);
	set("score", 200000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("hand",400);
	set_skill("strike", 400);
	set_skill("sword",400);
	set_skill("blade",400);
	set_skill("literate",400);
	set_skill("music",400);

	set_skill("zhemei-shou",400);
	set_skill("liuyang-zhang",400);
	set_skill("tianyu-qijian",400);
	set_skill("yueying-wubu",400);
	set_skill("bahuang-gong", 400);
	set_skill("ruyi-dao", 400);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	map_skill("blade", "ruyi-dao");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("inquiry", ([
		"������" : (: ask_shengsi :),
		"job" : (: ask_job :),
		"����" : (: ask_job :),
		"����" : (: ask_escape :), 
		"�ɲ���" : (: ask_escape :), 
		"escape" : (: ask_escape :), 
//add new quest by firefox
		"���ϴ�" : (: ask_wulaoda :),
		"��Ѷ" : (: ask_shenxun :),
		"��ת������" : (: ask_xiongshewan :),
		"���ɴ��" : (: ask_dahui :),
	]));

	set("lingjiu/shengsi",1);
	set("count_wan",5);

	create_family("���չ�",1,"����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/city/npc/obj/doupeng")->wear();
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/city/obj/jiudai");
	carry_object("/d/city/obj/jiudai");
}

void attempt_apprentice(object ob)
{
        	mapping fam = ob->query("family");

		if (ob->query("gender") != "Ů��") {
			command("say ��������!");
			return; 
		}
		if (!fam || fam["family_name"] != "���չ�"){
                	command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                	return;
                }
		if((int)ob->query_skill("force", 1) < 180 ) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                	return;
                }  
		if((int)ob->query_skill("bahuang-gong", 1) < 180) {
			command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
                	return;
                }  
		if((int)ob->query_skill("dodge", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("yueying-wubu", 1) < 180 && (int)ob->query_skill("lingbo-weibu", 1) < 180 ) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ṧ�϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("sword", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("tianyu-qijian", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ���ڽ����϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("hand", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����ַ��϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("zhemei-shou", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����ַ��϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("strike", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ʒ��϶��µ㹦��");
                	return;
                }
		if((int)ob->query_skill("liuyang-zhang", 1) < 180) {
                	command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����Ʒ��϶��µ㹦��");
                	return;
                }
		if (ob->query_con() < 34) {
			command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
			return;
		}
		if ((int)ob->query("shen") < -100)  {
                        command("hmm " + ob->query("id"));
                        command("say �����չ��䲻���������ɣ���Ҳ�����ڼ�а֮��Ϊ�顣");
                	command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
        		return;
		}
		command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
		ob->set("class", "dancer");
}

string ask_job()
{
	mapping fam , namelist;
	object ob = this_player();
	object me = this_object();
	int i ;
	int start_time;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(this_player()) + "�뱾��������������֪�˻��Ӻ�̸��";

	if ( me->query_temp("job_girl2") == ob->query("id") ) {
		command("sneer");
		return "�ϵ�����û��ɻ�����Ҫ�����ҿ����˳�ȥ��\n";
	}

	if((this_player()->query("job_status"))==2)
		return "�㻹û������Ҹ���Ĺ�����������ʲô��\n";

	command( "say ���������С��ʵ�ڿɶ�����������Ƥ���´󴵷��ݡ�");

	i=(int)this_player()->query("combat_exp",1);
	if(i>1000000)
		i=3;
	else if(i>500000)
		i=2;
	else if(i>100000)
		i=1;
	else 
		i=0;

	namelist=query_namelist(i);

	command( "say ��ȥ��" +namelist["name"]+ "��ʬ���������ң��������ͣ�");

	this_player()->set("job_status", 2);
	this_player()->set("namelist", namelist);
	
	return "��ȥ����\n";

}

int accept_object(object who, object ob)
{
	int bonus, exp, pot;
	mapping namelist;
	int possible_pot;
	int now_pot, i, j;
	object me;

	if((who->query("job_status"))!=2)
	{
		command("say ����������ʲô��");
		who->set("job_status",0);
		return 1;
	}
	
	if(!(namelist =  who->query("namelist")))
	{
		command("hmm");
		command("say �㵨����ʦ���棡�������չ���ʲô�ط���");
		COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
		return 1;
	}

	if( ob->query("victim_name") != namelist["name"])
	{
		command("hmm");
		command("say �㵨����ʦ���棡�������չ���ʲô�ط���");
		COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
		return 1;
	}

	if ( ob->query("my_killer") != who->query("id") ) {
		command("hmm");
		command("say ���Ȼ̰ͼ���˵Ĺ��ͣ��������չ���ʲô�ط���");
		message_vision("$N˵�������ڹ�һ������$n������ǡ�\n", this_object(), who);
//		who->receive_wound("qi", who->query("max_qi")+100, "����ɽͯ��ɱ����");
		COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
		return 1;
	}
		command("say �ܺã������������С�����ܲ��񵽼�ʱ��");
//		exp = namelist["exp_bonus"]/2 + random(namelist["exp_bonus"]/2);
//		pot = namelist["pot_bonus"]/2 + random(namelist["pot_bonus"]/2);
		exp = namelist["exp_bonus"];
		pot = namelist["pot_bonus"];
		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		who->add("potential", pot);
		if ( who->query("potential") > who->query("max_potential") )
			who->set("potential", who->query("max_potential"));

		who->set("namelist", 0);
		who->set("job_status", 0 );
		call_out("destroy", 1, ob);

	return 1;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

mapping *namelist = ({
	      ([      "name":          "����������",
		"exp_bonus":            80,
		"pot_bonus":           60
	]),

	([      "name":                "�����ɺ���",
		"exp_bonus":            80,
		"pot_bonus":           70
	]),

		 ([      "name":                "�����ɹ���",
		"exp_bonus":       100,
		"pot_bonus":         80
	 ]),

       ([      "name":                "����",
		"exp_bonus":           110,
		"pot_bonus":            90
		
	]),

	 ([      "name":                "������",
		"exp_bonus":          120,
		"pot_bonus":           120
		
	]),

	([      "name":                "������",
		"exp_bonus":         120,
		"pot_bonus":           120
		
	]),

	    ([      "name":                "ʨ����",
		"exp_bonus":         250,
		"pot_bonus":           200
		
	]),

		([      "name":                "ժ����",
		"exp_bonus":            350,
		"pot_bonus":            320
		
	]),
	
		([      "name":                "������",
		"exp_bonus":            800,
		"pot_bonus":            450
		
	]),
});

mapping query_namelist(int i)
{
	switch(i)
	{
	case 0:
	return namelist[random(3)];
	case 1:
	//	return namelist[random(5)+3];
		return namelist[random(3)+2];
	case 2:
		return namelist[random(5)+3];
	default:
		return namelist[random(2)+7];
	}
	return 0;
}

int ask_shengsi()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "���չ�") {
                command("say ���������չ����ľ�ѧ��");
                return 1;
        }
		if (ob->query("family/master_name") != "��ɽͯ��") {
                command("say �����ַ������ľ�����ֻ�����ҵĵմ����ӡ�");
		return 1;
		}     
        if (ob->query("lingjiu/shengsi") > 0 ) {
                command("say �㲻���Ѿ�ѧ������");
                return 1;
        }
        if (ob->query_skill("strike",1) < 120) {
                command("say Ҫʹ�������ľ�����Ҫ������Ʒ����㻹�Ƕ���ϰ��ϰ��˵�ɡ�");
                return 1;
        }
        if (ob->query_skill("liuyang-zhang",1) < 120) {
                command("say Ҫʹ�������ľ�����Ҫ������Ʒ����㻹�Ƕ���ϰ��ϰ����ɽ�����ơ���˵�ɡ�");
                return 1;
        }
		if (this_player()->query_temp("xiongshe_quest")!=7){
                command("say ֻ�ж������ҳϵ��˲��ܵ��Ҵ��ڴ˾�ѧ��");
                return 1;
        }
        	command("say ���Ȼ�����չ��ĵ��ӣ��Ҿͽ���һ�С����������ɣ�\n");

        ob->set("lingjiu/shengsi", 1);
        return 1;
}

string ask_escape()
{
	mapping fam;
	object ob = this_player();
	object me = this_object();
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if((ob->query("job_status"))==2)
	{
		command("say �ߣ�����Ҳ�겻���ҵ�����");
		add("job_count", -2);
		ob->set("job_status",0);
		me->add_temp("job_girl2", ob->query("id") );
		remove_call_out("clear_job_girl");
		call_out("clear_job_girl", 20 + random(30), me );
	}
	else  
		command( "say ����û�Ը���ȥ���£��⻰�Ӻ�˵��");
		
	return "���ҿ����˳�ȥ��\n";
}

int clear_job_girl()
{
	object me = this_object();
	if ( objectp(me) ) {
		me->delete_temp("job_girl2");
	}
	return 1;
}

string ask_wulaoda()
{
	if ( !this_player()->query_temp("quest")) return ;
		this_player()->set_temp("xiongshe_quest",1);
		return "��͵���ҵľ�ת�����裬���ڱ��ҹ������С�\n";
}

string ask_shenxun()
{
	object keyob,me;
	me=this_player();
	if (me->query_temp("xiongshe_quest")==1){
		if (!present("key",me)) {
			keyob=new("/d/lingjiu/obj/key");
			keyob->move(me);
			me->delete_temp("xiongshe_quest");
			message_vision("ͯ�Ѹ�$Nһ�����ҵ�"HIY"Կ�ס�\n"NOR,me);
			return "Ҳ�ã����ȥ������һ�����ɡ�\n";
		}
	}
} 

string ask_dahui()
{
	if (this_player()->query_temp("xiongshe_quest")==5){
		message_vision("$N����Ѷ�ľ��������ɴ��֮��һ��һʮ����������ͯ��\n",this_player());
		this_player()->set_temp("xiongshe_quest",6);
		return HIB"����ȥ�����ϴ����ɱ�ˣ���\n"NOR;
	}
}

string ask_xiongshewan()
{
	object ob,keyob;
	if (this_player()->query_temp("xiongshe_quest")!=7)
		return "���������չ���ʥҩ�������컯������������\n";
	else {
		this_player()->delete_temp("quest");
		if ( !keyob=present("key",this_player()) ) {
//			this_player()->delete_temp("xiongshe_quest");
			return HIB"���Կ��Ū��ȥ�ˣ�\n"NOR;
		}else {
			destruct(keyob);
			message_vision(HIW"$N����ͯ��һ��"HIY"Կ�ס�\n"NOR,this_player());
		}
		if ( this_object()->query("count_wan")<=0){
			this_player()->delete_temp("xiongshe_quest");
			return "����������û����ҩ�ˣ�������������ɣ�";
		}
		if (this_player()->query("xiongshewan_last_time")+20000>=time()) {
			this_player()->delete_temp("xiongshe_quest");
			return "���Ǹ���������ҩ�Զ��к����棡\n";
		}
		if (present("jiuzhuan-xiongshe wan",environment())) {
			this_player()->delete_temp("xiongshe_quest");
			return "�㲻����һ����Ҫ��ô�൱���԰���\n";
		}
		this_player()->delete("xiongshewan_last_time");
		command("say "+this_player()->query("name")+"���úã���ž�ת������͸���ɣ�\n");
		this_object()->set("count_wan",this_object()->query("count_wan")-1);
		this_player()->delete_temp("xiongshe_quest");
		this_player()->set("xiongshewan_last_time",time());
		ob= new ("/clone/drug/xiongshe-wan");
		ob->move(this_player());
	}
	return ;
} 
#include "/kungfu/class/lingjiu/auto_perform.h"
