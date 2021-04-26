//fix by Cheap
//10-30-01
// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_job();
int auto_perform();
void assign_job(object ob);

void create()
{
        set_name("³�н�", ({"lu youjiao", "lu", "youjiao"}));
        set("title", "ؤ��Ŵ�����");
        set("nickname", "�ư���ͷ");
        set("gender", "����");
        set("age", 45);
        set("long", 
                "³�н���Ȼ�书�㲻�ö�����֣������ڽ�����ȴ����������\n"
                "��Ϊ����ؤ�����������壬���¹������䣬��ú��߹������ء�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 12);
        set("con", 25);
        set("dex", 20);

        set("rank", 9);

        set("qi", 1200);
        set("max_qi", 1200);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 150);
        
        set("combat_exp", 750000);
        set("score", 20000);
        
        set_skill("force", 140); // �����ڹ�
        set_skill("huntian-qigong", 140); // ��������
        set_skill("strike", 150); // ����ȭ��
        set_skill("xianglong-zhang", 150); // ����ʮ����
        set_skill("dodge", 130); // ��������
        set_skill("xiaoyaoyou", 130); // ��ң��
        set_skill("parry", 150); // �����м�
        set_skill("stick", 150); // ��������
        set_skill("dagou-bang", 150);
        set_skill("begging", 130);
        set_skill("training", 100);
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("stick", "dagou-bang");
        map_skill("dodge", "xiaoyaoyou");
        
        prepare_skill("strike", "xianglong-zhang");

        create_family("ؤ��", 18, "�Ŵ�����");

        set("inquiry", ([
                "����ͼ��" : (: ask_me :),
                "ͼ��" : (: ask_me :),
                "�ܼ�" : (: ask_me :),
                "����" : (: ask_me :),
                "����" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        set("book_count", 1);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

        setup();

        carry_object("/d/gaibang/obj/budai")->set_amount(8);
        carry_object("/d/gaibang/obj/budai")->wear();
        carry_object("/clone/weapon/zhubang")->wield();
}

void init()
{
        object ob;

        ::init();

        set_heart_beat(1);

        if ( interactive( ob = this_player() )
        && ob->query("family/family_name") == "ؤ��" 
        && ob->query("gb/job_pending") ) {
                remove_call_out("check_job");
                call_out("check_job", 1, ob);
        }
}

void attempt_apprentice(object ob)
{
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="Ů��")
                        command ("say ʦ̫���ǳ����ˣ���ô���ڱ������л����أ�");
                return;
        }

        if ( (int)ob->query("int") >= 25 ) {
                command("say ����ؤ�������һ���Ը���Ϊ����" + 
                RANK_D->query_respect(ob) + "�ϻ۹��ˣ��ƺ�����ѧؤ��Ĺ���");
                return;
        }

        if( ob->query("family/family_name") != "ؤ��" )
        {
                if( ob->query("rank") > 1 ) {
                        command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
                        return;
                }
        
                command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
                "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
                ob->set("rank", 1); 
                command("recruit " + ob->query("id"));
                ob->set("title", "ؤ��һ������");
        } 
        else
        {
                ob->set_temp("title", ob->query("title"));
                command("recruit " + ob->query("id"));
                ob->set("title", ob->query_temp("title"));
                ob->delete_temp("title");
        }
}

string ask_me()
{
        mapping fam; 
        object ob, me=this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "ؤ��")
                return RANK_D->query_respect(this_player())+"�뱾�����ԨԴ����ô�ܿ�������Ҫ����ͼ�⣿";

       if ((fam = this_player()->query("family")) || fam["family_name"] = "ؤ��")
                return RANK_D->query_respect(this_player())+"����ȥ�����о�";
         
}

int accept_object(object me, object obj)
{

        object ob = this_player();

        if ( (obj->name() == "ţƤ�ƴ�" || obj->name() == "����ƴ�")
        && obj->query("liquid/type") == "alcohol" ) {
                call_out("drink_jiudai", 1, this_object(), ob, obj);
                return 1;
        }

        command( "say �ⶫ���Ͻл��Ҳ�����Ȥ���������Ը������Űɡ�" );
        return 0;
}

