                                       //Create by cheap
// Jay 11/9/01

// Code Last Update by Scatter on 12/31/2001

// MODIFY INFORMATION
/*
        This fix the problem of the owner ship for the car.
*/

inherit NPC;
string ask_car();

void create()
{
        set_name("风大贵", ({ "feng dagui","feng","dagui" }));
        set_color("$HIW$"); 
        set("long", "他是矿车行的老板，他生得粗眉大眼，一副凶恶的样子。\n");
        set("title","车行老板");
        set("gender", "男性");
        set("age", 47);
        set("no_get_from", 1);
        set("max_jing", 5000);
        set("jing", 5000);
        set("max_jingli", 500);
        set("jingli", 500);
        set("max_qi", 500);
        set("qi", 500);
        set("PKS", 1000000);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 120);
        set_temp("apply/attack", 120);
        set_temp("apply/damage", 50);

        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("inquiry", ([
                "租车" : (: ask_car :),
                "矿车" : (: ask_car :),
]));
        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{     
        add_action("return_car", "还");
        add_action("return_car", "return");
                add_action("return_car", "huan");
}
int return_car(string arg)
{
                object ob , me ,che;
                                me = this_player();   
                                che = this_object();
                
                                if (me->query("rided") || me->query_temp("mark/车"))
                                {
                                if( !ob=present("xiao tuiche", environment(me))) 
                                        return notify_fail("车呢？ \n");
                            if( ob->query("owner") != me->query("id"))
                                        return notify_fail("这不是你的车! \n");
 //               if (ob->query_lord() != me) return 0;
                
                                if( arg!="che" ) 
                                {
                                        message_vision("你要还什么啊？",me);
                                }
                else
                {
                        message_vision("仆人过来把车推走。\n欢迎下次在来。\n", me, this_object());
                        add("car_count", -1);    
                        if(me->query("rided"))
                        me->set("rided", 0);
                                                me->set_temp("mark/车", 0); //以前没有这句所以还了车也不能再要了
                        destruct(ob);
                        return 1;
        }
                                }else
                                return notify_fail("你没有在这里租车! \n");
}
string ask_car()
{
                object ob , me;
                me = this_player();

        if (me->query("rided") || me->query_temp("mark/车"))
                {
                        return("你不是租了车吗？");
        }

        if (query("car_count") > 10)
            return("对不起，所有的矿车都租了出去,要得他们还了在说吧。");

                ob=new("/newjob/tiejiang/obj/xiao_tc");
        ob->move("/newjob/tiejiang/gate");
                ob->set("owner",me->query("id"));

        add("car_count", 1);
        ob->set_lord(me);
        ob->set_leader(me);
        me->set_temp("mark/车", 1);
        say("请你去前门拿车了。\n");
        return(RANK_D->query_respect(me) + "记得早点还车啊。");
}

