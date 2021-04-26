// Code of ShenZhou
#include <ansi.h>
#define OBJ_PATH "/d/mingjiao/obj"
#define MINGJIAO "/d/mingjiao/"
#include "/d/mingjiao/obj/time_all.h"
inherit NPC;


string ask_tyling()
{
	object player=this_player();
	object ling;
    mapping fam ;
	int comexp;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
		return "��λ"+RANK_D->query_respect(player)+"���������̵��֣�����������\n";


	if(objectp(ling = present("tieyan ling", player)) )
		return "�����������������ÿ�����������ʱ�������ҽ̹���ʹ�߷���һ�顣ƾ��\n"
		"�����������ֵ�����书�����ǹ������ͣ������¼������������ϡ��������ϵ��\n"
		"��"+RANK_D->query_respect(player)+"��Ī��ʧ���������ڣ�����������\n";
	else
		if(query("id")=="leng qian"&&query("name")=="��ǫ")
		{
			comexp=player->query("mingjiao/credit");
			if(comexp)
				comexp=comexp-comexp/50;
			if(comexp<=0)
				comexp=0;
			command("say ����������õ��ܷ���\n");
			tell_object(player,HIB"������������½��ˡ�\n"NOR);
			player->set("mingjiao/credit",comexp);
			
			ling = new("/d/kunlun/obj/tieyanling");
			ling->move(player);

			message_vision("$N�������ó�һ���������$n��\n",this_object(),player);
			return player->query("name")+"���պã������ٶ���\n";
		}
		
		else
			return "�����������������"+RANK_D->query_respect(player)+"���ɶ�ʧ����ȥ����ִ��������ʧ��\n";


}

void attempt_apprentice(object ob)
{
		command("say �ҹ���ʥ������û��ʦͽ֮��ֻ�еȼ�֮�֣�����֮������໥�������ա������ҽ������Ĺ�ء�" + RANK_D->query_respect(ob) +"��Ҫѧ��Ļ�������������������ֵ���̡�\n");
		
		return;
}


void Set_Inquiry(mapping I_inquiry,mixed Skill_name)
{
	int i;
	string str_skill;
	mapping I_inquiryS;
	if(sizeof(I_inquiry))
		I_inquiryS=I_inquiry;
	str_skill="";

	if(i=sizeof(Skill_name))
	{
		set("teach_skillsname",Skill_name);
		for(i=0;i<sizeof(Skill_name);i++)
		{
			str_skill=str_skill+to_chinese(Skill_name[i])+"("+Skill_name[i]+")"+"\n";
			
		}
	
		I_inquiryS["�书"]="���²��ţ��ܴ��ڸ����µ��书��\n"+str_skill+"\n�������ѧ��ֻ���������( qingjiao <ĳ��> <����> [����])���Ϳ����ˡ�\n";
	}
	else
		I_inquiryS["�书"]="�����书��΢�����²��ܴ��ڸ���ʲô�书�����������������\n";

	I_inquiryS["������"]=(: ask_tyling :);
	set("inquiry",I_inquiryS);

	
	return;
}

int Set_Action()
{
	object ob=this_object();
	if(ob->query("teach_skillsname"))
	{
		add_action ("do_qingjiao", "qingjiao");

	}
}


void Set_Npcattrib(int Basic_Attrib,int Random_var,
				   int Maxqi,int Random_Maxqi,
				   int Maxjing,int Random_Maxjing,
				   int Maxjingli,int Random_Maxjingli,
				   int Maxneili,int Random_Maxneili,
				   int Exp,int Random_Exp)
				  				  
{
	int Mneili=Maxneili+random(Random_Maxneili);
	set("str", Basic_Attrib+random(Random_var));
	set("int", Basic_Attrib+random(Random_var));
	set("con", Basic_Attrib+random(Random_var));
	set("dex", Basic_Attrib+random(Random_var));
	set("max_qi", Maxqi+random(Random_Maxqi));
	set("max_jing", Maxjing+random(Random_Maxjing));
	set("eff_jingli", Maxjingli+random(Random_Maxjingli));
	set("max_neili", Mneili);
	set("neili",Mneili);
	set("combat_exp", Exp+random(Random_Exp));
	return;
}

void Set_Npcskills(int Basic_skill,int Random_skill,mapping S_skills)
{
	int i;
	mixed S_name;
	
	if(i=sizeof(S_skills))
	{
		S_name=keys(S_skills);
		for(i=0;i<sizeof(S_name);i++)
		{
			set_skill(S_name[i], Basic_skill+random(Random_skill) );
			set_skill(S_skills[S_name[i]], Basic_skill+random(Random_skill) );
			map_skill(S_name[i],S_skills[S_name[i]]);
		}
	}

	set("jiali",(Basic_skill+Basic_skill/2)/2);
	return;
}


int prevent_learn(object me, string skill)
{
	return 0;
}

void set_title(object player, int generation)
{
	string title;

	switch(generation)
	{
		case 33:
			title = "����";
			break;
		case 34:
			title = "����ʹ��";
			break;
		case 35:
			title = "���̷���";
			break;
		case 36:
			title = "ɢ��";
			break;
		case 37:
			title = "����ʹ";
			break;
		case 38:
			title = "����";
			break;
		default:
			title = "����";
	}

	player->set("title","����"+title);

}
