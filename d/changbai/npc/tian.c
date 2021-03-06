
// Code of ShenZhou
// /d/changbai/npc/tian.c

inherit NPC;

void create()
{
        set_name("田归农", ({ "tian guinong", "tian" }));
        set("nickname", "天龙门北宗掌门人");
        set("long",
"他就是天龙门北宗掌门人田归农。\n"
"他长身玉立，气宇轩昂，背上负着一个包裹。\n");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1200);

        set("jiali", 40);

        set("combat_exp", 700000);

        set_temp("apply/armor", 30);

        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("wuxingbu", 160);
        set_skill("ding-force", 160);
        set_skill("wuxing-quan", 140);
        set_skill("sword", 160);
        set_skill("wugou-jianfa", 160);

        map_skill("dodge", "wuxingbu");
        map_skill("force", "ding-force");
        map_skill("sword", "wugou-jianfa");
        map_skill("parry", "wugou-jianfa");
        map_skill("unarmed", "wuxing-quan");

        prepare_skill("unarmed", "wuxing-quan");
	set("inquiry", ([

		"胡一刀" : 
		"他的胡家刀法非常的厉害，听说还留下一把宝刀。",
		"飞天狐狸" : "他的胡家刀法非常的厉害，听说还留下一把宝刀。",
        ]) );

        setup();

        carry_object("/d/changbai/obj/qinggang-jian")->wield();
        carry_object("/d/dali/obj/zipao")->wear();
}

int accept_object(object me, object obj)
{
        object where = environment(this_object());object ob = this_player();

        if ( obj->name() == "胡家刀法残篇" && obj->query("id") == "hujia daofa" ) {call_out("create_exit", 1, where);
        command( "oh" );
	command("say 你既然找到了胡家刀法，就去拜一下胡大侠的坟墓吧。\n");
           return 1;
        
};      command( "hmm" );
        command( "say 你给我这东西做什麽？" );
           
        return 0;
}

void create_exit(object where)
{
        where->set("exits/southdown","/d/changbai/fen");
}