// snowyu dali promote quest 2002/5
inherit NPC;

void create()
{
	set_name("段延庆", ({ "duan yanqing", "duan", "yanqing" }));
	set("nickname", "恶贯满盈");
	set("long", 
"此人身形修长，其胸凸出，由如一鼓。长髯垂胸，根根漆黑。但是瘸了双腿，拄着根钢制拐杖。\n");
	set("gender", "男性");
	set("age", 55);
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 8000);
	set("max_jing",10000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 300);
	set("family/family_name", "大理段家");
	set("combat_exp", 15000000);

	set_skill("force", 400);
	set_skill("buddhism", 400);
	set_skill("dodge", 450);
	set_skill("parry", 450);
	set_skill("finger", 450);
	set_skill("kurong-changong", 450);
	set_skill("yiyang-zhi", 450);
	set_skill("duanjia-jian", 450);	
	set_skill("strike", 450);
	set_skill("staff", 450);
	set_skill("duanshi-shenfa", 450);
	map_skill("dodge", "duanshi-shenfa");
    map_skill("force", "kurong-changong");
    map_skill("finger", "yiyang-zhi");
	map_skill("staff", "duanjia-jian");
	map_skill("parry", "duanjia-jian");
	prepare_skill("finger", "yiyang-zhi");

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/xixia/obj/robe")->wear();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_temp("arrest_yanqing")) {
                command("say 哼！你身为大理臣子竟然管我们段家的家事！");
				command("say 拿命来吧！！");
				remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
				command("perform yiyang");
				ob->start_busy(10+random(5));
				
				
        }
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob= me->query_temp("last_damage_from")) && ob->query("family/family_name") == "大理段家" && ob->query_temp("arrest_yanqing")&& ob->query("dali/rank")==3) ob->add("dali/rank", 1), ob->delete_temp("arrest_yanqing") ;
	::die();
}
