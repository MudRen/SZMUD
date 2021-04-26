// Code of ShenZhou
// buqun.c ����Ⱥ
// qfy July 4, 1996.
// Modify by Scatter

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#define BUSY_TIME 180
int auto_perform();
int intPaiValue;

string ask_me();
string ask_feng();
string ask_job();
int dest_lingpai(object obj, object ob);
int reward_dest(object obj, object ob);

int do_bonus();
void no_answer(object user);
int do_anwser(string arg);
int do_kill(string arg);

void create() 
{
        set_name("����Ⱥ", ({ "yue buqun", "yue", "buqun" }));
        set("nickname", "���ӽ�");
        set("long", 
"����ǻ�ɽ�������š����ӽ�������Ⱥ�����ڽ���������Զ����\n"
"��������������ġ������������秵��Ƹ��������书ȴ����\n"
"���ɲ⡣\n");
        set("gender", "����");
        set("age", 46);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 29);
        set("int", 35);
        set("con", 26);
        set("dex", 29);
        
        set("max_qi", 1500);
        set("max_jing", 900);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 50);
        set("combat_exp", 950000);
        set("score", 5000);

        set_skill("force", 150);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("sword", 145);
        set_skill("strike", 140);
        set_skill("huashan-jianfa", 145);
        set_skill("hunyuan-zhang",140);
        set_skill("zixia-gong", 150);
        set_skill("huashan-shenfa", 140);
        set_skill("cuff", 140);
        set_skill("pishi-poyu", 140);
        set_skill("ziyin-yin", 110);
        set_skill("zhengqi-jue", 110);
        set_skill("literate", 101);

        map_skill("cuff", "pishi-poyu");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("strike","hunyuan-zhang");
        map_skill("dodge","huashan-shenfa");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "pishi-poyu");

        create_family("��ɽ��", 13, "����");

        set("inquiry", ([
            "����" : (: ask_me :),
            "����" : (: ask_me :),
            "������" : "�����ҷ��ˡ�\n",
            "�����" : "������Ů����\n",
            "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",
            "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",          
            "˼����" : "���Ǳ��ɵ�������˼��֮����\n", 
            "������" : (: ask_feng :),
            "����" : (: ask_job :),
            "job" : (: ask_job :),
        ]));

        set_temp("job_pos", 10);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object ob;

        add_action("do_answer", "answer", 1);

        ::init();

        set_heart_beat(1);
                add_action("do_answer", "answer");
        if ( interactive( ob = this_player() ) || ob->query( "scheme" ) ) {
           if ( ob->query("family/family_name") == "��ɽ��" ) {
//              remove_call_out("check_student");
                call_out("check_student", 1, ob);
           }else if( ob->query("huashan/job_pending") ){
                call_out("check_student", 1, ob);
        }

           if (present("pixie jianpu",ob)) {
                message_vision(
                       HIY "$NͻȻ����һ��$n�Ŀڴ���Ц�������򲻸������ˣ�����ԭ�����������\n"
                       NOR, this_object(), ob );
                kill_ob(ob);
           }
        }
}

