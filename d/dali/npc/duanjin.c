// Code of ShenZhou
// /d/dali/npc/duanjin.c  段陉  逮捕工作
// updated by Lara 2001/12/16
// by snowyu 2002/4 升候 quest , 带兵系统 (注解: 此代码沿用xkx chu 北京带兵系统)
inherit NPC;

string ask_me();
string ask_me1();
string ask_suicong();
string ask_yin();
void create()
{
	set_name("段陉", ({ "duan jin", "duan"}));
	set("long", 
"    定安府五大判官之首，官服打扮与中原甚有渊源，唯独颇为洒脱，\n"
"与中原官场人氏之淤昵不清不可相提并论。段陉是定安府总督，本为 \n"
"皇族之远亲，官场上下甚是熟靠，既能秉公于法，又不得罪显贵，是 \n"
"大理国难得的一人材。此公与平南王貌似，方脸大耳，浓眉大眼，双 \n"
"唇薄而紧闭，以相则贵。\n");
	set("gender", "男性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set( "str", 5000 );
	set("int", 16);
	set("con", 22);
	set("dex", 24);

	set("combat_exp", 30000);
	set("dalinpc",1);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	setup();

	set("inquiry", ([
		"升职" :  (: ask_me :),
		"功劳" :  (: ask_me1 :),
		"士兵" : (: ask_suicong :),
		"帅印" : (: ask_yin :),
		]));

	carry_object("/d/dali/obj/zipao")->wear();
}


int accept_object(object who,object ob,object obj)
{
	int a, b, c, d, e, exp, pot;//引入功劳累积制

	if (who->query_temp("marks/arrestee") != ob->query("name")
	|| ob->query_temp("last_damage_from") != who
	|| !who->query("dali/employee")
	|| (who->query("family/family_name") != "大理段家" && who->query("combat_exp")>5000000))
	return 0;
	
          if (who->query("combat_exp") > 800000) exp = 380 + random(40);
          if (who->query("combat_exp") < 800000) exp = 580 + random(40);
          if (who->query("combat_exp") < 300000) exp = 780 + random(40);
          if (who->query("combat_exp") > 800000) pot = 300 + random(40);
          if (who->query("combat_exp") < 800000) pot = 220 + random(40);
          if (who->query("combat_exp") < 300000) pot = 140 + random(40);
        pot = 140 +random(40);
       who->delete_temp("marks/arrestee");

/*	
        a = ob->query("combat_exp");
	b = who->query("combat_exp");
	c = a*100/b;	
        d = who->query("dali/arrestmade");
        e = who->query("dali/trust");
	who->delete_temp("marks/arrestee");

	if (a > b/2){
		if (ob->query("wrong_fainted") || !ob->query("dalibandit")) {
			//exp = (c+random(c/2))/2;
			exp = 100+random(60);
			//pot = c/6;
			pot = 10+random(30);
		}
		else {
                     if (e>1000) e=1000;
                      exp = 350+random(100);
                      //exp = c*2/3+random(c/6)+random(d/90)+e/30;
                      pot = 160+random(80);
                      //pot = c*2/9+random(d/150)+e/22;
                      
		}
*/		
		
		who->add("combat_exp", exp);
		who->add("potential", pot);
		who->set("mp_job_time",time() );
		log_file("/job/dl-zhian",sprintf("[%s] %s(%s) 做治安工作得到 %d 点经验和 %d 点潜能。\n", ctime(time()),	who->name(), getuid(who), exp, pot)); //add log file. 
		if (who->query("potential") > who->query("max_potential"))
			who->set("potential",who->query("max_potential"));
	

	if (ob->query("combat_exp") > (who->query("combat_exp")*23/10)) {
		command("courage "+who->query("id"));
		who->add("dali/trust",1);
	}
	else command("thumb "+who->query("id"));
	who->add("dali/arrestmade", 1);
	who->delete_temp("dalijobon");
	if (userp(ob)) {
		if (ob->query("combat_exp")>2500) {
			ob->add("combat_exp",-2000);
			who->add("combat_exp",1500);
		       	log_file("/job/dl-zhian",sprintf("[%s] %s(%s) 抓捕玩家得到 1500 点经验。\n", ctime(time()), who->name(), getuid(who))); //add log file. 
		       	log_file("/job/dl-zhian",sprintf("[%s] %s(%s) 被抓失去 2000 点经验。\n", ctime(time()), ob->name(), getuid(ob))); //add log file. 
		}
		ob->move("/d/dali/laoyu");
	}
	else
	{
		this_object()->save();
		call_out( "destroy", 1, ob );
	}
    return 1;
        }

int destroy( object ob )
{
	destruct(ob);
	this_object()->save();
	return 1;
}

void jail(object ob)
{
	ob->move("/d/dali/laoyu");
	return;
}

void init()
{
	object ob,me=this_object();

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="大理段家"
		&& ob->query("dali/trust")<0) {
		message_vision("$N严肃地警告$n：“"+RANK_D->query_respect(me)+"投我大理为差，却怎么行为不轨、恶迹累累？皇上就要把你开除了！”\n",me,ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="大理段家"
		&& (ob->query("dali/trust")<=-100
		|| ob->query("family/family_name")=="丐帮"
		|| ob->query("family/family_name")=="星宿派"
		|| ob->query("family/family_name")=="雪山派"
		|| ob->query("family/family_name")=="血刀门"
		|| ob->query("family/family_name")=="白驼山"
		|| ob->query("sg/spy")
		|| (ob->query("class") && ob->query("class")!="officer")
		|| (ob->query("PKS")>20	&& ob->query("combat_exp")/ob->query("PKS") < 10000))) {
		command("sneer "+ob->query("id"));
		message_vision("$N对$n冷笑着道：“"+RANK_D->query_rude(me)+"来此为差却心怀不轨，视国法为无物。大理岂是你这种小人逍遥的地方！”\n",me,ob);
		message_vision("$N掏出一卷公文对$n大声宣读：“现秉承皇命，革去"+ob->query("name")+"大理差人之职，永不复录用！”\n",me,ob);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
		ob->set("dali/trust",-100);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="大理段家"
		&& (ob->query("shen")>(ob->query("combat_exp")/2)
		|| ob->query("shen")<(-ob->query("combat_exp")/2)
		|| ob->query("family/family_name")=="全真教"
		|| ob->query("family/family_name")=="桃花岛")) {
		command("sigh "+ob->query("id"));
		message_vision("$N轻轻地拍了拍$n肩膀，说道：“"+RANK_D->query_respect(me)+"近来在江湖上名声大长，在大理屈尊为差实在太委屈你了。”\n",me,ob);
		message_vision("$N掏出一卷公文对$n大声宣读：“现秉承皇命，革去"+ob->query("name")+"大理差人之职，永不复录用！”\n",me,ob);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
		ob->set("dali/trust",0);
	}
}

int accept_fight(object me)
{
	command("say 在下公务繁忙，没空陪你玩。");
	return notify_fail("看来他不想和你交手。\n");
}

int accept_kill(object me)
{
	if (me->query("dali/employee"))
		command("say 你我同府共事，何故加害与我？！我跟你拼了！\n");
	else command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("dlkiller", 100);
	me->add("dali/trust",-1);
	return 1;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::die();
}

string ask_me()
{
	object ob, who=this_player();

	if (!who->query("dali/employee"))
		return RANK_D->query_respect(who)+"和我大理素无瓜葛，何有此问啊？";

	if (who->query("dali/rank")<=1)
		return RANK_D->query_respect(who)+"级别还不够，没有官职给你作，你还是老老实实当差吧。";

	if (who->query("dali/rank")>=2) {
		if (who->query("dali/arrestmade")>=500 && who->query("dali/duty")<1) {
			who->set("dali/duty",1);
			who->set("title","大理国下府副将");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作下府副将。";
		}
		if (who->query("dali/arrestmade")>=1000 && who->query("dali/duty")<2) {
			who->set("dali/duty",2);
			who->set("title","大理国下府主将");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作下府主将。";
		}
	}

	if (who->query("dali/rank")>=3) {
		if (who->query("dali/arrestmade")>=2000 && who->query("dali/duty")<3) {
			who->set("dali/duty",3);
			who->set("title","大理国中府副将");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作中府副将。";
		}
		if (who->query("dali/arrestmade")>=4000 && who->query("dali/duty")<4) {
			who->set("dali/duty",4);
			who->set("title","大理国中府主将");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作中府主将。";
		}
		if (who->query("dali/arrestmade")>=6000 && who->query("dali/duty")<5) {
			who->set("dali/duty",5);
			who->set("title","大理国上府副将");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作上府副将。";
		}
	
                if (who->query("dali/arrestmade") >= 10000 && who->query("dali/duty") == 5 && 
                    who->query("dali/rank") == 3 && who->query("dali/jobdone") >= 6000 && 
                    ! who->query("dali/findduan") && ! who->query_temp("dali/uprank"))
                {
                        who->set_temp("dali/uprank", 1);
                        who->set_temp("dali/trust", who->query("dali/trust"));
                        who->set_temp("dali/arrestmade", who->query("dali/arrestmade"));
                        who->set_temp("dali/jobdone", who->query("dali/jobdone"));
                        who->set_temp("allowtime", NATURE_D->game_time());
                        command("congra");
                        ob = new("/u/snowyu/work-letter1");
                        ob->move(this_object());
                        ob->set("applicant", who->query("id"));
                        ob->move(who);
                        message_vision("$N给$n一本功绩表。\n", this_object(), who);
                        return RANK_D->query_respect(who) + "近来勤勉出力、功绩显赫，请将此表呈于圣上，相信必有升赏。";
                }
        }

	if (who->query("dali/rank")>=4) {
		if (who->query("dali/arrestmade")>=8000 && who->query("dali/duty")<6) {
			who->set("dali/duty",6);
			who->set("title","大理国上府主将");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作上府主将。";
		}
		if (who->query("dali/arrestmade")>=10000 && who->query("dali/duty")<7) {
			who->set("dali/duty",7);
			ob = new("/d/dali/obj/shuaiyin.c");
            ob->move(this_object());
            ob->move(who);
            message_vision("$N给$n一只大理国兵马帅印。\n", this_object(), who);
			who->set("title","大理国御林军都督");
			command("congra");
			return RANK_D->query_respect(who)+"近来勤勉出力、功绩显赫，现秉承皇命，升你作御林军都督。";
		}
	}

	if (who->query("dali/rank")==5) {
		if (who->query("dali/arrestmade")>=15000 && who->query("dali/duty")<8) {
			who->set("dali/duty",8);
			who->set("title","大理国兵马总管");
			command("congra");
			return RANK_D->query_respect(who)+"为国尽心尽力、军功赫赫，承皇上旨意，封您为兵马总管。";
		}
		else return RANK_D->query_respect(who)+"的官已经高得不能再升了。";
	}

	return RANK_D->query_respect(who)+"还没有积下足够的功劳，不够资格升职。";
}

string ask_me1()
{
	object who=this_player();

	if (!who->query("dali/employee"))
		return RANK_D->query_respect(who)+"和我大理素无瓜葛，何有此问啊？";

	return RANK_D->query_respect(who)+"在我大理工作之中，已经积累功劳点"+chinese_number(who->query("dali/trust"))+"。";
}
string ask_suicong()
{
	 object ob;
	 object player = this_player();
     object me = this_object(), suicong;

     int suicong_num = player->query("suicong_num");

	 if (!player->query("dali/employee"))
		return RANK_D->query_respect(player)+"和我大理素无瓜葛，何有此问啊？";

	 if (player->query("suicong_num")>= 2)
	    return RANK_D->query_respect(player)+"已经有两名士兵了!";
	 
	 if (player->query("dali/rank")<=3)
		return RANK_D->query_respect(player)+"官职还不够啊,需要多努力!";
	 
	 if (player->query("dali/rank")>=4)
     command("ok "+player->query("id"));
	 message_vision("$N拍了拍$n的肩膀，笑道，好好，没问题，来人啊。\n", me, player);
     suicong_num ++;
     player->set("suicong_num", suicong_num);
     suicong = new("/d/dali/npc/suicong.c");
     suicong->new_master(player, suicong_num);
     suicong->move(environment(player));
     suicong->set_leader(player);
     player->save();
     message_vision("$N快步走了过来，向$n行礼道：候爷金安。\n",suicong, player);
	 return RANK_D->query_respect(player)+"为国尽心尽力、军功赫赫, 现分派御林军给你。";
   }
string ask_yin()
{
	 object ob;
	 object player = this_player();
	 
	 int suicong_num = player->query("suicong_num");

	 if (!player->query("dali/employee"))
		return RANK_D->query_respect(player)+"和我大理素无瓜葛，何有此问啊？";

	 if (!player->query("suicong_num"))
	    return RANK_D->query_respect(player)+"没有士兵要帅印做什么？";
	 
	 if (player->query("dali/rank")<=3)
		return RANK_D->query_respect(player)+"官职还不够!";
	 
	 if ( present("shuaiyin", this_player()) )
		return RANK_D->query_respect(this_player()) + "已经有帅印了，为何还要！";

	 if (player->query("dali/rank")>=4)
	 command("ok "+player->query("id"));
	 ob = new("/d/dali/obj/shuaiyin.c");
     ob->move(this_object());
     ob->move(player);
     message_vision("$N给$n一只大理国兵马帅印。\n", this_object(), player);
	   return RANK_D->query_respect(player)+"小心别在把这么贵重的东西丢了! ";
}
