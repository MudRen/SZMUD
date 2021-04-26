// Code of ShenZhou
// /d/dali/npc/duanjin.c  ����  ��������
// updated by Lara 2001/12/16
// by snowyu 2002/4 ���� quest , ����ϵͳ (ע��: �˴�������xkx chu ��������ϵͳ)
inherit NPC;

string ask_me();
string ask_me1();
string ask_suicong();
string ask_yin();
void create()
{
	set_name("����", ({ "duan jin", "duan"}));
	set("long", 
"    ����������й�֮�ף��ٷ��������ԭ����ԨԴ��Ψ����Ϊ���ѣ�\n"
"����ԭ�ٳ�����֮���ǲ��岻�����Ტ�ۡ������Ƕ������ܶ�����Ϊ \n"
"����֮Զ�ף��ٳ����������쿿�����ܱ����ڷ����ֲ������Թ��� \n"
"������ѵõ�һ�˲ġ��˹���ƽ����ò�ƣ����������Ũü���ۣ�˫ \n"
"���������գ��������\n");
	set("gender", "����");
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
		"��ְ" :  (: ask_me :),
		"����" :  (: ask_me1 :),
		"ʿ��" : (: ask_suicong :),
		"˧ӡ" : (: ask_yin :),
		]));

	carry_object("/d/dali/obj/zipao")->wear();
}


