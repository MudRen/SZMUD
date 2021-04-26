//by snowyu add qingyan 2001/10
// Duan ZhengChun

 
inherit NPC;
inherit F_MASTER;

#include "/kungfu/class/dali/auto_perform.h"
 
string ask_me();
string ask_me_1();
string ask_qingyan();
 
void create()
{
	set_name("������", ({ "duan zhengchun", "zhengchun", "duan"}));
	set("long","�����θߴ�һϮ���������ĵ�һ�Ź�������ŭ������\n�����ǵ�����ϣ����Ƕ����׼ҵ�һ���֡�\n");
	set("title", "�����ʮ����İ��ʵ�");
	set("gender", "����");
	set("age", 43);
	set("inquiry", ([
		"����" : "��������Ȯ�ӣ�����ǰ������ҳ��ߣ��� ... ���ʸ���֪���������䣿",
		"����" : (: ask_me_1 :),
		"��������" : (: ask_qingyan :),
		]));

	set("dali/rank", 6);
	set("dali/qingyan",1);
	set_skill("finger", 150);
	set_skill("force", 130);
	set_skill("strike", 125);
	set_skill("dodge", 125);
	set_skill("parry", 125);
	set_skill("sword", 125);
	set_skill("cuff", 125);
	set_skill("buddhism", 130);
	set_skill("yiyang-zhi", 140);
	set_skill("duanjia-jian",140);
	set_skill("duanshi-shenfa",130);
	set_skill("kurong-changong",130);
	set_skill("qingyan-zhang", 140);
	set_skill("jinyu-quan", 120);
	map_skill("cuff","jinyu-quan");
	map_skill("sword","duanjia-jian");
	map_skill("dodge","duanshi-shenfa");
	map_skill("parry", "duanjia-jian");
	map_skill("force","kurong-changong");
	map_skill("strike","qingyan-zhang");
	map_skill("finger","yiyang-zhi");
	prepare_skill("finger","yiyang-zhi");

	set("str", 28);
	set("int", 25);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("qi",1200);
	set("max_jing", 800);
	set("jing",800);
	set("max_neili", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 80);
	set("combat_exp", 700000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	create_family("����μ�", 15 , "����");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/dali/obj/zipao")->wear();
}
#include "/kungfu/class/dali/condition.h"

void attempt_apprentice(object ob)
{
	mapping fam;
	string jiachen;
	if (!mapp(fam=ob->query("family"))
		|| fam["family_name"] !="����μ�") {
		command("say "+RANK_D->query_respect(ob)+"�������ڶμ�����������������Ұɡ�");
		return;
	}

	if ((int)ob->query_skill("kurong-changong",1)<80) {
		command("say ���Ƕμҵ���������������һ�����㻹Ҫ�����¹���");
		return;
	}

	if ((int)ob->query_skill("finger", 1)<75) {
		command("say ���Ǵ���μ�������ָ��������");
		command("say "+RANK_D->query_respect(ob)+"���ָ���ϻ�Ҫ�����¹���");
		return;
	}

	message_vision("$N˫ϥ�򵹣�����$n˵�������������ϣ���������Ч�ң���\n\n$n������Ц����������ƽ����$N�ӵ��Ϸ���\n\n",ob,this_object());
	ob->set_temp("title", ob->query("title"));
	command("recruit " + ob->query("id"));
	ob->set("title", ob->query_temp("title"));
	ob->delete_temp("title");
    return;
}

string ask_me_1()
{
	mapping skl; 
	object ob, me=this_player();
	string *sname;
	int i, k;

	if (me->query("family/family_name")!="����μ�")
		return RANK_D->query_respect(me)+"��ҪͶ�٣��β�ǰ����ԭ���ι���";

	if (me->query("dali/rank")<2)
		return RANK_D->query_respect(me)+"������ǳ�����������������";

	if (me->query("dali/rank")>=3)
		return RANK_D->query_respect(me)+"��Ʒ�Ѹߣ�����������ʥּ�����ˡ�";

	skl=me->query_skills();
    sname=sort_array( keys(skl), (: strcmp :) );
    for(i=0; i<sizeof(skl); i++) {
		if (skl[sname[i]]<90) k++; }
	if (k>2)
		return RANK_D->query_respect(this_player())+"���������������ʸ���ȡʥּ��";

	if (me->query("family/family_name")!="����μ�"
		&& me->query("dali/employee")) {
		if (me->query("dali/arrestmade") < (me->query("combat_exp")*3/2000))
			return RANK_D->query_respect(me)+"��������Ϊ���������������������ɡ�";
		if (me->query("dali/trust") < (100+me->query("dali/arrestmade")/20))
			return RANK_D->query_respect(me)+"���Ҵ��������������Ŭ������";
	}

	ob = new("/d/dali/obj/allow-letter3");
        ob->move(me);
	ob->set("applicant",me->query("id"));
    message_vision("$N���һ��ʥּ��\n",me);
    return "�ðɣ�ƾ���ʥּ�������ȥ����ʿ�����ս��";
}
string ask_qingyan()
{
	object me=this_player();
	mapping fam;
	
	if (me->query("family/family_name")!="����μ�")
	            return  RANK_D->query_respect(me)+"�����Ҵ�����!";
	                                
         if ((int)me->query("dali/rank")<=1)
	            return  RANK_D->query_respect(me)+"�Ƿ�Ϊ���������̫����!";
	                  
	  if (me->query("dali/qingyan")==1)
	            return  RANK_D->query_respect(me)+"�Ѿ�ѧ���������̣���Ҫ����ȡ��!";
	      
	  
	    me->set("dali/qingyan",1);
	    message_vision("������վ����������$N�������������������еİ��أ�\n",me);
            return "�����Ҵ���μҾ�ѧ�������Ժ���Ϊ������츣��";
	    }
	    	                
	      	                
	      	       	                
	     	                        
	     	                                
	                                              
#include "/kungfu/class/dali/promote5.h"