int check_student(object ob)
{
        mapping job_stat;
        object me = this_object();
        int expG, potG;
        expG = 180 + random(40);
        potG = 60 + random(40);
        if ( ob->query("shen") < -100 && ob->query("family/master_id") == "yue buqun" ) {
                command("say " + RANK_D->query_rude(ob) + "�������������������Ϊ��");
                command("expell " + ob->query("id"));
                
                return 1;
        }

//        if ( ob->query("huashan/job_pending") && !ob->query_condition("hz_job") ) {
        if ( ob->query("huashan/job_pending") && !ob->query("scheming") ) {
                job_stat = ob->query_temp("hz_job");

		if ( ob->query("family/family_name") != "��ɽ��" ){
	                if ( sizeof(job_stat) < 10 ) {
	                        command("sigh "+ob->query("id"));
	                        message_vision("$N����üͷ��$n˵������ɽ�ܴ���"+RANK_D->query_respect(ob)+"�����ú�Ѳ��һ�¡�\n", me, ob);
	                }
	                else 
	                {
	                        ob->delete("huashan/job_pending");
	                        ob->delete_temp("hz_job");
	                        ob->add("huashan/job_comp", 1);
	                        // increase hs xunshan bonous to around twice as before
	                        //expG = 100+random(50);
	                        ob->add("combat_exp", expG );
	                        ob->add("potential", potG );
	                        if ( ob->query("potential") > ob->query("max_potential") )
	                                ob->set("potential", ob->query("max_potential"));
	                        command("say �ܺã�"+RANK_D->query_respect(ob)+"�����ض���Ϊ���ֵĶ�����");
	                }
	        }else{
			if ( sizeof(job_stat) < 12 ) {
//	                        ob->apply_condition("hz_job", 30);
	                        message_vision("$N����üͷ��$n˵�����ҽ��㵽��ɽ�����ú�Ѳ�ӣ������ƺ���û������ȥ���ɡ�\n", me, ob);
	                        command("say �����ϸ��һ�ȥ�ú�Ѳ�ߣ�");
	                }
	                else 
	                {
	                        ob->delete("huashan/job_pending");
	                        ob->delete_temp("hz_job");
	                        ob->add("huashan/job_comp", 1);
	                        // increase hs xunshan bonous to around twice as before
	                        //expG = 100+random(50);
                               expG = 180 + random(40);
	                        ob->add("combat_exp", expG );
	                        //potG = 50+random(50);
                                potG = 60 + random( 40 );
	                        ob->add("potential", potG );
	                        if ( ob->query("potential") > ob->query("max_potential") )
	                                ob->set("potential", ob->query("max_potential"));
	                //log_file("job/huashan",ob->query("name") +" (" + ob->query("id") + ") Ѳɽ��� " + 
	            //    expG + " �㾭��� "+ potG + " ��ǳ�� "+ctime(time())+"\n");
	
	                        if ( me->query_temp("job_pos") < 10 ) 
	                        {
	                                me->add_temp("job_pos", 1);
	                        }
	
	                        me->set_temp("job_man", ob->query("id") );
	                        remove_call_out("clear_job_man");
	                        //call_out("clear_job_man", 1000, me);
	                        //decrease the job time for huashan xunshan to half
                    call_out("clear_job_man", 1, me);
	                        command("nod");
	                        command("say �ܺã�"+ob->name()+"������һ�죬�ȵ�ƫ������ʦү��ͷ������ȥ��Ϣ�ɡ�");
	                }
	        }
	}
        return 1;
}

int clear_job_man(object me)
{
        if ( objectp(me) ) {
                me->delete_temp("job_man");
        }
        
        return 1;
}

void attempt_apprentice(object ob)
{
        if( ob->query("family/family_name") != "��ɽ��" && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }

        if (ob->query("class")=="bonze") {
                command ("say ��ɽ��һ���ճ�����Ϊͽ������ذɡ�");
                return;
        }

        if ((string)ob->query("gender") == "Ů��") {
                command("say �Ҳ���Ůͽ��" + RANK_D->query_respect(ob) + "���ǵ����ð����ҷ������°ɡ�");
                if ( ob->query("family/family_name") != "��ɽ��" ) {
                        ob->set_temp("marks/bai_ning", 1);
                }
                return;
        }

        if ((string)ob->query("gender") == "����" && (int)ob->query_skill("pixie-jian",1) > 50 ) {
                command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
                return;
        }

        if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                return;
        }

        if ((int)ob->query("huashan/yue") == 1 && (int)ob->query("betrayer") > 10) {
                command("say " + RANK_D->query_respect(ob) + "�Ǹ������ķ���֮�ˣ���������ŵù��㣿");
                return;
        }

        if ((int)ob->query("shen") < 0) {
                command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
                command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
                return;
        }
       
        command("say �ðɣ��Ҿ��������ˡ�ϣ�����ܽ���ɽ�������츣���֡�");
        ob->set("huashan/yue", 1);
        ob->set("betrayer", 0);
        command("recruit " + ob->query("id"));
}