int accept_object(object who,object ob,object obj)
{
	int a, b, c, d, e, exp, pot;//���빦���ۻ���

	if (who->query_temp("marks/arrestee") != ob->query("name")
	|| ob->query_temp("last_damage_from") != who
	|| !who->query("dali/employee")
	|| (who->query("family/family_name") != "����μ�" && who->query("combat_exp")>5000000))
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
		log_file("/job/dl-zhian",sprintf("[%s] %s(%s) ���ΰ������õ� %d �㾭��� %d ��Ǳ�ܡ�\n", ctime(time()),	who->name(), getuid(who), exp, pot)); //add log file. 
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
		       	log_file("/job/dl-zhian",sprintf("[%s] %s(%s) ץ����ҵõ� 1500 �㾭�顣\n", ctime(time()), who->name(), getuid(who))); //add log file. 
		       	log_file("/job/dl-zhian",sprintf("[%s] %s(%s) ��ץʧȥ 2000 �㾭�顣\n", ctime(time()), ob->name(), getuid(ob))); //add log file. 
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
		&& ob->query("family/family_name")!="����μ�"
		&& ob->query("dali/trust")<0) {
		message_vision("$N����ؾ���$n����"+RANK_D->query_respect(me)+"Ͷ�Ҵ���Ϊ�ȴ��ô��Ϊ���졢�����ۣ����Ͼ�Ҫ���㿪���ˣ���\n",me,ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& (ob->query("dali/trust")<=-100
		|| ob->query("family/family_name")=="ؤ��"
		|| ob->query("family/family_name")=="������"
		|| ob->query("family/family_name")=="ѩɽ��"
		|| ob->query("family/family_name")=="Ѫ����"
		|| ob->query("family/family_name")=="����ɽ"
		|| ob->query("sg/spy")
		|| (ob->query("class") && ob->query("class")!="officer")
		|| (ob->query("PKS")>20	&& ob->query("combat_exp")/ob->query("PKS") < 10000))) {
		command("sneer "+ob->query("id"));
		message_vision("$N��$n��Ц�ŵ�����"+RANK_D->query_rude(me)+"����Ϊ��ȴ�Ļ����죬�ӹ���Ϊ�����������������С����ң�ĵط�����\n",me,ob);
		message_vision("$N�ͳ�һ���Ķ�$n�������������ֱ��л�������ȥ"+ob->query("name")+"�������ְ֮��������¼�ã���\n",me,ob);
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
		&& ob->query("family/family_name")!="����μ�"
		&& (ob->query("shen")>(ob->query("combat_exp")/2)
		|| ob->query("shen")<(-ob->query("combat_exp")/2)
		|| ob->query("family/family_name")=="ȫ���"
		|| ob->query("family/family_name")=="�һ���")) {
		command("sigh "+ob->query("id"));
		message_vision("$N�����������$n���˵������"+RANK_D->query_respect(me)+"�����ڽ����������󳤣��ڴ�������Ϊ��ʵ��̫ί�����ˡ���\n",me,ob);
		message_vision("$N�ͳ�һ���Ķ�$n�������������ֱ��л�������ȥ"+ob->query("name")+"�������ְ֮��������¼�ã���\n",me,ob);
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
	command("say ���¹���æ��û�������档");
	return notify_fail("������������㽻�֡�\n");
}

int accept_kill(object me)
{
	if (me->query("dali/employee"))
		command("say ����ͬ�����£��ιʼӺ����ң����Ҹ���ƴ�ˣ�\n");
	else command("say ��ү����������ɱ�ţ��������㵹ù��\n");
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
		return RANK_D->query_respect(who)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	if (who->query("dali/rank")<=1)
		return RANK_D->query_respect(who)+"���𻹲�����û�й�ְ���������㻹������ʵʵ����ɡ�";

	if (who->query("dali/rank")>=2) {
		if (who->query("dali/arrestmade")>=500 && who->query("dali/duty")<1) {
			who->set("dali/duty",1);
			who->set("title","������¸�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������¸�������";
		}
		if (who->query("dali/arrestmade")>=1000 && who->query("dali/duty")<2) {
			who->set("dali/duty",2);
			who->set("title","������¸�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������¸�������";
		}
	}

	if (who->query("dali/rank")>=3) {
		if (who->query("dali/arrestmade")>=2000 && who->query("dali/duty")<3) {
			who->set("dali/duty",3);
			who->set("title","������и�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������и�������";
		}
		if (who->query("dali/arrestmade")>=4000 && who->query("dali/duty")<4) {
			who->set("dali/duty",4);
			who->set("title","������и�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������и�������";
		}
		if (who->query("dali/arrestmade")>=6000 && who->query("dali/duty")<5) {
			who->set("dali/duty",5);
			who->set("title","������ϸ�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������ϸ�������";
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
                        message_vision("$N��$nһ��������\n", this_object(), who);
                        return RANK_D->query_respect(who) + "������������������Ժգ��뽫�˱����ʥ�ϣ����ű������͡�";
                }
        }

	if (who->query("dali/rank")>=4) {
		if (who->query("dali/arrestmade")>=8000 && who->query("dali/duty")<6) {
			who->set("dali/duty",6);
			who->set("title","������ϸ�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������ϸ�������";
		}
		if (who->query("dali/arrestmade")>=10000 && who->query("dali/duty")<7) {
			who->set("dali/duty",7);
			ob = new("/d/dali/obj/shuaiyin.c");
            ob->move(this_object());
            ob->move(who);
            message_vision("$N��$nһֻ���������˧ӡ��\n", this_object(), who);
			who->set("title","��������־�����");
			command("congra");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л��������������־�������";
		}
	}

	if (who->query("dali/rank")==5) {
		if (who->query("dali/arrestmade")>=15000 && who->query("dali/duty")<8) {
			who->set("dali/duty",8);
			who->set("title","����������ܹ�");
			command("congra");
			return RANK_D->query_respect(who)+"Ϊ�����ľ����������պգ��л���ּ�⣬����Ϊ�����ܹܡ�";
		}
		else return RANK_D->query_respect(who)+"�Ĺ��Ѿ��ߵò��������ˡ�";
	}

	return RANK_D->query_respect(who)+"��û�л����㹻�Ĺ��ͣ������ʸ���ְ��";
}

string ask_me1()
{
	object who=this_player();

	if (!who->query("dali/employee"))
		return RANK_D->query_respect(who)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	return RANK_D->query_respect(who)+"���Ҵ�����֮�У��Ѿ����۹��͵�"+chinese_number(who->query("dali/trust"))+"��";
}
string ask_suicong()
{
	 object ob;
	 object player = this_player();
     object me = this_object(), suicong;

     int suicong_num = player->query("suicong_num");

	 if (!player->query("dali/employee"))
		return RANK_D->query_respect(player)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	 if (player->query("suicong_num")>= 2)
	    return RANK_D->query_respect(player)+"�Ѿ�������ʿ����!";
	 
	 if (player->query("dali/rank")<=3)
		return RANK_D->query_respect(player)+"��ְ��������,��Ҫ��Ŭ��!";
	 
	 if (player->query("dali/rank")>=4)
     command("ok "+player->query("id"));
	 message_vision("$N������$n�ļ��Ц�����úã�û���⣬���˰���\n", me, player);
     suicong_num ++;
     player->set("suicong_num", suicong_num);
     suicong = new("/d/dali/npc/suicong.c");
     suicong->new_master(player, suicong_num);
     suicong->move(environment(player));
     suicong->set_leader(player);
     player->save();
     message_vision("$N�첽���˹�������$n���������ү�𰲡�\n",suicong, player);
	 return RANK_D->query_respect(player)+"Ϊ�����ľ����������պ�, �ַ������־����㡣";
   }
string ask_yin()
{
	 object ob;
	 object player = this_player();
	 
	 int suicong_num = player->query("suicong_num");

	 if (!player->query("dali/employee"))
		return RANK_D->query_respect(player)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	 if (!player->query("suicong_num"))
	    return RANK_D->query_respect(player)+"û��ʿ��Ҫ˧ӡ��ʲô��";
	 
	 if (player->query("dali/rank")<=3)
		return RANK_D->query_respect(player)+"��ְ������!";
	 
	 if ( present("shuaiyin", this_player()) )
		return RANK_D->query_respect(this_player()) + "�Ѿ���˧ӡ�ˣ�Ϊ�λ�Ҫ��";

	 if (player->query("dali/rank")>=4)
	 command("ok "+player->query("id"));
	 ob = new("/d/dali/obj/shuaiyin.c");
     ob->move(this_object());
     ob->move(player);
     message_vision("$N��$nһֻ���������˧ӡ��\n", this_object(), player);
	   return RANK_D->query_respect(player)+"С�ı��ڰ���ô���صĶ�������! ";
}
