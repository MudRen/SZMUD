//Cracked by jiuer
// 06/1/2002

inherit NPC;
string ask_camel();

void create()
{
        set_name("吐尔逊", ({ "tu ersun", "tu" }));
        set("long", "吐尔逊是个西域胡人，长着个鹰钩鼻，善骑术，被欧阳峰招来做驼夫。\n");
        set("gender", "男性");
        set("age", 25);

    set_skill("dodge", 30);
	set_skill("chanchubu", 30);
    set_skill("parry", 30);
    set_skill("force", 30);
	set_skill("hamagong", 35);
	set_skill("strike",30);
	set_skill("training",70);
    map_skill("dodge","chanchubu");
	map_skill("force","hamagong");

        set("str", 28);
        set("int", 21);
        set("con", 24);
        set("dex", 21);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 550);
        set("max_neili", 550);
        set("jiali", 10);
        set("combat_exp", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        set("inquiry", ([
			"骆驼" : (: ask_camel :),
			"坐骑" : (: ask_camel :),
			"camel" : (: ask_camel :),

        ]));

        create_family("白驼山", 3 , "弟子");
	setup();
	carry_object("/d/baituo/obj/wcloth")->wear();
	add_money("silver",3);
}
void init()
{
        add_action("return_camel", "还");
        add_action("return_camel", "return");
}
int return_camel(string arg)
{
    object ob, me = this_player();

    if( !arg || arg=="" ) return 0;

    if (!ob=present("camel", environment(me)))  return 0;

    if (ob->query_lord() != me) return 0;


    if( arg=="camel" ) {
        message_vision("$N把手中骆驼的缰绳交给了$n。\n", me, this_object());
        add("camel_count", -1);

        if(me->query("rided"))
        me->set("rided", 0);

        destruct(ob);
	return 1;
	}
}

string ask_camel()
{
	object ob, me=this_player();
	
	if (me->query("family/family_name")!="白驼山") {
                command("say 你是哪里来的" + RANK_D->query_rude(me) +
                        "到我们庄来混食？快给我滚！");
                command("kick2 " + me->query("id"));
                return ("小心我宰了你！");
        }

	if (me->query("rided") || me->query_temp("mark/驼")){
		return("你不是有坐骑了吗？");
	}	

	if (query("camel_count") > 20)
                return("骆驼都让你师兄弟们骑走了，"+ RANK_D->query_respect(me)+
                       "要出山，等他们回来在说吧。");

	ob=new("/clone/horse/btcamel");
	ob->move("/d/baituo/tuopeng");
	add("camel_count", 1);
	ob->set_lord(me);
	ob->set_leader(me);
	me->set_temp("mark/驼", 1);
		command("nod");
		say("吐尔逊到草房牵出一匹骆驼来交给你。\n");
		return(RANK_D->query_respect(me) + "路上小心，早去早归！");
}
