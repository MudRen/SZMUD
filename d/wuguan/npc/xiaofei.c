//Cracked by Kafei
// xiaofei.c ����
// qfy July 30, 1996
// modified by ryu, 10/4/97

inherit NPC;
int auto_throw();
void create()
{
	set_name("����", ({ "xiao fei", "xiao", "fei" }));
	set("long", "������������ݵİ�������ͷ��Ϊ�˻�����ı��\n");
	set("nickname", "���컨��");
	set("title", "��ݽ�ͷ");
	set("gender", "����");
	set("age", 32);

	set_skill("literate", 50);

	set_skill("finger", 55);
	set_skill("force", 55);
        set_skill("literate", 10);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("taixuan-gong",40);
	set_skill("liuxing-bu",45);
	set_skill("yingxiong-sanzhao",55);
	map_skill("finger","yingxiong-sanzhao");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	prepare_skill("finger","yingxiong-sanzhao");
	//set_skill("throwing", 70);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_throw :),
        }) );
	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/feibiao1");
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob=this_player()) && (int)ob->query_temp("mark/��") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say ��ӭ��λ"+RANK_D->query_respect(ob)+"���������ѧ����(throwing)��ָ��(finger)���ڹ�(force)���м�(parry)���Ṧ(dodge)��");
}


int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/��"))
		return 0; 
	return 1;
}
#include "/clone/npc/auto_throw.h";