string ask_me()
{
        object me = this_player();
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( !myfam || myfam["family_name"] != "��ɽ��" )
                return "���Ǻ���ԨԴ���������¸��\n";

        say("����Ⱥָ��������Ҷ�����ĳ���˵��������ɽ��������Ϊ�������ڡ���\n");
        say("�����ڷ���Ϊ�����Խ�Ϊ���������˽����޼᲻�ݡ�������������ʩ�ؽ�\n");
        say("���������ڸ��ּ���������ˮ���ݣ�ͬ�Ųٸ꣡��ɽ���ʽ΢���㼴����\n");
        say("�ţ������ܽ����԰�������ɽ���ǵõ����Ҷ���д���ǡ���������������\n");
        say("�������佣·�ݺᣬ�仯�޷�������Ȼ�������ڡ���ϼ�񹦡�֮�£���ʮ��\n");
        say("���������֣�ʵ�첻ʤ��Ҳ����\n");
        return "�мǣ��мǣ�\n";
}

string ask_feng()
{
        say("����Ⱥ����ɫͻȻ��ú��ѿ�������üͷ��\n");
        return "���Ǳ��ŵ�һ��ǰ����һ�򲻹��ʱ���������Ҳ������������䡣\n";
}

void unconcious()
{
        object obj, me = this_object();
        object ob = this_player();

        message_vision("\n$NͻȻ���³������ó�һ���廨�룬����Ʈ��������ȣ�����֮��֮�죬ֱ�Ƿ�����˼��\n", me);
        obj = new(__DIR__"buqun2");
        obj->move(environment(me));
        destruct(me);
}

string ask_job()
{
        mapping job_stat;
        object ob = this_player();
        object me = this_object();
        object *doer;

        job_stat = ob->query_temp("hz_job");
        
		
        if ( ob->query("scheming")) return "���ڽ�ֹ�� Scheme �����ɹ�����\n"; 

        if ( ob->query("huashan/job_pending", 1) && sizeof(job_stat) == 12 )
                return "��û��ϸѲɽ�ɣ���ô���Ѳ���˻�ɽ����������ʵʵ�ػ�ȥѲɽ�ɣ�\n";

        else if ( ob->query("huashan/job_pending", 1) )
                return "�㻹û����ҽ����Ĺ�������ô�������ң�\n";

        if ( ob->query("family/family_name") != "��ɽ��" ){
 		if (ob->query("combat_exp") >= 500000)
	                return "�ף�"+RANK_D->query_respect(ob)+"���һ�ɽ���ӣ�����ͷ���\n";
		if ( time() < ob->query("mp_job_time") + BUSY_TIME ) 
			return "��λ"+RANK_D->query_respect(ob)+"�����ﲻȱ���֣��뵽�����ط�������\n";
	        ob->set("huashan/job_pending", 1);
		ob->set("mp_job_time",time());
                return "�ðɣ�"+RANK_D->query_respect(ob)+"��������ϸѲ�컪ɽ�����������ͷ��ˡ�\n";
	}

	if ( time() < ob->query("mp_job_time") + 180 ) 
		return "������̫�������Ѳɽ���㻹���ȵ�����������������ɡ�\n";

        if ( me->query_temp("job_pos") == 0 ) {
                doer = filter_array(livings(), "is_doing_job", me, ob);
                me->set_temp("job_pos", 10 - sizeof(doer) );
                if ( me->query_temp("job_pos") == 0 ) {
                        command("shake");
                        return "��������ʮ������Ѳɽ���㻹���ȵ�����������������ɡ�\n";
                }
        }

        if ( me->query_temp("job_man") == ob->query("id") ) {
                command("shake");
                return "���Ѳɽ������Ӧ�úú���Ϣ�ˡ����۵Ļ�����������Ҳ�ɡ�\n";
        }
        
        ob->set("huashan/job_pending", 1);
//        ob->apply_condition("hz_job", 15+random(5));
    //log_file("job/huashan",ob->query("name")+" (" + 
    //    ob->query("id") + ") ��ȡѲɽ����  "+ctime(time())+"\n");
	ob->set("mp_job_time",time() );
        command("nod");
        command("say ���������Ͼ��ҷ������㵽��ɽ��ׯ�Ĵ��ú�Ѳ�ߣ�����а�����˻��˽�����");
        return "������ϲ�ƽ֮�£���һ��Ҫ���������������׹�һ�ɽ������һ��С�ģ�\n";
}

