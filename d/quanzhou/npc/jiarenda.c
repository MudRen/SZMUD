// Code of ShenZhou
//Jay 3/31/97
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("���˴�", ({ "jia renda","jia","renda" }));
	set("long", 
		"��ͷ�ϲ��˰ײ���һ�����ۣ�����˹�Ĵ�磬ȴ���������ȶ������³��㣬�����޶���Ь��\n"
		"�������װ�������ǵ������������������Ϊ����Т������Ű��������ǧ��֮�£��ײ��Բ�ȥ�ס�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 28);
	set("int", 18);
	set("con", 26);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);

	set_skill("force", 40);
  	set_skill("huagong-dafa", 25);
	set_skill("dodge", 30);
	set_skill("zhutian-bu", 40);
	set_skill("claw", 40);
	set_skill("sanyin-zhua", 40);
	set_skill("parry", 20);
	set_skill("sword", 40);
	set_skill("taiji-jian", 30);
	set_skill("san-sword",35);
  	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
        map_skill("sword","san-sword");
	map_skill("dodge", "zhutian-bu");
	map_skill("claw", "sanyin-zhua");
	map_skill("parry", "taiji-jian");

	prepare_skill("claw", "sanyin-zhua");

	create_family("�����", 5, "����");

	setup();
	carry_object("/clone/weapon/emeici")->wield();
	carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
}

void attempt_apprentice(object me)
{
	command("say ����ɵ��Ӳ��������ͽ��");
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("pixie jianpu",ob)) {
           message_vision(
           HIY "$NͻȻ�ٽź�ɨ����$n������Ц����ԭ����Ҳ��Ҫ��а���ף�\n"
            NOR, this_object(), ob );
	   command("follow " + ob->query("id"));
           kill_ob(ob);
        }
}


