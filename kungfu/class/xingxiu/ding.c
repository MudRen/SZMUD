// ding.c 丁春秋
#include "/kungfu/class/xingxiu/auto_perform.h"
#define ANTI_ROBOT "/u/yeer/robot"
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void no_answer(object user);
string ask_me();
string ask_zhen();
int auto_perform();
int ask_ding();
int ask_book();
int ask_poison();
string ask_suo();
string ask_wxs();
int ask_staff();
int do_answer(string arg);
int ask_job();
int ask_chname();
void create()
{
        set_name("丁春秋", ({ "ding chunqiu", "ding" }));
        set("nickname", "星宿老怪");
        set("long",  "他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。\n"
                     "可是他看起来形貌清奇，仙风道骨。\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 40);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 4500);
        set("max_jing", 2500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("combat_exp", 3500000);
        set("shen", -400000);
        set("apply/armor", 50);
        set("PKS", 1000000);

        set_skill("force", 400);
        set_skill("huagong-dafa", 400);
        set_skill("dodge", 360);
        set_skill("zhaixinggong", 400);
        set_skill("strike", 360);
        set_skill("claw", 360);
        set_skill("sanyin-zhua", 360);
        set_skill("poison", 400);
        set_skill("chousui-zhang", 360);
        set_skill("parry", 360);
        set_skill("staff", 360);
        set_skill("tianshan-zhang", 400);
        set_skill("feixing-shu", 360);

        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "chousui-zhang");
        map_skill("parry", "tianshan-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("sword", "tianshan-zhang");

        prepare_skill("strike", "chousui-duzhang");
        prepare_skill("claw", "sanyin-zhua");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        create_family("星宿派", 1, "开山祖师");
        //set("class", "taoist");
        set("san_count", 3);
        set("suo_count",1);
        set("zhen_count", 7);
        set("wxs_count",3);
        set("inquiry", ([
                "逍遥三笑散" : (: ask_me :),
                "碧磷针" : (: ask_zhen :),
                "柔丝索" : (: ask_suo :),
                "工作" : (: ask_job :),
                "job" : (: ask_job :),
                "无形散" : (: ask_wxs :),
                "披风杖" : (: ask_staff :),
                "更名" : (: ask_chname :),
                "冰蚕剧毒" : (: ask_poison :),
                "解毒" : (: ask_poison :),
                "book" : (: ask_book :),
                "易筋经残篇" : (: ask_book :),
                "神木王鼎" : (: ask_ding : ),
        ]));

        setup();
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/sanxiao");
        carry_object("/d/xingxiu/obj/rousi-suo");
}


void init()
{
        object ob,ob1;
        string poison;
               
        ::init();
        add_action("do_answer", "answer", 1);
        if( interactive(ob=this_player()) && ob->query_condition("bingcan_posion") ) {
                   command("?" + ob->query("id"));
                   command("say" + ob->query("name") + "好徒儿,你似乎中了冰蚕剧毒。\n");
           }
        
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && ob->query("shen") > 100 && ob->query("id")!="wsky") {
                command("say " + RANK_D->query_rude(ob) + "，你胆敢替白道的做事，显然是不想在我这混了吧。\n");
                command( "expell " + ob->query("id"));
        }
        if (interactive(ob=this_player()) && ob->query("family/master_id") == "ding chunqiu"
        && (!present("yu di", this_player()))){
                ob1=new("/d/xingxiu/obj/yudi");
                ob1->move(this_player());
                command("say 这只玉笛是咱们星宿弟子的护身符，你好好拿着，不可弄丢。");
                write("丁春秋给你一只玉笛。\n");
        }
        add_action("do_flatter", "flatter");
}
int ask_book()
{
        object ob;
     object me=this_player();

       if(me->query("canbook")==1 && (!present("yijinjing", me)) ) {
                tell_object(me,"丁春秋说道：“好徒儿，还没参透这本易筋经的奥秘么？\n");
                tell_object(me,"那好吧。这本副本给你，拿回去好好参悟吧！\n");
                tell_object(me,"徒儿你一定要记住，千万配合神木王鼎一起修炼，要不然很容易走火入魔。”\n");
                ob=new("/d/quest/xingxiu/obj/book2.c");

                ob->move(me);
                write("丁春秋给你一本易筋经。\n");
                return 1;
        }
        else
                return 0;
}
int ask_ding()
{       
        object ob;
        object me=this_player();
        if(me->query("ask/ding")==1 && (!present("shenmu wangding",me)) && me->query("family/master_id") == "ding chunqiu")
        {
                tell_object(me,"幸亏你把阿紫捉回来，神木王鼎才得以失而复返，你既然需要就拿去吧。\n");
                ob=new("/d/quest/xingxiu/obj/muding.c");

                ob->move(me);
                return 1;
        }
        else return 0;
        
}
        
int ask_poison()
{
        object ob=this_player();
        if(ob->query("family/master_id" )=="ding chunqiu" && ob->query_condition("bingcan_poison")) 
        {
        tell_object(ob,"要解冰蚕剧毒有两种办法，如果有易筋经残篇，
        然后配合神木王鼎修炼化功大法，这点毒算得了什么！
        可惜啊，那本残篇至尽仍然下落不明，如果你能找到那
        本书的话，我看了以后必然能弥补化功大法的缺憾。除
        此之外，只能靠药物逃过此劫了！\n");
        return 1; }
        else
        return 0;
        
}       

int do_answer(string arg)
{
        int result;
        object me = this_object(), user = this_player();
        result = ANTI_ROBOT->do_answer(arg, user, me);

        if (result == 2) {
                command("whisper " + user->query("id") + " 好！好！好！老仙现在放心了。");
                command("say " + user->name(1) + "，你有什么问题只管问我吧！");
                user->set("passed_ding", 1);
                return 1;
        }

        if (result == -1) {
                command("hummer " + user->query("id"));
                command("say " + user->name(1) + "你这个畜生！居然敢欺骗老仙，给我滚一边去。");
                user->add("ding_robot", 1);
                user->set("robot_ding", user->query("mud_age") + user->query("ding_robot")*600);
                return 1;
        }

        return result;
}

void no_answer(object user)
{
        if(objectp(present(user->query("id"), environment()))) {
        command("beep " + user->query("id"));
        command("heihei " + user->query("id"));
        command("say " + user->name(1) + "，你以为你装马虎我就治不了你了吗！");
        command("say 给我滚一边去吧！");
        }
else {
        command("tell " + user->query("id") + " " + user->name(1) + "，你以为你装马虎我就治不了你了吗！");
        command("tell " + user->query("id") + "你暂时用不着给老仙做事了！");
}
        user->add("ding_robot", 1);
        user->set("robot_ding", user->query("mud_age") + user->query("ding_robot")*600);
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100000) {
                command("say 老仙越看你越象白道派来卧底的。");
                return;
        }
        if( me->query("family/family_name") == "丐帮"
        && me->query("combat_exp") >= 10000 ) {
                command ("say 老仙生平最恨叫化子，你给我滚得远远的！");
                return;
        }
        if ((int)me->query_skill("poison", 1) < 50){
                command("say " + RANK_D->query_respect(me) +
                        "的毒炼得这么差劲，去多抓几年虫子再说吧。");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                return;
        } else {
                command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
                message_vision("星宿老怪微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        object ob;
        string name, new_name;
        mapping fam;
        int x;
        int contribution=this_player()->query("xingxiu/contribution");
        
        fam=this_player()->query("family");
        
        if (this_player()->query_temp("pending/flatter")){                      
                if( !arg ) return notify_fail("你说老仙什么？\n");
                this_player()->set_temp("pending/flatter", 0);
                message_vision("$N大声说道：" + arg + "\n", this_player());
                if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
                        || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
                        command("smile");
                        this_player()->set("oldname", name);
                        name = this_player()->query("name");
                        x=random(3);
                        if (x==3)               
                                new_name =  name[0..01] + name[2..3] + "子";
                        else if (x==2) 
                                new_name =  name[2..3] + name[0..01] +  "子";
                        else if (x==1)
                                new_name =  name[0..01]+ "玄" + "子";
                        else 
                                new_name =  name[0..01]+ "凡" + "子";
                        
                        command("say 这还差不多，从今以后你的名字叫做" + new_name + "。");
                        this_player()->set("name", new_name);
                        command("recruit " + this_player()->query("id"));
                        if (!present("yu di", this_player())){
                                ob=new("/d/xingxiu/obj/yudi");
                                ob->move(this_player());
                                command("say 这只玉笛是咱们星宿弟子的护身符，你好好拿着，不可弄丢。");
                                write("丁春秋给你一只玉笛。\n");
                        }
                } else {
                        command("say 你如此不把老仙放在眼里，老仙怎会收你？");
                }
                return 1;
        } else if(fam["family_name"]=="星宿派") {
                if(contribution<100){
                        command("say 你这混蛋还有脸来见我？");
                } else if(contribution>100 && contribution<500) {
                        command("say 徒儿干得不错，再接下去为师一定有赏。");
                } else if(contribution>500) {
                        command("say 好徒儿，功夫上有什么不不懂的地方尽管问我。");
                        this_player()->set_temp("canask",1);
                }
                return 1;       
        }

        return 0;

        
        
}

int ask_chname(){
        
        object me=this_player();
        mapping fam;
        string name, new_name;
        int contribution=this_player()->query("xingxiu/contribution");
        int x;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="星宿派"){
                command("say 您不要开玩笑。");
                return 1;
        }
        
        if (contribution<100) {
                command("shake "+me->query("id"));
                command("say 你对老仙贡献不够。");
        } else {
                command("ok");
                name = this_player()->query("name");
                new_name=name;
                
                while(name==new_name) {
                
                x=random(6);
                
                if (x==6)               
                        new_name =  name[0..01] + name[2..3] + "子";
                else if (x==2) 
                        new_name =  name[2..3] + name[0..01] + "子";
                else if (x==1)
                        new_name =  name[0..01]+ "玄" +  "子";
                else if (x==3)
                        new_name =  name[0..01]+ "凡" +  "子";
                else if (x==4)
                        new_name =  name[0..01]+ "缘" +  "子";
                else if (x==5)
                        new_name =  name[0..01]+ "冥" +  "子";
                else 
                        new_name =  name[0..01]+ "尘" +  "子";
                
                }
        
                command("chat 从今以后"+name+"的名字叫做" + new_name + "。");
                
                this_player()->set("oldname", name);
                this_player()->set("name", new_name);   
                this_player()->add("xingxiu/contribution", -50);        
        }

        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
string ask_suo()
{
        mapping fam;
        object ob;
                
        if (!(fam = this_player()->query("family")) || fam["family_name"]!="星宿派")
                return RANK_D->query_respect(this_player()) +
        "与本派素无来往，不知此话从何谈起？";
        if (query("suo_count") < 1)
                return "你来晚了，都被你师兄们拿走了。";
        if (  present("rousi suo", this_player()) )
                return "不是刚给你了吗？怎么又来要了？";
        if ( this_player()->query_skill("feixing-shu", 1) < 120)
                return "这东西你可不能玩。";
        add("suo_count", -1);
        ob = new("/d/xingxiu/obj/rousi-suo");  
        ob->move(this_player());   
        say("丁春秋给你一条柔丝索。\n");
        return "好吧，拿去好好享用。这是为师多年心血所得，你可要珍惜！";
}

string ask_wxs()
{
        mapping fam;
        object ob;
                
        if (!(fam = this_player()->query("family")) ||fam["family_name"]!="星宿派")
                return RANK_D->query_respect(this_player()) +
        "与本派素无来往，不知此话从何谈起？";
        if (query("wxs_count") < 1)
                return "你来晚了，都被你师兄们拿走了。";
        if (  present("wuxing san", this_player()) )
                return "不是刚给你了吗？怎么又来要了？";
        if ( this_player()->query_skill("feixing-shu", 1) < 120)
                return "这东西你可不能玩。";
        add("wxs_count", -1);
        ob = new("/d/xingxiu/obj/wuxing");  
        ob->move(this_player());   
        say("丁春秋给你一包无形散。\n");
        return "好吧，拿去好好享用。这是为师多年心血所得，你可要珍惜！";
}


string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="星宿派")
                return RANK_D->query_respect(this_player()) +
        "与本派素无来往，不知此话从何谈起？";
        if (query("san_count") < 1)
                return "你来晚了，都被你师兄们拿走了。";
        if (  present("sanxiao san", this_player()) )
                return "不是刚给你了吗？怎么又来要了？";
        if (this_player()->query_skill("poison", 1) < 100 ||
        this_player()->query_skill("feixing-shu", 1) < 100 ||
        this_player()->query_skill("huagong-dafa", 1) < 100)
                return "这东西你可不能玩。";
        add("san_count", -1);
        ob = new("/d/xingxiu/obj/sanxiao");
        ob->move(this_player());
        say("丁春秋给你一包逍遥三笑散。\n");
        return "好吧，拿去好好享用。";
}

