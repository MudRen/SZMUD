// newjob/builder/
// Jiuer 11/2001
// baiquan.c ʯ��Ȫ

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void greeting(object);

void create()
{
	set_name("ʯ��Ȫ", ({ "shi baiquan", "shi", "baiquan" }));
	set_color("$YEL$");
	set("title","ʯ���ϰ�");
	set("shen_type", 0);
	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 65);
	set("long", "����һλ�������Ƶĸ���С��ͷ����ͷ��һ������ñ��
��һ����ɫ���ۣ�����˵����ͷ���й����صľ��ˡ�\n");
	set("no_get_from", 1);			
	
	set("max_jing", 5000);			//���
	set("jing", 5000);				//��
	set("max_jingli", 500);			//�����
	set("jingli", 500);				//����
	set("max_qi", 500);				//�����
	set("qi", 500);					//��
	
	set_skill("force", 100);		//�ڹ�
	set_skill("parry", 100);		//�м�
	set_skill("unarmed", 100);		
	set_skill("dodge", 100);		//�Ṧ
	set_temp("apply/attack", 120);
	set_temp("apply/attack", 120);
	set_temp("apply/damage", 50);
	
	set("combat_exp", 40000);		//����
	set("attitude", "friendly");	
		
	set("vendor_goods", ({
		 "/newjob/builder/obj/chisel",		//ʯ��
 		 "/newjob/builder/obj/hammer",		//����
      // "/newjob/builder/obj/explosive",   //ըҩ
		 "/newjob/builder/obj/axe",			//��	
         "/newjob/builder/obj/saw",         //��
		 "/clone/drug/jinchuang",			//��ҩ
		 "/clone/drug/gaoyao",				//��Ƥ��ҩ
	}) );
	setup();
	
	carry_object("/newjob/builder/obj/pao")->wear();	//�·�
}

void init()
{

	object ob;

	::init();
    if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
		remove_call_out("greeting");
        call_out("greeting", 1, ob);
	}

	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
    switch( random(2) ) {
	     case 0:
			 say(query("name")+"Ц�����˵������λ" + RANK_D->query_respect(ob)
				 + "����Ҫ��ʲô���ߣ�\n");
			 break;
	     case 1:
			 say( query("name")+"Ц����ع��˹��֣�˵������λ" + 
       RANK_D->query_respect(ob)+ "����������\n");
		     break;
	}
}

void unconcious()
{
	message_vision("\nͻȻ��ֻ��$N����������̨��һ�����ţ����˽�ȥ���������߰��������ˡ�\n", 
		this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}

int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        return 1;
}
