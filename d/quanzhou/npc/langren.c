// Code of ShenZhou
// langren.c �ձ�����

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ձ�����", ({ "lang ren", "wu shi", "lang", "ren" }) );
	set("gender", "����");
	set("age", 20+random(30));
	set("long",
		"���Ǹ���̬�ư��Ķ�����ʿ��ͷ�����ң����ŻҺ�ɫ�ĺͷ���������Űѳ�������ʿ����\n");
	set("combat_exp", 150000+random(5000));
        set("shen_type", -1);
	set("attitude", "heroism");

	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :)
	}) );

	set("str", 28);
	set("con", 30);
	set("int", 15);
	set("dex", 27);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);

	set_skill("blade",   60+random(60));
	set_skill("unarmed", 60+random(40));
	set_skill("parry",   60+random(60));
	set_skill("dodge",   60+random(60));

	setup();

        carry_object("/d/quanzhou/obj/wushidao")->wield();
        carry_object("/d/quanzhou/obj/wushifu")->wear();
}

void init()
{
	::init();
	if( this_player()->query("combat_exp") <= 5000 & random(5) == 0) {
		message_vision("�ձ���������ص���$Nһ�ۣ�˵�����й��˶��������û�ðɣ���������\n", 
		this_player());
	}	
	else if( this_player()->query("combat_exp") <= 10000 & random(5) == 0) {
		message_vision("�ձ����˶���$N��Ц�������������������Ѫ��ϴ�ҵĵ������䣡\n", 
		this_player());
	}	
}