string ask_zhen()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] !="星宿派")
                return RANK_D->query_respect(this_player()) +
        "与本派素无来往，不知此话从何谈起？";
        if (query("zhen_count") < 1)
                return "你来晚了，都被你师兄们拿走了。";
        if (  present("bilin zhen", this_player()) )
                return "不是刚给你了吗？怎么又来要了？";
        if (this_player()->query_skill("poison", 1) < 50 ||
        this_player()->query_skill("feixing-shu", 1) < 50 ||
        this_player()->query_skill("huagong-dafa", 1) < 50)
                return "这东西你可不能玩。";
        add("zhen_count", -1);
        ob = new("/d/xingxiu/obj/blzhen");
        ob->move(this_player());
        say("丁春秋给你一把碧磷针。\n");
        return "好吧，去替我干掉两个白道的人物。";
}


int ask_job(){
        
        object me=this_player();
        object waguan;
        mapping fam;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="星宿派"){
                command("?");
                return 0;
        }
/*
                
        if (me->query("robot_ding") > me->query("mud_age")) {
                command("say 哼！上次你骗老仙的事，老仙还没有和你算帐呢！你现在还有脸问这问那！");
                command("say 你先给我回去好好反省自己一下，以后再来！");
                return 1;
        }

        if(me->query("robot_answer")) return notify_fail("快给老夫把先前的问题答了！\n");

        if (random(4) == 1 && !me->query("passed_ding")) {
                command("say 昨夜老夫受仙人告戒，说你" + me->name(1) + "做事不老实。用写机器来欺骗老夫");
                command("say 所以老夫现在要问你一问，你听好了！");
                ANTI_ROBOT->get_question(me, this_object());
                return 1;
        }
*/
        if(me->query_temp("xx_job")==1) {
                command("say 好小子，上一个工作没有完成就敢来问我工作。");
                return 1;
        }
        command ("say 「老仙我最近练功需要一些毒丹，你到后山拿些来给我吧。」");
        waguan=new("/d/xingxiu/obj/waguan");
        me->set_temp("xx_job",1);
        if (!present("wa guan", me)) waguan->move(me);
            message_vision("丁春秋顺手从身后架子上取出一个小瓦罐扔给你。\n", me);
                command ("say 「快去快回，路上小心。」");
        return 1;

}


