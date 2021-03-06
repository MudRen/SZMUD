// mengmianr.c
// shilling 97.2
/*Updated by George 98/7
*/

inherit NPC;

int do_kill();

void create()
{
        set_name("蒙面大汉", ({"bandit"}));
        set("long",
                "一个蒙着面部，身穿黑色夜行衣服的神秘人。\n");
        set("gender", "男性");
		set("attitude", "aggressive");
		
		set("age", 20+random(30));
        set("shen_type", -1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 0);
        set("combat_exp", 10000);

        set_skill("force", 30);
        set_skill("dodge", 25);
        set_skill("parry", 20);
        set_skill("sword", 30);
        set_skill("lingbo-weibu", 25);
        set_skill("beiming-shengong", 30);
        set_skill("tianyu-qijian", 30);

        map_skill("sword", "tianyu-qijian");
        map_skill("dodge", "lingbo-weibu");
        map_skill("force", "beiming-shengong");
        setup();

        carry_object("/d/obj/changjian")->wield();
        carry_object("/d/obj/cloth")->wear();

		add_money("silver",random(20));

}