int drink_jiudai(object me, object ob, object obj)
{
        if ( obj->query("liquid/remaining") >= 5 ) {
                message_vision("³�н�����ƴ�һ��ͷ���������ƹ�ཹ�ཱུ�һ��������\n", me);
                command( "taste" );
                if ( ob->query("family/family_name") == "ؤ��" ) {
                        command( "nod" );
                        command( "say �ã���ʲô�������ʰɡ�" );
                        ob->set_temp("lu", 1);
                }
                else {
                        command( "say ��л��λ"+RANK_D->query_respect(ob)+"������治����\n" );
                        command( "smile" );
                }
        }
        else if ( obj->query("liquid/remaining") == 0 ) {
                message_vision("³�нŴ�ŭ˵�����㵱����ɵ�İ����ø��վƴ�����ǲ���ӣ�\n", me);
                if ( ob->query("family/family_name") == "ؤ��" ) {
                        command( "slap " + obj->query("id") );
                        ob->set_temp("lu", 2);
                }
        }
        else {
                command( "say �ٺ٣�����ô��ƾ�����ָ���㣿̫���˰ɣ�");
        }

        remove_call_out("destroy_it");
        call_out("destroy_it", 1, obj);
        return 1;
}
        
void destroy_it(object obj)
{
        destruct(obj);
}

private int is_suitable(object target, object worker)
{
        string *no_assign_list = ({
                "mu ren",
                "mengzhu",
                "white gargoyle",
                "black gargoyle",
                "shangshan shizhe",
                "fae shizhe",
                "xuantong dashi",
                "feng qingyang",
                "daoguo chanshi",
                "huang zhen",
                "juexin dashi",
                "yideng dashi",
                "wei shi",
                "wu jiang",
                "guan bing",
                "ya yi",
                "dongfang bubai",
                "ren woxing"
        });
        if( !clonep(target) || userp(target) || target->query("race") != "����" 
        || target->query("combat_exp") < 15000 
        || strsrch(base_name(target), "/kungfu/class/gaibang/") == 0 
        || strsrch(base_name(target), "/u/") == 0 
        || member_array(target->query("id"), no_assign_list) != -1 ) {
                return 0;
        }
        if( strsrch(base_name(target), "/d/xiakedao") == 0 ) 
                return 0;
                
        if(target->query("name") == "����")
                return 0;
                
        if(base_name(target) =="/d/city/npc/ftb_killer.c")
                return 0;
        return 1;
}

void assign_job(object ob)
{
        object obj, *target_list;
        int i;
        string str, clan, place;

        target_list = filter_array(livings(), "is_suitable", this_object(), ob);

        if( sizeof(target_list) == 0 ) {
        // try again in 5 secs.
                call_out("assign_job", 5, ob);
                return;
        }

        i = random(sizeof(target_list));

                if(target_list[i]->query_temp("pkid"))
                {
                        assign_job(ob);
                        return;
                }

        if ( !clan=target_list[i]->query("family/family_name") ) clan = "";

        
        message_vision("³�н������뻳ȡ��һ���ż㡣\n", ob);
        message_vision("³�нŶ�$N˵�����������ܺ�����"+clan+target_list[i]->name()+"����������͵���\n", ob);
        obj=new("/d/gaibang/obj/mihan");
        if (clan=target_list[i]->query("family/family_name") ) clan = "��"+clan+"��";
        else clan = "";
        obj->set("long", "�ܺ�����д�ţ�"+clan+""+target_list[i]->name()+RANK_D->query_respect(target_list[i])+"������\n");
        obj->set("target_id", target_list[i]->query("id"));
        obj->set("target_name", target_list[i]->name());
        obj->set("owner", ob->query("id"));
        obj->move(ob);
        //log_file("job/gaibang",ob->query("name")+" (" + 
        //    ob->query("id") + ") ��ȡ�ܺ�����  "+ctime(time())+"\n");
        
}