int ask_staff()
{        
        object me=this_player();
        object waguan;
        mapping fam;
        
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="星宿派")
                {
                command("?");
                return 1;
        }
                
        if (me->query("tianshan")==1)
                {
                command("say 不要开这种无聊的玩笑。");
                return 1;
        }
        
        if (me->query_skill("pixie-jian",1)>=10)
                {
                command("hmm");
                command("say 你阴阳失调，不宜修炼此功。");
                return 1;       
        }
                        
        if (me->query_skill("staff", 1) < 250)
                {
                command("say 你基本杖法的修为不够。");
                                return 1;
        }
        
        if (me->query_str() < 50) 
                {
                command("say 你的体能太低了，好好锻炼锻炼在来问我吧。");
                return 1;
        }
        
        if (me->query_con() < 50) 
                {
                command("say 你的内功修为太低了，好好锻炼锻炼在来问我吧。");
                return 1;
        }
                
        if (me->query_int() < 35) 
                {
                command("sneer");
                command("say 我派武学讲究领悟，你悟性太差，回去好好读一下书吧。");
                return 1;
        }

                if (me->query("xingxiu/contribution") < 500)
                {
                                command("hmm");
                                command("say 你对我星宿的贡献度不够高吧，多多努力以后再来问我。");
                                return 1;
                }

                message_vision(HIG"$N微微一笑，将$n拉到一旁，慢慢地解释天上披风杖这一招。\n", this_object(), this_player());
                message_vision(HIG"$n在$N的讲解下，对天山杖法又有了一层新的理解。", this_object(), this_player());
                me->set("tianshan", 1);
                tell_object(this_object(),HIC"你的天山杖法进步了！");
                me->add_skill("tianshan-zhang", 10);

        return 1;

}