private int is_doing_job(object doer)
{
        if ( doer->query("family/family_name") == "��ɽ��" && doer->query_condition("hz_job") > 0 )
                return 1;
        else
                return 0;
}


int accept_object(object me, object obj)
{
        object ob = this_player();

        if ( obj->name() == "��ͭ����" && obj->query("id") == "ling pai" ) {
        if ( ob->query("family/family_name") == "��ɽ��" ){
call_out("reward_dest", 0, obj, ob); 
}else{
remove_call_out("dest_lingpai"); 
call_out("dest_lingpai", 0, obj, ob);
}
return 1;
        return 1;
        }

        command( "hmm" );
        command( "say ������ⶫ����ʲô��" );
           
        return 0;
}

int reward_dest(object obj, object ob)
{
        object me=this_object();
        int rate, exp, cut;
        int expG, potG;
        intPaiValue = obj->query_amount();
        // Modified by Chu:
        // Huashan grows faster when they are young, and slower when they are old
/*        rate = 200;
        exp = ob->query("combat_exp");
        if (exp > 4000000) rate += 10; 
        if (exp > 3000000) rate += 10; 
        if (exp > 1000000) rate += 10; 
        if (exp < 300000) rate -= 10; 
        if (exp < 150000) rate -= 10; 
        if (exp > 3000000) cut = 90 - (exp / 200000);
        else cut = 80;
        if (cut < 50) cut = 50;*/
        message_vision("$N��üͷ���Լ�����˵��������а�ɵ���ͭ����ǵ����к���ͼ��\n", me);
        if ( obj->query_temp("owner") == ob->query("id") && !obj->query("scheming")) {
                command("say "+ob->name()+"�����÷ǳ��ã�����ȥ��Ϣ�ɡ�");
/*                expG = rate*(cut + random(20))*intPaiValue/100;
                ob->add("combat_exp", expG);
                potG = rate*(cut * 3 / 5  + random(20))*intPaiValue/100;
                ob->add("potential", potG );
                if ( ob->query("potential") > ob->query("max_potential") )
                ob->set("potential", ob->query("max_potential"));
                log_file("job/huashan",ob->query("name") +" (" + ob->query("id") + ") ѲɽɱMMR��� " + expG + " �㾭��� "+ potG + " ��ǳ�� "+ctime(time())+"\n");
*/
                expG = 180 + random(40);
                potG = 60 + random(40);
		ob->add("combat_exp", expG);
                ob->add("potential", potG );
                if ( ob->query("potential") > ob->query("max_potential") )
                ob->set("potential", ob->query("max_potential"));
		ob->set("mp_job_time",time() );
                log_file("job/huashan",ob->query("name") +" (" + ob->query("id") + ") ѲɽɱMMR��� " + expG + " �㾭��� "+ potG + " ��ǳ�� "+ctime(time())+"\n");
        }
        else {
                message_vision("$N��$n���ʵ����������ƺ�������ġ�������������ģ�\n", me, ob);
        }

        destruct(obj);

        return 1;
}


int dest_lingpai(object obj, object ob)
{
        object me=this_object();

        message_vision("$N��üͷ���Լ�����˵��������а�ɵ���ͭ����ǵ����к���ͼ��\n", me);
        message_vision("$N��$n����˵��������"+RANK_D->query_respect(ob)+"�ε���������ɽ��������м���\n", me, ob);
        command("say "+RANK_D->query_respect(ob)+"�˾��츣���֣����˽�������Ҳ��");
        
        destruct(obj);

        return 1;
}

int auto_perform()
{
        object me=this_object();
        object weapon=me->query_temp("weapon");
        object opp=me->select_opponent();

        if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 50);

                return 1;
        }

        if ( objectp(weapon) ) {
                if ( weapon->query("skill_type") == "sword" )
                        return perform_action("sword.jianzhang");
        }
        else if ( !me->query_temp("leidong") ) {
                        return perform_action("cuff.leidong");
        }
        else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
                        return perform_action("strike.wuji");
        }
}