string ask_job()
{
        object ob = this_player();
        object me = this_object();

        if ( ob->query("gb/job_status") == 2 ) {
                remove_call_out("check_job");
                call_out("check_job", 1, ob);
                return "�ޣ����������������\n";
        }
        else if ( ob->query("gb/job_pending") && ob->query_condition("gb_job") > 0 )
                return "�㻹û����ҽ����Ĺ����������������ң�\n";
        else if ( ob->query("gb/job_pending") && !ob->query_condition("gb_job") ) {
                remove_call_out("check_job");
                call_out("check_job", 1, ob);
                return "�ޣ����������\n";
        }
        else if ( ob->query_condition("gb_job") > 0 ) 
                return "������ûҪ������ȥ�ɣ�������������ɡ�\n";

        if ( ob->query("family/family_name") != "ؤ��" )
                return RANK_D->query_respect(ob)+"����ؤ���ֵܣ����������ͷ���\n";

        command("nod");
//      remove_call_out("assign_job");
        call_out("assign_job", 1, ob);
        ob->set("gb/job_pending", 1);
        ob->apply_condition("gb_job", 3+random(3));
        ob->set("gb/job_status", 1);
        return "���������ɣ����м���Ҫ��ȥ�죡\n";
}

int check_job(object ob)
{
        object me=this_object();
        int expG, potG;
        if ( ob->query("gb/job_status") == 2 ) {
                ob->delete("gb/job_pending");
                ob->delete("gb/job_status");
                ob->add("gb/job_comp", 1);
                expG = 250+random(100);
                if ( ob->query("combat_exp")>3600000 ) expG = expG*2/3;
                if ( ob->query("combat_exp")>6400000 ) expG = expG/2;  
                ob->add("combat_exp", expG );
                potG = 50+random(100);
                ob->add("potential", potG );
                log_file("job/gaibang",ob->query("name") +" (" + ob->query("id") + ") ؤ�����Ż�� " + 
                    expG + " �㾭��� "+ potG + " ��ǳ�� "+ctime(time())+"\n");

                if ( (string)ob->query("gb/job_kill") ) {
                        message_vision("³�нŶ�$N�����������������ϴ����㽫"+ob->query("gb/job_kill")+"���������ȥ��ʵ����̫���ˣ�\n", ob);
                        expG = 300+random(100);
                        ob->add("combat_exp", expG );
                        potG = 50+random(50);
                        ob->add("potential", potG );
                        ob->delete("gb/job_kill");
                        log_file("job/gaibang",ob->query("name") +" (" + ob->query("id") + ") ؤ������ɱ�˻�� " + 
                            expG + " �㾭��� "+ potG + " ��ǳ�� "+ctime(time())+"\n");
                        
                }

                if ( ob->query("potential") > ob->query("max_potential") )
                        ob->set("potential", ob->query("max_potential"));

                command("nod");
                message_vision("³�нŶ�$N�����ܺã��������������ȥ��Ϣ�ɡ�\n", ob);
        }
        else if ( ob->query("gb/job_status") == 1 && !ob->query_condition("gb_job") 
        && present("mihan", ob) ) {
                ob->apply_condition("gb_job", 3);
                message_vision("³�н����ö�$N����㻹��������͵������������Ұ��ܺ���ȥ��\n", ob);
        }
        else if ( ob->query("gb/job_pending") && !ob->query_condition("gb_job") ) {
                ob->apply_condition("gb_job", 3);
                ob->set("gb/job_fail", 1);
                ob->delete("gb/job_pending");
                ob->delete("gb/job_status");
                message_vision("³�н����ö�$N�������û�õļһ������ܺ���Ū���ˣ�����ҹ�����\n", ob);
        }

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

        if ( !me->query_temp("powerup") ) {
                return exert_function("powerup");
        }

        if ( objectp(weapon) ) {
                if ( !me->query_temp("shengang") )
                        return exert_function("shengang");

                if ( weapon->query("skill_type") == "stick" )
                        return perform_action("stick.chan");
        }
        else {
                        return perform_action("strike.leiting");
        }
}
