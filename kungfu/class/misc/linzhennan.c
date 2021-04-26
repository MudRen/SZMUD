// MODIFY BY SCATTER
// V. 1.1
// by snowy 2002/1  ����ʦ������(Buwu)��+shen biaoju job �� 400 + random(100) exp

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

string *Robber_Name = ({
        "����","ɽ����","·��","ɽ��","ë��","կ��","���"
        });
string *Biaohuo_Name = ({
        "����","���","����","��ʯ","����","����","����"
        });

int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();
//string ask_biao();
string ask_job();
string ask_jiebiao();
string ask_abandon();
void assign_biaotou(object me, object partner);
void setup_skill(object me,object obj);
int do_jobwith(string arg);
private int is_suitable(object victim, object killer);
private int is_suitable_rob(object victim, object killer);
string QueryDest(object obj);
int assign_rob(object me);
void award2(object dest,object owner);
void award(object me, object ob, object obj);

void create()
{
        set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "����");
        set("age", 45);
        set("long", "�����ǡ������ھ֡�������ͷ���������ϡ�\n");

        set("combat_exp", 500000);
        set("shen_type", 1);
        set("max_neili", 3000);
        set("neili", 3000);
        set("jiali", 100);
        set_skill("force", 140);
        set_skill("sword", 140);
        set_skill("unarmed", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("san-sword", 140);
        map_skill("sword", "san-sword");
        map_skill("parry", "san-sword");
        set("inquiry", ([
                "������լ" : "������˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
                "�����ھ�" : (: ask_fuwei :),
                "Զͼ��" : (: ask_yuantu :),
                "��Զͼ" : "�����ϴ�ŭ��С������ôû��ò��ֱ���������䣡\n",
                "��а����" : (: ask_pixie:),
                "ͭǮ" : (: ask_tong:),
                "ͭ��" : (: ask_tong:),
//              "����" : (: ask_biao:),
//              "����" : (: ask_biao:),
                "����" : (: ask_job:),
                "job" : (: ask_job:),
//                "jiebiao" : (: ask_jiebiao:),
//                "����" : (: ask_jiebiao:),
                "abandon" : (: ask_abandon:),
                "����" : (: ask_abandon:),
                ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);

        add_action("do_jobwith", "jobwith");

        if( interactive(ob = this_player()) && !is_fighting())
        {
                //remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        int bonus,addexp,old_pot;
        string *skname;
        mapping skills;
        int i;

        if( !ob || environment(ob) != environment() ) return;
        if (present("pixie jianpu",ob))
        {
                message_vision(HIY "$N����һ�ʣ��ŵ�$n�����з�ù����Ҷ����ζ���ȵ����ð����㾹��˽���ҵ���լ����������\n"NOR, this_object(), ob );
                kill_ob(ob);
        }
        if( ob->query("biao/bonus") )
        {
                bonus = ob->query("biao/bonus");

	        if (ob->query("combat_exp")< 200000) addexp = 1400 + random(200); 
	        else if (ob->query("combat_exp")< 800000) addexp = 1100 + random(200); 
                else addexp = 800 + random(200);
                message_vision( HIG"$N����$nЦ����$n�ɵĺã����Ǹ����ھ�ȫ�����������˲š�\n\n"NOR,this_object(),ob);
                command( "thumb "+ob->query("id") );
//              if( ob->query("family/family_name") == "ؤ��" ) bonus = bonus - 150; // ؤ�� ppl can send letter to get extra bonus
//              if( ob->query("family/family_name") == "��ɽ��" ) bonus = bonus - 150; // ��ɽ�� ppl can get extra bonus from xuanshan
                ob->delete("biao");
        	bonus = bonus*2;
                ob->add("combat_exp", addexp );
                old_pot = ob->query("potential");
                bonus = bonus / 2 * 3;
                 if(bonus>360)bonus=360;
                ob->add("potential", addexp*2/5 );
                ob->remove_all_killer();
                if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
                ob->add("biaoju/succeed",1);
                if( ob->query("potential") > ob->query("max_potential") ) ob->set("potential",ob->query("max_potential") );
                add_temp("biao", -1);
                log_file("/test/BiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")�ڸ����ھֱ��ڻ��" + addexp + "�����"+ (ob->query("potential")-old_pot) + "Ǳ��\n" );
        }
        if( ob->query("master_name") == "��ʦ" || ob->query("master_name") == "������")
        {
                command( "say ���ھ���ʦ����ͽ�ܣ���������ʦ��");
                message_vision("\n$N����$n˵�����ӽ�������������ʦ��\n\n", this_object(), ob);
                ob->delete("family");
                ob->delete("title");
                ob->delete("master_id");
                ob->delete("master_name");
                ob->set("score", 0);
                skills = ob->query_skills();
                if( mapp(skills) )
                {
                        skname = keys(skills);
                        for(i=0; i<sizeof(skname); i++) skills[skname[i]] /= 2;
                }
        }
        ob->delete_skill("lingbo-weibu");
        ob->delete_skill("dulong-dafa");
}

int ask_fuwei()
{
        say("��������ҫ��˵�������ּ��������ڣ�һ����������Զͼ�����괳�µ���������\n"
                "�����������ּҼҴ������ն����㺬��������н��յľ��棬��Ϊ����������\n"
                "һָ�Ĵ��ھ֡��������ᵽ�������ھ֡����֣�˭��Ҫ�����Ĵָ��˵һ������\n"
                "�ø����������磡��������������\n");
        this_player()->set_temp("marks/��1", 1);
        return 1;
}

int ask_yuantu()
{
        if ((int)this_player()->query_temp("marks/��1"))
        {
                say("�����Ͽ�һ���̶���˵����Զͼ�����ҵ��游�������ھ�����һ�ִ���ġ�����\n"
                        "�游����ʮ��·��а���������ھ֣������Ǵ��ڵ��޵��֡���ʱ�׵���Ӣ�ۼ�\n"
                        "��̫�����磬Ҳ��ȥ�����������յģ�����������������ʦ������������֮ʱ\n"
                        "��������а���������˼��С�\n");
                this_player()->set_temp("marks/��2", 1);
                return 1;
        }
        else
        {
        say("������˵����Զͼ�����ҵ��游��\n");
        return 1;
        }
}

int ask_pixie()
{
        int p1, p2, p3, p4;

        if ((int)this_player()->query("passwd"))
        {
                say("�����ϲ��õ�˵�����Ҳ��Ƕ������������ҵĽ����������档\n");
        }
        else if ((int)this_player()->query_temp("marks/��2"))
        {
                say("������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ��ˣ����µĹ�������\n"
                        "��֪��ϸ����ʵ���������档��\n");

               p1=random(4)+1;
                p2=random(4)+1;
                p3=random(4)+1;
                p4=random(4)+1;
                this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
                write("�����϶�һ�٣����Ŷ������˵������ȥ��ǰ�������Ҹ�����\n"+
                CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
                        "��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4)+
                "��ͭǮ����һֱδ�����а��ء�\n");
        }
        else
        {
                message("vision",HIY "�����ϲ�Ȼ��ŭ���ȵ�����Ҳ���������ּҵı�а���ף����Ҹ���ƴ�ˣ�\n"NOR, environment(), this_object() );
                kill_ob(this_player());
        }
        this_player()->delete_temp("marks/��1");
        this_player()->delete_temp("marks/��2");
        return 1;
}

int ask_tong()
{
        int p, p1, p2, p3, p4;

        if (!(p=(int)this_player()->query("passwd")))
        {
                say("������һ����Ц�����ӣ�˵����ô�쵽��һ���˵���ҪǮ��\n");
        }
        else
        {

               p1=(int)p/1000;
                p2=(int)(p-p1*1000)/100;
                p3=(int)(p-p1*1000-p2*100)/10;
                p4=(int)(p-p1*1000-p2*100-p3*10);
                write("�����ϵ���˵������ȥ��ǰ�������Ҹ�����\n"+
               CHINESE_D->chinese_number(p1)+"ǧ"+CHINESE_D->chinese_number(p2)+
                       "��"+CHINESE_D->chinese_number(p3)+"ʮ"+CHINESE_D->chinese_number(p4)+
               "��ͭǮ����һֱδ�����а��ء�\n");
        }
        return 1;
}

int accept_object(object me, object obj)
{
        object ob = this_player();

        if ( (obj->name() == "�ڻ�" ) && obj->query("id") == "biao huo" )
        {
                call_out("award", 1, this_object(), ob, obj );
                return 1;
        }
        command( "say �ⶫ���Ҳ�����Ȥ��" );
        return 0;
}

void award2(object dest,object owner)
{
        object wage;
        object here = environment(dest);

        if(userp(owner))
        {
                if (MONEY_D->player_job_pay(owner, dest, (10 + random(10)) * 10000))
                {
                        message_vision(HIY"$N"+HIY"�ݸ�$n�����ƽ�˵������������ͽ��Ҹ��ط�����ȥ�ɣ���\n"NOR,dest,owner);
                        command("hehe");
                }
                owner->delete_temp("riding");
        }
}

void award(object me, object ob, object obj)
{
        int bonus,old_pot;
        if( !ob || environment(ob) != environment() ) return;
        message_vision( HIY"$N���ڻ��򿪣�������һ��"+Biaohuo_Name[random(7)]+"��\n"NOR,me);
        if( obj->query("owner") != ob->query("id") )
        {
                message_vision( HIY"$N��Ц�����Ķ������ģ�������Ȼ�䵽���֣���û���ٻ���ĵ���ร�\n"NOR,me);
                destruct(obj);
                return;
        }
        destruct(obj);
        command( "thumb "+ob->query("id") );
        message_vision( HIG"$N����$nЦ����$n�ɵĺã������ھ־�Ҫ���������˲š�\n\n"NOR,me,ob);
        ob->delete_temp("apply/name");
        ob->delete_temp("apply/long");
        ob->delete_temp("apply/short");
        ob->delete_temp("apply/id");
        ob->add("biaoju/succeed",1);
        ob->remove_all_killer();
        call_out("award2",1,me,ob);
        bonus = 1000 + random(400);
        ob->add("combat_exp", bonus );
        old_pot = ob->query("potential");
        ob->add("potential", bonus/2 );
        if( ob->query("potential") > ob->query("max_potential") ) ob->set("potential",ob->query("max_potential") );
        if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
        log_file("/test/BiaoJob", ctime(time()) + ob->query("name") +"(" + ob->query("id") + ")�ڸ����ھֽ��ڻ��" + bonus + "�����"+ (ob->query("potential")-old_pot) + "Ǳ��\n" );
        ob->delete("biao");
        add_temp("biao", -1);
}

private int is_suitable(object victim, object killer)
{
        string *no_kill_list = ({
        "mu ren",
        "huang zhen",
        "juexin dashi",
        "fighter dummy",
        "du e",
        "du nan",
        "du jie",
        "xie yanke",
	"duan jin",
        "ren woxing",
        "qu san",
        "yue buqun",
        "qiu chuji",
        "zhang sanfeng",
        "zuo lengchan",
        "ouyang zhan",
        "seng bing",
        "ma guangzuo",
        "black gargoyle",
        "white gargoyle",
        "tang nan",
        "zhu xi",
        "tangzi shou",
        "lao chaofeng",
        "hua tiegan",
        "yideng dashi",
        "lu tianshu",
        "liu chengfeng",
        "qu san",
        "zhao zhijing",
        "lu youjiao",
        "yang guo",
        "xiao longer"
        "cheng buyou",
        "lin zhennan",
        "hong qigong",
        "master",
        "xun bu",
        "dongfang bubai",
        "du laoban",
        "ling tuisi",
        "zhao liangdong",
        "guai she",
        });
        if(  !victim || !clonep(victim) || !living(victim) || userp(victim)
                || victim->query("race") != "����"
                || victim->query("shen") < 0
                || victim->query("winner")
                || strsrch(base_name(victim), "/kunfu/skill/") != -1
                || strsrch(base_name(victim), "/clone/") != -1
                || strsrch(base_name(victim), "/u/") != -1
                || strsrch(base_name(victim), "/d/xiakedao/") != -1
                || strsrch(base_name(victim), "/task/") != -1
                || victim->query("combat_exp") < killer->query("combat_exp") * 1/4
                || victim->query("combat_exp") > killer->query("combat_exp")*7/4
                || victim->query("family/family_name") == "�һ���"
                || member_array(victim->query("id"), no_kill_list) != -1 || random(2)==0 )
        {
                return 0;
        }
        return 1;
}

void do_leave(object ob)
{
        if( objectp(ob) )
        {
                if( ob->is_busy() || ob->is_fighting())
                {
                        message_vision("$N���һ��������սȦ��\n",ob);
                        message_vision("$N˵�������������������ȥ������Ԯ��\n���Ǽ��ؾ���ʤ����ǧ��Ҫ���˸����ھֵ�������\n",ob);
                }
                if(!living(ob))ob->revive(0);
                message_vision("$N����ææ�뿪�ˡ�\n",ob);
                destruct(ob);
        }
}

void setup_skill(object me,object obj)
{
        mapping skills;
        string *names;
        int level,i;

        if(!objectp(me) || !objectp(obj) ) return;
        if( obj->query("combat_exp") < me->query("combat_exp") )
        {
                obj->set("combat_exp", me->query("combat_exp") /100  * ( 100+random(50) )  );
        }
        level = pow( obj->query("combat_exp")*10.,0.33333 );
        if(level < 10) level = 10;
        if( obj->query("combat_exp") < 4000 )
        {
                level = level/2 + random(level/2);
        }
        else if( obj->query("combat_exp") < 30000)
        {
                level = level/2 + random(level/3);
        }
        else if( obj->query("combat_exp") < 60000)
        {
                level = level/2 + random(level/4);
        }
        else if( obj->query("combat_exp") < 300000)
        {
                level = level/2 + random(level/5);
        }
        else level = level/3 + random(level/6);
        skills = obj->query_skills();
        names = keys(skills);
        for (i=0; i<sizeof(names); i++)
        {
                obj->set_skill(names[i], level);
        }
        obj->set( "title", "�����ھ�" );
        obj->delete( "nickname");
        obj->delete( "long");
        obj->delete( "family");
        obj->delete( "name" );
        obj->delete( "short" );
        if( obj->query("combat_exp") < 500000 ) obj->set_name("������", ({ "tangzi shou", "shou" }));
        else obj->set_name("��ʦ", ({ "biao shi", "biaoshi" }));
        call_out("do_leave",1000,obj);
}

void assign_biaotou(object me, object partner)
{
        object ob,here;
        object *target_list;
        int i;

        if( !userp(me) ) return;
        here = environment(me);
        if(!here) return;
        if( strsrch(base_name(here), "/d/") == -1 ) return;
        target_list = filter_array(livings(), "is_suitable", this_object(), me);
        if( sizeof(target_list) == 0 )
        {
                // try again in 5 secs.
                call_out("assign_biaotou", 5, me,partner);
                return;
        }
        do
        {
                i = random(sizeof(target_list));
                ob=new( base_name(target_list[i]) + ".c" );
        }
        while( !living(ob) );
        ob->move(here);
        setup_skill(me,ob);
        ob->set_temp("biao/owner",me->query("id") );
        if(partner)ob->set_temp("biao/owner2",partner->query("id") );
        ob->set_leader(me);
        message_vision("\n$N�첽���˹���!\n", ob);
        message_vision("\n$N��$n��ȭ������"+RANK_D->query_respect(me)+"��������ͷ�ɰ�����һ��������ڡ�\n��ûɶ˵�ģ��ӽ��Ժ�����ͬ�����и�ͬ���������Ǹ����ھֵĽ������ơ�\n\n", ob,me);
}

int do_jobwith(string arg)
{
        object biaoche, ob = this_player(), me = this_object(), partner,here=environment(me);
        float diff;
        int penalty;

        if(!arg) return notify_fail("��Ҫ��˭���\n");
        partner = present(arg,here);
        if(!partner) return notify_fail("���˲��������ô���\n");
        if( !userp(partner) ) return notify_fail("���˲������ˣ���ô���\n");

        message_vision("$N��$n��ʾ˵������������ͷ���ҿɲ����Ժ�"+partner->query("name")+"������һ���ڣ�\n",ob,me);
        if( partner == ob) return notify_fail("�Լ����Լ����\n");

       	if ( time() < ob->query("bj_job_time") + 900 && ob->query("combat_exp") < 200000 )
		return notify_fail( "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(900 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );		
       	if ( time() < ob->query("bj_job_time") + 720 && ob->query("combat_exp") > 200000 )
		return notify_fail( "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(720 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );
       	if ( time() < ob->query("bj_job_time") + 600 && ob->query("combat_exp") > 2000000 )
		return notify_fail( "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(600 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );
       	if ( time() < partner->query("bj_job_time") + 900 && partner->query("combat_exp") < 200000 )
		return notify_fail( "��׮���º����࣬��Ĵ����Ҫ��Ϣһ�£���"+ chinese_number(900 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );	
       	if ( time() < partner->query("bj_job_time") + 720 && partner->query("combat_exp") > 200000 )
		return notify_fail( "��׮���º����࣬��Ĵ����Ҫ��Ϣһ�£���"+ chinese_number(720 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );
       	if ( time() < partner->query("bj_job_time") + 600 && partner->query("combat_exp") > 2000000 )
		return notify_fail( "��׮���º����࣬��Ĵ����Ҫ��Ϣһ�£���"+ chinese_number(600 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n" );
        if ( ob->query("biao/fail") )
        {
                ob->delete("biao");
                penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
                ob->apply_condition( "biao", penalty );
                ob->add("biaoju/fail",1);
                return notify_fail("���ⲻ���õļһ���㻹������������Ҫ�����ڣ�\n");
        }
        if ( ob->query_condition("biao") )
        {
                return notify_fail("�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n");
        }
        if ( ob->query("biao") )
        {
                command( "angry" );
                return notify_fail("�㻹û���������ô�����ֶ�׮���£�\n");
        }
        if ( ob->query("combat_exp") < 10000 )
        {
                command( "hmm" );
                return notify_fail("���书��ô���ô���ڱ��ھ����£�\n");
        }
        if ( ob->query("combat_exp") > 2700000 )
        {
                command( "hmm" );
                return notify_fail("���书��ô�ߣ���Ҫ���˲��ܱ�����ڣ�\n");
        }
        if ( (int)partner->query("biao/fail") )
        {
                partner->delete("biao");
                penalty = ( 1 + partner->query("biaoju/fail") * 10 / ( 1+ partner->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
                partner->apply_condition( "biao", penalty );
                partner->add("biaoju/fail",1);
                return notify_fail("�ǲ����õļһ����������������Ҫ�����ڣ�\n");
        }
        if ( partner->query_condition("biao") )
        {
                return notify_fail("�����ﵹ�м�׮���£�������ʱ�Ų����Ǽһ�ȥ�ɣ�\n");
        }
        if ( (int)partner->query("biao") )
        {
                command( "angry" );
                return notify_fail("�ǲ����õļһ��û���������ô�����ֶ�׮���£�\n");
        }
        diff = (float)(partner->query("combat_exp") - ob->query("combat_exp"))*10/(float)(partner->query("combat_exp") + ob->query("combat_exp"))*2.0 ;
        if( diff > 2 || diff < -2) return notify_fail("�����书���̫�󣬲��˴��\n");
        command( "say �ðɣ�����������ʱ���������ȱ���á�");
        switch( random(5) )
        {
                case 0:
                        ob->set("biao/dest", "dao baifeng");
                        ob->set("biao/dest2", "/d/dali/yuxuguan2");
                        command("say �����ݶ����͵������������׷��Ƕ�������ڷ�ͬС�ɣ�һ��ҪС�ġ�");
                        break;
                case 1:
                        ob->set("biao/dest", "hu laoye");
                        ob->set("biao/dest2", "/d/xingxiu/house");
                        command("say ���Ǳ���С��������͵����ڣ���ö��С�ģ����˿��ⲻ��");
                        break;
                case 2:
                        ob->set("biao/dest", "ye erniang");
                        ob->set("biao/dest2", "/d/xixia/dawu");
                        command("say ����������͵�����Ҷ����ģ�������Խ�������");
                        break;
                case 3:
                        ob->set("biao/dest", "feng yiming");
                        ob->set("biao/dest2", "/d/foshan/yxhuiguan");
                        command("say ���з�Ҫ�͸���ɽӢ�ۻ�ݷ�һ�����ڻ����������һ�˰ɡ�");
                        break;
                case 4:
                        ob->set("biao/dest", "wang tongzhi");
                        ob->set("biao/dest2", "/d/quanzhou/yaopu");
                        command("say ����Ȫ�ݼ������ϵ������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ���ҩ���ƹ���ͨ�����");
                        break;
        }
        message_vision( "$N�����е��������ţ�\n", me);
        if (ob->query("family/family_name") == "����μ�") ob->add("dali/trust", -1);
	ob->set("bj_job_time",time() );
        ob->add("biao/times", 1);
        ob->apply_condition("biaoju",40);
        ob->set_temp("apply/short", ({HIR"�����ھ���ʦ  "NOR+ob->name()+"("+ob->query("id")+")"}));
        ob->delete_temp("riding");
        ob->remove_all_killer();
        if(partner)
        {
                if (partner->query("family/family_name") == "����μ�") partner->add("dali/trust", -1);
		partner->set("bj_job_time",time() );
                partner->add("biao/times", 1);
                partner->set_temp("apply/short", ({HIR"�����ھ���ʦ  "NOR + partner->name()+"("+partner->query("id")+")"}));
                partner->delete_temp("riding");
                partner->set("biao/dest", ob->query("biao/dest") );
                partner->set("biao/dest2",ob->query("biao/dest2") );
                partner->apply_condition("biaoju",40);
                partner->remove_all_killer();
        }
        biaoche = new(__DIR__"obj/biaoche");
        biaoche->move("/d/city/biaoju");
        biaoche->set_owner(ob,partner);
        me->add_temp("biao", 1);
        assign_biaotou(ob,partner);
        command("say �ڳ���������������ǡ�����ҪС�����£���ν�������ڣ�����������������޶���ʱ�����������");
        return 1;
}

string ask_abandon()
{
        object ob = this_player(), me = this_object();
        int penalty;

        if( !ob->query("biao") ) return "����û�����񣬷���ʲô��\n";
        command("angry");
        command("disapp "+ob->query("id") );
        ob->delete("biao");
        if(ob->query_condition("biaoju")) ob->clear_one_condition("biaoju");
        penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) );
        ob->apply_condition( "biao", penalty );
        ob->add("biaoju/fail",1);
        ob->delete_temp("apply/name");
        ob->delete_temp("apply/long");
        ob->delete_temp("apply/short");
        ob->delete_temp("apply/id");
        ob->remove_all_killer();
        return "�����ǲ����ã��»���Ҫ���£��ҿ�Ҫ���ǿ��ǣ�\n";
}

string ask_job()
{
        object biaoche, ob = this_player(), me = this_object();
        int penalty;

        if ( ob->query("biao/fail") )
        {
                ob->delete("biao");
                penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
                ob->apply_condition( "biao", penalty );
                ob->add("biaoju/fail",1);
                return "���ⲻ���õļһ���㻹������������Ҫ�����ڣ�\n";
        }
       	if ( time() < ob->query("bj_job_time") + 900 && ob->query("combat_exp") < 200000 )
		return "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(900 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n";		
       	if ( time() < ob->query("bj_job_time") + 720 && ob->query("combat_exp") > 200000 )
		return "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(720 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n";
       	if ( time() < ob->query("bj_job_time") + 600 && ob->query("combat_exp") > 2000000 )
		return "��׮���º����࣬�㻹�Ƕ���Ϣ��Ϣ����"+ chinese_number(600 - time() + ob->query("bj_job_time")) +"�������ʰɡ�\n";
        if ( ob->query_condition("biao") )
        {
                return "�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n";
        }
        if ( (int)me->query_temp("biao") >= 1000 )
        {
                return "�������е��ڶ��������ˣ�������������ɡ�";
        }
        if ( ob->query("biao") ) {
                command( "angry" );
                return "�㻹û���������ô�����ֶ�׮���£�\n";
        }
        if ( ob->query("combat_exp") < 10000 )
        {
                command( "hmm" );
                return "���书��ô���ô���ڱ��ھ����£�";
        }
        if ( ob->query("combat_exp") < 10000 )
        {
                command( "hmm" );
                return "���书���˵㣬�����������˲��ܱ�����ڡ���ȥ��һλ��ɣ�";
        }
        command( "say �ðɣ�����������ʱ���������ȱ���á�");
        switch( random(5) )
        {
                case 0:
                        ob->set("biao/dest", "dao baifeng");
                        ob->set("biao/dest2", "/d/dali/yuxuguan2");
                        command("say �����ݶ����͵������������׷��Ƕ�������ڷ�ͬС�ɣ�һ��ҪС�ġ�");
                        break;
                case 1:
                        ob->set("biao/dest", "hu laoye");
                        ob->set("biao/dest2", "/d/xingxiu/house");
                        command("say ���Ǳ���С��������͵����ڣ���ö��С�ģ����˿��ⲻ��");
                        break;
                case 2:
                        ob->set("biao/dest", "ye erniang");
                        ob->set("biao/dest2", "/d/xixia/dawu");
                        command("say ����������͵�����Ҷ����ģ�������Խ�������");
                        break;
                case 3:
                        ob->set("biao/dest", "feng yiming");
                        ob->set("biao/dest2", "/d/foshan/yxhuiguan");
                        command("say ���з�Ҫ�͸���ɽӢ�ۻ�ݷ�һ�����ڻ����������һ�˰ɡ�");
                        break;
                case 4:
                        ob->set("biao/dest", "wang tongzhi");
                        ob->set("biao/dest2", "/d/quanzhou/yaopu");
                        command("say ����Ȫ�ݼ������ϵ������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ���ҩ���ƹ���ͨ�����");
                        break;
        }
        if (ob->query("family/family_name") == "����μ�") ob->add("dali/trust", -1);
        message_vision( "$N�����е��������ţ�\n", me);
        ob->set("bj_job_time",time() );
        ob->apply_condition("biaoju",40);
        ob->add("biao/times", 1);
        ob->set_temp("apply/short", ({HIR"�����ھ���ͷ  "NOR+ob->name()+"("+ob->query("id")+")"}));
        ob->delete_temp("riding");
        ob->remove_all_killer();
        biaoche = new(__DIR__"obj/biaoche");
        biaoche->move("/d/city/biaoju");
        biaoche->set_owner(ob);
        me->add_temp("biao", 1);
// MODIFY BY SCATTER
    me->set_temp("lingzhen", 1);
// END OF MODIFY
        assign_biaotou(ob,ob);
        return "�ڳ���������������ǡ�����ҪС�����£���ν�������ڣ�����������������޶���ʱ�����������";
}

private int is_suitable_rob(object victim, object killer)
{
        if(  !userp(victim)
                || victim->query("race") != "����"
                || victim->query("shen") > 0
                || victim->query("xbiao/dest2") == 0
                || strsrch(base_name(victim), "/u/") != -1
                || strsrch(base_name(victim), "/d/xiakedao/") != -1
                || victim->query("combat_exp") < killer->query("combat_exp") * 4/5
                || victim->query("combat_exp") > killer->query("combat_exp") * 5/4
                || victim->query_condition("biaoju") < 25)
        {
                return 0;
        }
        return 1;
}

string QueryDest(object obj)
{
        if ( obj->query("xbiao/dest") == "dao baifeng" ) return "�����������׷�";
        else if ( obj->query("xbiao/dest") == "hu laoye" ) return "����С�����";
        else if ( obj->query("xbiao/dest") == "ye erniang" ) return "����Ҷ����";
        else if ( obj->query("xbiao/dest") == "feng yiming" ) return "��ɽӢ�ۻ�ݷ�һ��";
        else if ( obj->query("xbiao/dest") == "wang tongzhi" ) return "Ȫ�ݼ������ϵ�";
        return "���صش�";
}

string ask_jiebiao()
{
        object biaoche, ob = this_player(), me = this_object();
        int penalty;


// ADD BY SCATTER
    if( me->query("shen") < 50000 )
    {
        return "������Ҳ��ر꣡\n";
    }
// END OF ADDING



/*
    if ( ob->query("family/family_name") == "��Ĺ��" )
    {
        return "��Ĺ�ɵ��Ӷ������ˣ��������ðɡ�\n";
    }
*/ //gumu dizi���
        if ( ob->query("biao/fail") )
        {
                ob->delete("biao");
                penalty = ( 1 + ob->query("biaoju/fail") * 10 / ( 1+ ob->query("biaoju/succeed") ) ) * ( 30+random(30) ) ;
                ob->apply_condition( "biao", penalty );
                ob->add("biaoju/fail",1);
                return "���ⲻ���õļһ���㻹�����������ң�\n";
        }
        if ( ob->query_condition("biao") )
        {
                return "�����ﵹ�м�׮���£�������ʱ�Ų�����ȥ�ɣ�\n";
        }
        if( ob->query("shen") <0 )
        {
                return RANK_D->query_respect(ob)+"�Ǻڵ��ϵ�Ӣ�ۣ��������ŵù��㣬�ҿͻ�Ҳ�Ų����㡣\n";
        }
        if ( ob->query("biao") )
        {
                command( "angry" );
                return "�㻹û���������ô�����ֶ�׮���£�\n";
        }
        if ( ob->query("combat_exp") < 100000 )
        {
                command( "hmm" );
                return "���书��ô���ô���ڱ��ھ����£�";
        }
        if( assign_rob(ob) > 0 ) return "��ҪС�����£�������޶���ʱ�����������";
        return "�����Ĳ��ɣ�����û��������������ȥ����";
}

int assign_rob(object me)
{
        object ob,here;
        object *target_list;
        int i;
        string rename;

        if( !userp(me) ) return;
        here = environment(me);
        if(!here) return;
        if( strsrch(base_name(here), "/d/") == -1 ) return;
        target_list = filter_array( users(), "is_suitable_rob", this_object(), me);
        if( sizeof(target_list) == 0 )
        {
                return -1;
        }
        do
        {
                i = random(sizeof(target_list));
                ob= target_list[i];
        }
        while( !userp(ob) );
        rename = Robber_Name[random(7)];
        command( "say �ðɣ�����������ʱ���������ȱ���á�");
        message_vision( "$N˵����������ӥ�ھ�һֱ�ͱ��ھ����ԣ��������Ƕ�����������ڣ��ǿ��̣��벻���̣�\n",this_object());
        message_vision( "$N����˵������˵��������������������"+ob->query("name")+"����"+ QueryDest(ob) +"����������"+rename+"ȥ��������\n",this_object());
        me->delete_temp("riding");
        me->set_temp("apply/short", ({rename+"(robber)"}));
        me->set_temp("apply/name", ({rename}) );
        me->set_temp("apply/long",  ({"һ���ڲ����棬��������ļһ\n"}));
        me->set_temp("apply/id", ({"robber","zei"}) );
        me->remove_all_killer();
        me->set("biao/owner",ob->query("id"));
        me->set("biao/dest",ob->query("xbiao/dest"));
        me->apply_condition("biaoju",50);
        return 1;
}
/*
string ask_biao()
{
        object biao, ob = this_player(), me = this_object();

        if ( (int)ob->query_temp("biao/fail") )
        {
                return "���ⲻ���õļһ���㻹������������Ҫ�����ڣ�";
        }
        if ( (int)ob->query_temp("biao/times") >= 5 )
        {
                return "���Ѹ��˺ö�����������Ϣһ�°ɡ�";
        }
        if ( (int)me->query_temp("biao") >= 20 )
        {
                return "�������е��ڶ��������ˣ�������������ɡ�";
        }
        if ( ob->query_temp("biao/zhu")
                || ob->query_temp("biao/bayi")
                || ob->query_temp("biao/ma")
                || ob->query_temp("biao/li")
                || ob->query_temp("biao/jiang") )
        {
                command( "angry" );
                return "�㻹û�������͵��������ϣ���ô�����ֶ�׮���£�";
        }
        command( "say �ðɣ�����������ʱ���������ȱ���á�");
        switch( random(5) )
        {
                case 0:
                        ob->set_temp("biao/zhu", 1);
                        command("say �����ݶ����͵���¹��Ժ���������Ƕ�������ḶǮ���㡣");
                        break;
                case 1:
                        ob->set_temp("biao/bayi", 1);
                        command("say ���Ǳ���С��������͵����ڣ���ö��С�ģ����˿��ⲻ��");
                        break;
                case 2:
                        ob->set_temp("biao/ma", 1);
                        command("say ����������͵�Ȫ��������ݵģ�������Խ��������������ʦ��");
                        break;
                case 3:
                        ob->set_temp("biao/li", 1);
                        command("say ���з�Ҫ�͸���ɽ������ȪԺ��������ڻ����������һ�˰ɡ�");
                        break;
                case 4:
                        ob->set_temp("biao/jiang", 1);
                        command("say ���ǵ����������������еĺ��ڣ���ͬС�ɡ���ǧ�򲻿ɴ��⣬��ؽ����ױ��ӳ�����ʤ���");
                        break;
        }
        message_vision( "�����Ͻ���$Nһ���ڻ���\n", ob );
        ob->add_temp("biao/times", 1);
        ob->set_temp("apply/short", ({"�ڿ�  "+ob->name()+"("+ob->query("id")+")"}));
        biao = new(__DIR__"obj/biaohuo");
        biao->move(ob);
        me->add_temp("biao", 1);
        return "��ҪС�����£���ν�������ڣ�����������������޶���ʱ�����������";
}
*/
