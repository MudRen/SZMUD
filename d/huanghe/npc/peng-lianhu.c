// Code of ShenZhou
// peng-lianhu ������

inherit NPC;
int auto_throw();
void create()
{
	set_name("������", ({ "peng lianhu", "peng" }));
	set("nickname", "ǧ������");
	set("long", 
"�����������ģ����ۺ�˿��Ŀ����磬�ϴ���������������
�б�����ɳͨ�������Ľ��顣\n");
//	set("title", "");
	set("gender", "����");
	set("age", 49);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 23);
	set("con", 25);
	set("dex", 22);
	
	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 320000);
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_throw :),
        }) );


	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("wuxingbu", 90);
	set_skill("parry", 95);
	set_skill("cuff", 90);
	set_skill("wuxing-quan", 120);
	set_skill("club", 100);
	set_skill("ding-force", 100);
	set_skill("liuhe-qiang", 120);
	
	map_skill("club", "liuhe-qiang");
	map_skill("parry", "liuhe-qiang");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff", "wuxing-quan");
        map_skill("force", "ding-force");

        prepare_skill("cuff", "wuxing-quan");

	setup();
	carry_object("/clone/weapon/panguanbi")->wield();
	carry_object("/d/shaolin/obj/beixin")->wear();
	carry_object("/clone/weapon/jqbiao")->set_amount(7);
}

/*void unconcious()
{
        command("say ���ֵܣ�����צ��̫Ӳ�����������");
        message_vision("\n$N������ǽ��һ�������������ֳ��İ����\n", this_object());
        destruct(this_object());
}
*/
#include "/clone/npc/auto_throw.h";
