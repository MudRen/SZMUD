// Code of ShenZhou
// Npc: /d/mingjiao/mingjiao_shouwei.c
// Date: Wzfeng@xkx 99 6 

#include "mingjiao_npc.c"


int ask_rujiao();
int find_yang(object player);

void create()
{
	mapping S_skills= ([ ]);
	set_name("��������", ({"mingjiao shouwei","shouwei",}));
    set_weight((random(2)+ 1) * 1300000);
	set("long",
		"����һ�����̵�ɽ��������һ���ʵ�ļ����Գ��������书�ҵס�\n"
		"��ͷϵ��ɫͷ������ɫ����ʥ�ۣ�ʥ��������һ�������档\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("age", 25);
	set("shen_type", 1);
	set("inquiry", ([
		"���": (: ask_rujiao :),
		"join": (: ask_rujiao :),
		]));

	Set_Npcattrib(20,1,1000,300,500,100,1000,100,1000,100,100000,10000);

	set_skill("force", 30+random(10));
	set_skill("dodge", 30+random(10));
	set_skill("parry", 30+random(10));
	set_skill("blade", 30+random(10));
	set_skill("sword", 30+random(10));
	

/*	if(!get_day())
	{
	set("chat_chance", 1);
    set("chat_msg", ({
		"��������ǿ����,�ȵ�������������ҹ�䣬�ֵ���Ҫ��ǿ�ػ�����ֹ�����ɵļ�ϸ�����ҹ���ʥ�̣�\n",
        }) );
	}
	*/
	create_family("����", 38, "����");
	
	setup();
	carry_object(OBJ_PATH"/blade")->wield();
	carry_object(OBJ_PATH"/changpao")->wear();

}

int ask_rujiao()
{
     object player=this_player();
     mapping fam = player->query("family");
//Ϊ��test�������ʽ������Ҫ��
	 	 if(player->query_temp("ask_rujiao"))
	 {
	 	 tell_object(player,"������������˵�������㲻���Ѿ��ʹ����𣿡�\n");
		 return 1;
	 }
	 
     
	 if (!fam || fam["family_name"] != "����")
		 if(player->query("combat_exp")<10000)
	 {
		 command("say "+RANK_D->query_respect(player)+"�����ҽ���Ե�������ȥ������ʹ��������Ϊ�������̴�䡣\n");
		 player->set_temp("ask_rujiao",1);
         message_vision("������������첽��ȥ��\n",this_object());
		 player->start_busy(3);
         remove_call_out("find_yang");
         call_out("find_yang", 1, player);

               return 1;
     }
		 
			 if(fam["family_name"] == "����")
			 {
				 command("say "+"�ҿ���λ"+RANK_D->query_respect(player)+"�����ҽ̽��ڣ����������ʲô��\n");
				 return 1;
			 }
	command("say "+"�ҿ���λ"+RANK_D->query_respect(player)+"���ǽ������֣��ҽ̿��²���������������ذɡ�\n");
		 

	return 1;
}

int find_yang(object player)
{
	object yang,where,room;
	object me=this_object();
    if(!( room = find_object(MINGJIAO"/shting")) )
       room = load_object(MINGJIAO"/shting");
	me->move(room);
	if(!objectp(yang = present("yang xiao", room) )||!living(yang)||yang->is_busy())
		{
	        	me->move(MINGJIAO"/damen");
        	     message_vision("\n���������첽���˹�����\n", me);
				message_vision("����������$n���˸�ȭ��˵����������ʹ���ڹ���æ����ʱ�޷��������̴�䣬���´������ɡ�\n", me,player);
				return 1;
			
		}
    message_vision("$N�첽���˹�������$n��ȭ˵������ɽ������������ҽ̣���������ʹΪ�������̴�䡣\n", me, yang);
	message_vision("$N��$n���˵�ͷ˵�������ã������ȥ��\n", yang,me);
	message_vision("�����������˳�ȥ��\n", me);
    me->move(MINGJIAO"/damen");
	yang->move(MINGJIAO"/damen");
	message_vision("$N���˳�ȥ��\n", yang);
	message_vision("�����������˹�����\n", me);
	message_vision("�������˹�����\n", me);
	yang->rujiao(player);
	player->start_busy(4);
	
	return 1;
}



void init()
{


}

