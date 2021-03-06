// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("黄眉大师", ({ "huangmei dashi", "dashi", "monk"}));
        set("long", 
"一个满脸皱纹，身形高大的老和尚，两道焦黄的长眉，眉尾下垂。。\n");
        set("gender", "男性");
        set("age", 75);
        set("rank_info/respect","大师");

        set_skill("finger", 150);
        set_skill("yizhi-chan", 140);
        set_skill("dodge", 130);
        set_skill("shaolin-shenfa", 130);
        set_skill("parry", 120);
        set_skill("force", 125);
        set_skill("hunyuan-yiqi", 120);
        set_skill("damo-jian",80);
        set_skill("sword",80);
        set_skill("buddhism",160);
        map_skill("finger","yizhi-chan");
        map_skill("sword","damo-jian");
        map_skill("dodge","shaolin-shenfa");
        map_skill("parry", "yizhi-chan");
        map_skill("force","hunyuan-yiqi");
        prepare_skill("finger","yizhi-chan");

        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 40);

        set("combat_exp", 800000);

        set("attitude", "peaceful");
        set("shen_type", 1);
        create_family("南少林普陀下院", 10, "弟子");
        setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
void attempt_apprentice(object ob)
{
        command("shake");
        command("say 老衲未得南少林住持许可，不能收徒。");
        return;
}
