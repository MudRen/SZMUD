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

        set_name("��ԫ", ({ "yan yuan","yan"}) );
        set("title", "���̺���������ʹ");
        create_family("����",37,"����ʹ");
        set("gender", "����");
        set("age",35);
        set("long", "
����
\n");
        set("attitude", "peaceful");
        set("shen", 1000000);
        
	I_inquiry["name"]="���¾������̺���������ʹ��ԫ����֪�����к�ָ�̡�";
	I_inquiry["����"]=(: ask_job :);
	I_inquiry["job"]=(: ask_job :);
	I_inquiry["����"]=(: ask_abandon :);
	I_inquiry["abandon"]=(: ask_abandon :);

	Skill_name=({"shenghuo-xuanming","wuxing-bu","bagua-dao",
		     "riyue-shenzhang","shenghuo-quan","guangming-xinfa"});

	Set_Inquiry(I_inquiry,Skill_name);

	Set_Npcattrib(23,5,2000,300,4000,400,4000,300,3000,1000,700000,50000);

//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["dodge"]="wuxing-bu";
//	S_skills["parry"]="bagua-dao";
//	S_skills["blade"]="bagua-dao";
//	S_skills["strike"]="riyue-shenzhang";
//	S_skills["cuff"]="shenghuo-quan";
//	set_skill("guangming-xinfa",100+random(20));
	set_skill("literate",100+random(20));
	
//	Set_Npcskills(100,20,S_skills);
	
//	prepare_skill("cuff","shenghuo-quan");
//	prepare_skill("strike","riyue-shenzhang");

        setup();

	carry_object(OBJ_PATH"/changpao")->wear();
	carry_object(OBJ_PATH"/blade")->wield();

}


string ask_job()
{
     object player=this_player();
     mapping fam ;
     object ling,qiao;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
        return "��λ"+RANK_D->query_respect(player)+"�����ҽ̵��֣��Ǹ������Ǹҷ��ɸ���ʲô�����ء�\n";

	if(!objectp(ling = present("tieyan ling", player)) )
		return "��λ"+RANK_D->query_respect(player)+"û���ҽ��������������μ�¼���͹�ʧ��\n";

//	if (fam["generation"] <37)
//		 return "��λ"+RANK_D->query_respect(player)+"�ѹ�Ϊ�ҽ�"+fam["title"]+"������ͷ���ܡ�\n";

	if ( player->query("mingjiao/job")=="tu_didao" && player->query_temp("didao_done") )
	{
		command("haha "+player->query("id"));
		if (qiao=present("tie qiao",player))
			destruct(qiao);
		command("say ���ǵĵص�����ǰ����һ����");
		player->delete_temp("didao_done");
		remove_call_out("reward");
		call_out("reward",1,this_player(),"�ڵص�");
		return player->query("name")+"�ɵò�������ȥ�ú���Ϣ��Ϣ��\n";
	}

	if(player->query("mingjiao/job"))
		return judge_jobmsg(player,0);

	command("nod "+player->query("id"));

	player->set("mingjiao/job","tu_didao");
	
	qiao=new(OBJ_PATH"/qiao");
	qiao->move(player);
	tell_object(player,"��ԫ����һ�����¡�\n");
	
	return "���Ǻ����츺���ڵص����������д��ó�����ȥ��������һ�𽫵ص�����㡣\n";

}   



