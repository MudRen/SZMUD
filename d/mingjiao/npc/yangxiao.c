// Code of ShenZhou

#include "mingjiao_npc.c"
#include <ansi.h>


int rujiao(object player);
int rujiao1(object player);
void create()
{
		mapping S_skills= ([ ]);
		mapping I_inquiry=([ ]);
		mixed Skill_name;
        set_name("����",({"yang xiao","yang","xiao"}));
        set("title", "���̹�����ʹ");

        set("long", "
���������̵Ĺ�����ʹ���ͷ�ң�ϳ���ң���ɵ����С�
������һ���������Ȼ�������꣬������ȥ��ʮ��Ӣ��������\n");
        set("gender", "����");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen", 3000000);
        create_family("����",34,"ʹ��");
		
		I_inquiry["name"]="���¾������̹�����ʹ���У���֪�����к�ָ�̡�";

	Skill_name=({"shenghuo-xuanming","xiaoyao-piaopiao","xiaoyao-zhangfa",
		     "xiaoyao-jianfa","riyue-shenzhang","shenghuo-quan","guangming-xinfa"});
		Set_Inquiry(I_inquiry,Skill_name);

		Set_Npcattrib(27,5,5000,300,7000,400,9000,300,5000,1000,3000000,100000);

//	S_skills["dodge"]="xiaoyao-piaopiao";
//	S_skills["parry"]="qiankun-danuoyi";
	S_skills["sword"]="xiaoyao-jianfa";
//	S_skills["force"]="shenghuo-xuanming";
//	S_skills["cuff"]="shenghuo-quan";
//	S_skills["strike"]="xiaoyao-zhangfa";
//	set_skill("riyue-shenzhang",300+random(20));
//	set_skill("guangming-xinfa",380+random(20));
	set_skill("literate",300+random(20));
	
	Set_Npcskills(300,20,S_skills);
	
	prepare_skill("strike","xiaoyao-zhangfa");
	

        setup();

	carry_object(OBJ_PATH"/changpao")->wear();
	carry_object(OBJ_PATH"/sword")->wield();
}

int rujiao(object player)
{
	
	command("hi"+" "+player->query("id"));
	command("look"+" "+player->query("id"));
	player->start_busy(4);

    remove_call_out("rujiao1");
    call_out("rujiao1", 3, player);



}
int rujiao1(object player)
{
	object ling;
	command("say "+"�ã���Ȼ��λ"+RANK_D->query_respect(player)+"������ҹ���ʥ��̣���ô�ӽ������������������ͽ��\n");
	player->create_family("����",38,"����");
	set_title(player,38);
	tell_object(player,HIC"��ϲ����Ϊ���̽��ڣ�\n"NOR);

	
	command("say "+"��λ"+RANK_D->query_respect(player)+"����������\n");
	message_vision("$N������ȥ��\n$n��������������ȥ��\n",this_object(),player);
	move(MINGJIAO"/daguangchang");
	player->move(MINGJIAO"/daguangchang");
	message_vision("$N����������\n$n������������������\n",this_object(),player);	
	//here need add later
	message_vision("$N��$n˵������������������صع�������\n",this_object(),player);	
    if(objectp(ling = present("tieyan ling", player)) )
	{
		message_vision("$N��$n˵����������ҽ̣����������ҽ̵�����������ʲôbug��㱨��wzfeng��\n",this_object(),player);	
		return 1;
	}
	ling = new(OBJ_PATH"/tieyanling");
	ling->move(player);
	tell_object(player,"���дӻ���ȡ��һ��״�ƻ�������ơ�\n");
	tell_object(player,"���ж���˵���������ҽ�����<������>������Ҫ����Я�������ɶ�ʧ��\n");
	tell_object(player,"���и���һ�������\n");
	command("say "+"������ҽ̣�����������ߣ����������������뽭������������Ρ�\n");
	command("say "+"�����ȥ�����죬��������ѧЩ���ŵĹ���\n");
	command("say "+"�һ���Ҫ���������и��ˡ�\n");
	move(MINGJIAO"/shting");
	message_vision("$N���˹�����\n",this_object());
	return 1;
	

}

