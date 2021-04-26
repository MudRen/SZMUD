// Code of ShenZhou

#include <ansi.h>
#include "mingjiao_npc.c"
#include "mingjiao_job.h"

string ask_job();

void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;

        set_name("��Ȼ", ({ "xin ran","xin"}) );
        set("title", "�����һ�������ʹ");
        create_family("����",37,"����ʹ");
        set("gender", "����");
        set("age",35);
        set("long", "
����
\n");
        set("attitude", "peaceful");
        set("shen", 1000000);
        
	I_inquiry["name"]="���¾��������һ�������ʹ��Ȼ����֪�����к�ָ�̡�";
	I_inquiry["job"]=(: ask_job :);
	I_inquiry["����"]=(: ask_job :);
	I_inquiry["abandon"]=(: ask_abandon :);
	I_inquiry["����"]=(: ask_abandon :);
	
	Skill_name=({"shenghuo-xuanming","wuxing-bu","duoming-bi",
		     "riyue-shenzhang","shenghuo-quan","guangming-xinfa"});

	Set_Inquiry(I_inquiry,Skill_name);

	Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="duoming-bi";
//	S_skills["stroke"]="duoming-bi";
//	S_skills["strike"]="riyue-shenzhang";
//	S_skills["cuff"]="shenghuo-quan";
//	set_skill("guangming-xinfa",100+random(20));
	set_skill("literate",100+random(20));
	
//	Set_Npcskills(100,20,S_skills);
	
//	prepare_skill("cuff","shenghuo-quan");
//	prepare_skill("strike","riyue-shenzhang");

        setup();

	carry_object(OBJ_PATH"/changpao")->wear();
	carry_object(OBJ_PATH"/panguan-bi")->wield();

}


string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
        return "��λ"+RANK_D->query_respect(player)+"�����ҽ̵��֣��Ǹ������Ǹҷ��ɸ���ʲô�����ء�\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "��λ"+RANK_D->query_respect(player)+"û���ҽ��������������μ�¼���͹�ʧ��\n";

//	if (fam["generation"] <37)
//		 return "��λ"+RANK_D->query_respect(player)+"�ѹ�Ϊ�ҽ�"+fam["title"]+"������ͷ���ܡ�\n";

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","huo_zaoqiang");
	
	return "���һ����ڽ��ڸ���������������죬�����Ҫ�ӽ������ǹ����ȥ\n"
		"��ɽ����Щ���ǣ���ȥ�����ҪЩ������Ȼ�󵽻𷿴����ǹ��\n"
		"��ǹ�����޴����ҽ̵������˵���Ҫ�������㶨ҪС�����⡣\n";


		 
}   


int accept_object(object me, object ob)
{
	string name;
	string job_flg;
//	object room;


	name = ob->query("id");	
	if ( name != "huo qiang")
		return 0;

	job_flg = judge_jobmsg(me,1);

	if ( job_flg !=  "�����ǹ" ) 
	{
		command("hmm "+me->query("id"));
		command("say ����û����������������Ļ�ǹ�����ǹ����Σ�գ����������ˡ�");
		return 1;
	}
	else
	{
		command("thumb "+this_player()->query("id"));
		command("say ��λ�ֵ�������!��ȥ�ú���Ϣ��Ϣ��");
//	        if (!(room = find_object("/d/kunlun/mj_center.c")))
//			room = load_object("/d/kunlun/mj_center.c");
//		room->add("jingtie",1);
		remove_call_out("reward_dest");
		call_out("reward_dest",1,this_player(),ob,job_flg);
		return 1;
	}
	
	return 0;

}