// 星宿老仙，德配天地，威震寰宇，古今无比

int accept_object(object who, object ob){

        object me=this_player();
        mapping fam;
        int pot, exp;
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="星宿派"){
                command("?");
                return 0;
        }               

        if(ob->query("id")=="du dan"){

                if (this_player()->query_temp("xx_job")!=1 || ob->query("player")!=me->query("id")) {
                        command("hehe");
                        return 0;
                } else {
                        command("pat "+this_player()->query("id"));        
                        command("say 好样的，老仙我越看你越顺眼了。\n");
                        // exp triple
                        pot = random(80)+80;
                        exp = 220 + random( 20 );
          if(me->query("combat_exp") > 6400000)
          {
              exp = exp / 2;
          }
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
                        if(me->query("potential")>me->query("max_potential"))
                                me->set("potential",me->query("max_potential"));
                        log_file("/job/xx-zhua",sprintf("[%s] %s(%s) 抓虫得到 %d 点经验和 %d 点潜能。\n", ctime(time()), me->name(), me->query("id"), exp, pot));
                        me->add("xingxiu/contribution", 1);
                        me->delete_temp("xx_job");
                        me->delete_temp("found");
                        me->delete_temp("bug_hold");
                        me->delete_temp("bug_out");
                        call_out("destob",1,ob);
                        me->delete("passed_ding");
                        return 1;
                }
        }
        if(ob->query("id")=="a zi"){

                {
                        command("say 太好了，终于有把这个孽徒抓回来了！\n");
                        command("say 来人哪！把这个孽徒给我先关到牢房里面去！\n");
                        tell_object(me,"门外进来两名星宿弟子把阿紫拖出去了。\n");
                        pot = random(1000)+80;
                        exp = 2200 + random( 20 );
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
                        if(me->query("potential")>me->query("max_potential"))
                                me->set("potential",me->query("max_potential"));
                        me->set("ask/ding", 1);
                     call_out("destob",1,ob);
                        return 1;
                }
        }
        if(ob->query("id")=="noname book")
        {
                if(me->query("ask/ding")==1)
                {
                        tell_object(me,"这……这是易筋经残篇！！好
徒儿，咱们星宿一统江湖的日子来了！此书既然由你取得，日后你当然也可
以修习，待为师将其译出并抄录副本。咱们师徒共同研究！\n");
                        me->set("canbook",1);
                        return 1;
                }
                else
                return notify_fail("丁春秋怒道：“我老仙是何等身份？！怎会收你这种垃圾，我不要！”\n");
        }
                        
        if(ob->query("id")=="ling pai"){
                if(ob->query("player")!=me->query("id")){
                        command("hehe");
                        return 0;
// Code of ShenZhou
                } else {
// rama@sz modified
                        command("hehehe");
                        command("say 好样的，让这些自称名门正派的知道老仙的厉害。\n");
                        if (ob->query("menpai")=="huashan" || ob->query("menpai")=="quanzhen")
                                exp = 200 + random( 20 );
                        else  if(ob->query("menpai")=="mingjiao") {
                                command("say 嗯。。明教竟然也跟我干上了。\n");
                                //exp triple
                                exp = 280 + random( 60 );
                        } else  exp = 270+random(50);
          if(me->query("combat_exp") > 6400000)
          {
            exp = exp / 2;
          }
          if(me->query("combat_exp") > 18000000)
          {
            exp = exp / 2;
          }

			me->add("combat_exp", exp);
                        log_file("/job/xx-zhua",sprintf("[%s] %s(%s) 捡令牌得到 %d 点经验。\n", ctime(time()),me->name(), me->query("id"), exp*4/3));                       
                        call_out("destob",1,ob);
                        me->delete("passed_ding");
                        return 1;                                       
                }
        }
        
        
        command("hmm");
        command("say 给我这个干什么？");
        return 0;
        
}       

void destob(object ob){
        destruct(ob);
}
