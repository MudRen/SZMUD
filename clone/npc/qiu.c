// Code of ShenZhou
// /kungfu/class/quanzhen/qiu.c
// qiu.c �𴦻�
// sdong 08/01/98
// xQin 8/00 ���뻹�׹���

inherit NPC;
inherit F_MASTER;
inherit F_SAVE;
inherit F_UNIQUE;
#include <ansi.h>
#define BUSY_TIME 180
#define OFFICE "/d/zhongnan/dadian"

int auto_check();
void waiting();
void checking();
void do_chase();
void do_kill(object);
void full_all(object me);
void die();
void do_inquiry();
string ask_me2();
string ask_job();
void reward_dest(object obj,object ob);
void thank_dest(object obj,object ob);
string ask_me_revenge();
string ask_finish();
string ask_huansu();
int do_kill_sb(string arg);
int do_throw(string arg);
int auto_perform();
void thank_feng(object obj,object ob);
void reward_feng(object obj,object ob);
int do_caiyao();

string query_save_file()
{
          return "/data/npc/qiu";
}


void create()
{
    seteuid(getuid());

    if(!restore())
    {
    set_name("�𴦻�", ({ "qiu chuji", "qiu" }));
    set("nickname", "������");
    set("long",
        "������ȫ���������ʢ�����𴦻������ų����ӣ�����ȫ����ƽ����ˡ�\n"
        "���������ʮ����Ŀ��࣬������⣬�������\n");
    set("gender", "����");
    set("age", 69);
    set("attitude", "heroic");
    set("shen_type", 1);
    set("str", 27);
    set("int", 25);
    set("con", 25);
    set("dex", 26);
    set("max_qi", 5000);
    set("max_jing", 3100);
    set("neili", 3800);
    set("max_neili", 3800);
    set("jiali", 80);
    set("combat_exp", 3600000);
    set("score", 5000);

    set_skill("force", 300);
    set_skill("dodge", 300);
    set_skill("parry", 300);
    set_skill("sword", 320);
    set_skill("strike", 300);
    set_skill("cuff", 300);
    set_skill("beidou-zhenfa", 300);

    set_skill("xiantian-gong", 300);
    set_skill("jinyangong", 300);
    set_skill("chunyang-quan", 300);
    set_skill("sanhua-juding", 300);
    set_skill("quanzhen-jian", 320);
    set_skill("literate", 101);
    set_skill("taoism", 300);

    map_skill("force", "xiantian-gong");
    map_skill("dodge", "jinyangong");
    map_skill("cuff", "chunyang-quan");
    map_skill("strike", "sanhua-juding");
    map_skill("parry", "quanzhen-jian");
    map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
    prepare_skill("strike", "sanhua-juding");

    set("class","taoist");

    create_family("ȫ���", 2, "���ӡ��ƽ�����");

    setup();
    }
    else {
    set_name("�𴦻�", ({ "qiu chuji", "qiu" }));
    set("nickname", "������");
    set("long",
        "������ȫ���������ʢ�����𴦻������ų����ӣ�����ȫ����ƽ����ˡ�\n"
        "���������ʮ����Ŀ��࣬������⣬�������\n");
    set("gender", "����");
    set("age", 69);
    set("attitude", "heroic");
    set("shen_type", 1);
    set("str", 27);
    set("int", 25);
    set("con", 25);
    set("dex", 26);

    set("max_qi", 5000);
    set("max_jing", 3100);
    set("neili", 3800);
    set("max_neili", 3800);
    set("jiali", 80);
    set("combat_exp", 1800000);
    set("score", 5000);

    set_skill("force", 300);
    set_skill("dodge", 300);
    set_skill("parry", 300);
    set_skill("sword", 320);
    set_skill("strike", 300);
    set_skill("cuff", 300);
    set_skill("beidou-zhenfa", 300);

    set_skill("xiantian-gong", 300);
    set_skill("jinyangong", 300);
    set_skill("chunyang-quan", 300);
    set_skill("sanhua-juding", 300);
    set_skill("quanzhen-jian", 320);

    set_skill("literate", 101);
    set_skill("taoism", 300);

    map_skill("force", "xiantian-gong");
    map_skill("dodge", "jinyangong");
    map_skill("cuff", "chunyang-quan");
    map_skill("strike", "sanhua-juding");
    map_skill("parry", "quanzhen-jian");
    map_skill("sword", "quanzhen-jian");

    prepare_skill("cuff", "chunyang-quan");
    prepare_skill("strike", "sanhua-juding");

    set("class","taoist");

    create_family("ȫ���", 2, "���ӡ��ƽ�����");
         setup();
         clear_condition();
    }

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
           (: auto_perform :),
    }));
    set("chat_chance", 3);
    set("chat_msg",({
           (: auto_check :),
    }));

    set("inquiry", ([
        "����" : (: ask_me_revenge :),
        "baochou" : (: ask_me_revenge :),
        "�ؼ�" : "�����ķ���̷����ʦ�ֱ��ܣ���ȥ����Ҫ�ɣ�",
        "miji" : "�����ķ���̷����ʦ�ֱ��ܣ���ȥ����Ҫ�ɣ�",
        "����" : (: ask_job :),
        "job" : (: ask_job :),
        "������ͨ��": "������ͨ���Ǳ��ŵ�һ��������ϧ�ұ�������������û�����ɡ�",
        "������": "��ʦ���������ǿ������˵�ģ�",
        "ŷ����": "����ŷ����һ���Ƕ���Ϊ�����֡�˭���ܽ�����ȥ���ؿɸ�ο��ʦү��",
        "����": "����ŷ����һ���Ƕ���Ϊ�����֡�˭���ܽ�����ȥ���ؿɸ�ο��ʦү��",
        "��ʦү" : (: ask_me2 :),
        "����" : (:ask_huansu:),
        "finish" :( :ask_finish: ),
    ]));
    set("book_count", 1);
    set_temp("job_pos",10);
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/greyrobe")->wear();
}


void init()
{
    object ob = this_player();

    ::init();
    if( interactive(ob))
    {
	    if( ob->query("id") == query_temp("target/id") )
        {
     	    do_kill(ob);
         }
    }

    add_action("do_name", "����");
    add_action("do_name", "fuchou");
    add_action("do_kill_sb","kill");
    add_action("do_kill_sb","hit");
    add_action("do_throw","throw");
    add_action("do_inquiry", "inquiry");
}


int do_throw(string arg)
{
    object victim, ob1, ob, me = this_player();
    string what, who;

      	if( !arg || sscanf(arg, "%s at %s", what, who)!=2)
    	return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");
    ob = present(what, me);
    if( !ob ) ob = present(arg, environment(me));
    if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

    if (ob->query("no_drop"))
          return notify_fail("������������뿪�㡣\n");

    if (!(victim = present(who, environment(me))))
          return notify_fail("����û�����Ŀ�ꡣ\n");

    if (!victim) return notify_fail("���ﲢ�޴��ˣ�\n");

    if (!living(victim)) return notify_fail("�ⲻ�ǻ��\n");

    if ( victim->query("id") == me->query("id")  ) {
    	return notify_fail("�Լ�ɱ�Լ���\n");
    }

    if ( victim->query("family/family_name") == "ȫ���"  && victim != this_object() ) {
        message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����У���\n", victim, me);
        message_vision( "$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", this_object() );
        this_object()->kill_ob(me);
        return 1;
    }

    return 0;
}


int do_kill_sb(string arg)
{
    object ob, ob1=this_object(), me = this_player();

    if ( !arg || arg == "" ) return 0;

    if ( !ob=present(arg, environment(me)) ) return 0;

    if ( ob->query("id") == me->query("id")  ) {
	    return notify_fail("�Լ�ɱ�Լ���\n");
    }

    if ( ob->query("family/family_name") == "ȫ���"  && ob != this_object() ) {
         message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
         message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ�����������ɱ�ˣ�����ȫ��̺��۸�ô��\n", ob1);
         ob1->kill_ob(me);
         return 1;
     }
    return 0;
}


void attempt_apprentice(object ob)
{
    mapping fam;
    string name,new_name;

    if( mapp(fam = ob->query("family")) && fam["family_name"] != "ȫ���" )
    {
        command ("say " + RANK_D->query_respect(this_player())
            + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
        return;
    }

    if ((int)ob->query_skill("xiantian-gong", 1) < 80) {
        command("say ��ȫ������ڼ��书���������ڹ��ķ���");
        command("say " + RANK_D->query_respect(ob) +
            "�Ƿ�Ӧ�����������칦�϶��µ㹦��");
        return;
    }

    if ((int)ob->query("shen") < 50000) {
        command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
    return;
    }

    command("say �ðɣ�ƶ�����������ˡ�");
    name = ob->query("name");

    new_name = name[0..1]+"־" + name[4..5];
    command("say �ӽ��Ժ���ͽ���" + new_name + "��");
    ob->set("name",new_name);
    command("recruit " + ob->query("id"));
}

string ask_me2()
{
    mapping fam;
    string msg;

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
        return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";

    if( random(7)==3 )
        msg = "��ʦү�͹�Ĺ������ԨԵ������Ĺ�ɴ��ˣ��ҵ�����ƴ�֮��";
    else if( random(7)==3 )
        msg = "��ʦү�񹦸��������ǿ���Ĵ�Ӣ�ۡ��ұ���ʱʱ����ʦүΪ�ᱮ��";
    else if( random(7)==3 )
        msg = "��ʦү������֪����ŷ����һ���᲻����ȫ��̣���������ô�����ͨ����һ��ָ��ȥ��ŷ����Ĺ�󡹦����ϧ�Լ�ҲԪ�����ˣ�����Ӣ�����š�";
    else if( random(7)==3 )
        msg = "��ʦү�Ķ��ž����Ǵ�����ͨ������ϧ�ұ���������Ȼ������ѧ�ɡ�";
    else if( random(7)==3 )
        msg = "����ŷ����һ���Ƕ���Ϊ�����֡�˭���ܽ�����ȥ���ؿɸ�ο��ʦү��";
    else if( random(7)==2 )
        msg = "��ʦү��֪����ŷ�������ԶԸ������Դ������������ֻҪ�ú������Կ�����ǿ�С�";
    else
        msg = "��ʦү�����ڵ�һ�λ�ɽ�۽�����Ⱥ�ۣ�������µ�һ��������";

    return msg;
}


string ask_job()
{
      mapping job_stat;
      object ob = this_player();
      object me = this_object();
      int good_skill;

      job_stat = ob->query_temp("qz/caiyao");

      if ( ob->query("family/family_name") != "ȫ���" ){
      		if ( ob->query("combat_exp") >= 800000)
      	  		return "��λ"+RANK_D->query_respect(ob)+"����ȫ��̵��ӣ�����ͷ���\n";
 		do_caiyao();
 		return "������λ"+RANK_D->query_respect(ob)+"�ˣ�һ·�϶��С�ġ�\n";
      	}

      if( ob->is_busy() ){
        command("hmm "+ob->query("id"));
        return "�㻹��æ�Ÿɱ�����أ�\n";
      }


      if(job_stat || ob->query_temp("qz/bdgranted") ){
        command("hmm "+ob->query("id"));
        return "�㻹û������񣬾�����Ҫ�µģ�\n";
      }

      ob->start_busy(random(2));
/*       good_skill = (int)( ob->max_skill(ob->query("combat_exp")) * 0.7 ) * 3/2 ;

      if( ob->query("combat_exp") > 20000 && ( (ob->query_skill("sword",1)/2+ob->query_skill("quanzhen-jian",1)) < good_skill ||
            (ob->query_skill("dodge",1)/2+ob->query_skill("jinyangong",1)) < good_skill ||
            (ob->query_skill("parry",1)/2+ob->query_skill("quanzhen-jian",1)) < good_skill ) && random(15) > 0
      )
            {
            command("say ��ȥ�ú���ϰһ�½����������мܰɣ�");
            return "ǧ��Ҫ͵����\n";
            }

      if( ob->query("combat_exp") > 5000 &&
            ob->query("max_neili") < ob->query_skill("force") * 7
            )
            {
              command("say ������������ȥ�úô���һ�°ɣ�");
              return "ǧ��Ҫ͵����\n";
} */

/*      if( ob->query("combat_exp") > 100000 && !(random(3)==1) && ob->query_skill("quanzhen-jian",1) > 60 )
      {
          command("nod");
          command("say �ã������˵��ǿ��Ҫ��������������");
          ob->set_temp("qz/bdgranted",1);
          log_file("job/quanzhen",ob->query("name")+" (" + ob->query("id") + ") ��ȡ��������  "+ctime(time())+"\n");
          return "��ȥ��У����־���Ƕ��ú���ϰһ�¡��������!\n";
      }

      if( ob->query("combat_exp") > 80000 && random(4)==1  && ob->query_skill("quanzhen-jian",1) > 60 )
      {
          command("nod");
          command("say �ã������˵��ǿ��Ҫ��������������");
          ob->set_temp("qz/bdgranted",1);
          log_file("job/quanzhen",ob->query("name")+" (" + ob->query("id") + ") ��ȡ��������  "+ctime(time())+"\n");
          return "��ȥ��У����־���Ƕ��ú���ϰһ�¡��������!\n";
      }*/

      if ( me->query_temp("job_pos") == 0 ) {
                if(random(8)==1)
                  me->set_temp("job_pos",1);
              return "����ûʲôҪ������ȥ������ȥ��Ϣ�ɡ�\n";
      }

/*      me->add_temp("job_pos", -1);

      command("nod");
      command("say �ã���������õĲ�ҩ�������ˣ���ȥɽ��������ȥ��һЩ������");
      yaochu = present("yao chu",ob );
      if(yaochu)destruct(yaochu);
      ob2 = new("/d/zhongnan/obj/yaochu");
      ob2->move(me);
      ob->set_temp("qz/caiyao",1);
      command("give yao chu to "+ob->query("id"));
      log_file("job/quanzhen",ob->query("name")+" (" + ob->query("id") + ") ��ȡ��ҩ����  "+ctime(time())+"\n");
      return "��ȥ��أ�·��ҪС��һЩ��\n";
*///delete by lisser
	if( ((ob->query("combat_exp") > 80000 && random(4)==1)
	    || (ob->query("combat_exp") > 100000 && !(random(3)==1)))
	    && ob->query_skill("quanzhen-jian",1) > 60 )
	{

	    add_action("do_caiyao", "caiyao");
		add_action("do_caiyao", "��ҩ");
		add_action("do_lianzhen", "lianzhen");
		add_action("do_lianzhen", "����");
		return "����������(lianzhen)�Ͳ�ҩ(caiyao)���ֹ������������ĸ�������\n";

	}
	add_action("do_caiyao", "��");
	add_action("do_caiyao", "zuo");
	return "����ֻ�в�ҩ(caiyao)һ�ֹ�������������Ļ��ʹ��������ߡ�zuo����\n";
}

int accept_object(object me, object obj)
{
      object ob = this_player();

      command( "say "+obj->name()+"?");

      if (
      	obj->query("id") == "chuanbei" ||
        obj->query("id") == "fuling" ||
        obj->query("id") == "gouzhi zi" ||
        obj->query("id") == "heshouwu" ||
        obj->query("id") == "huanglian" ||
        obj->query("id") == "jugeng" ||
        obj->query("id") == "jinyin hua" ||
        obj->query("id") == "shengdi"
       ) {

        if ( (ob->query("family/family_name") == "ȫ���") && (ob->query("id")==obj->query("player"))) {
	        call_out("reward_dest", 1, obj, ob);
        }
        else {
            call_out("thank_dest", 1, obj, ob);
        }

        return 1;
       }

       if ( obj->query("id") == "ouyang feng" )
       {
       	if ( ob->query("family/family_name") == "ȫ���" ) {
        	call_out("reward_feng", 1, obj, ob);
        }
        else {
            call_out("thank_feng", 1, obj, ob);
        }
        return 1;
       }

       command( "hmm" );
       command( "say ������ⶫ����ʲ�᣿" );
       return 0;
}

void reward_dest(object obj,object ob)
{
	int time, expG, potG;
	object yaochu = present("yao chu",this_player() );
	if(yaochu)destruct(yaochu);
                expG = 180 + random(40);
                potG = 60 + random(40);
        ob->add("combat_exp",expG);
	ob->add("potential",potG);
if(ob->query("potential")>ob->query("max_potential"))
ob->set("potential",ob->query("max_potential"));
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"�ɵĲ�����ȥ��Ϣһ�°ɣ�\n");
	time = time() - ob->query("qz/jobtime");
	//if (ob->query("qz/jobtime")>0)
	//	log_file("job/qz-caiyao",sprintf("[%s] %s(%s) �� %d ���� Caiyao �õ� %d ����� %d Ǳ�ܡ�\n", ctime(time()) ,ob->name(), getuid(ob), time, ob->query("qz/jobexp"), ob->query("qz/jobpot") )); //add log file.
	ob->set("qz/jobtime",0);
	if(ob->query_temp("qz/caiyao",1) )
	{
		ob->delete_temp("qz/caiyao");
		add_temp("job_pos", 1);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	int time, expG, potG;
	if (ob->query("id")==obj->query("player") && ob->query_temp("qz/caiyao",1)){
                expG = 180 + random(40);
                potG = 60 + random(40);
	        ob->add("combat_exp",expG);
		ob->add("potential",potG);
     if(ob->query("potential")>ob->query("max_potential")) 
     ob->set("potential",ob->query("max_potential")); 
              ob->delete_temp("qz/caiyao"); 
	}
	command( "jump");
	command( "say ���Ǻ���Ҫ��Щҩ�ģ���л����\n");
	destruct(obj);
}

void reward_feng(object obj,object ob)
{
    object lingpai = present("ling pai",ob );

    command( "jump");
    command( "say ��û�뵽���ܽ�ŷ����������̫������\n");

    command( "thumb "+ob->query("id"));
    command( "say ��Ȼŷ���������ˣ������ҵ���һ���������е�����������Ϊ���Σ�\n���ܵ㻯ŷ����һ���������������������������ɽ���鶴�ϼӿ��ܡ�\n");
    command("drop feng");

    if(lingpai)destruct(lingpai);

    lingpai = new("/d/zhongnan/obj/lingpai");

    lingpai->move(this_object());
    lingpai->set("owner",ob->query("id"));

    command("give ling pai to "+ob->query("id"));
    command("say �������е������µ�����������ġ��ִ������ƣ��ӽ��Ժ󱾽̵��Ӽ���������ˡ�\n");
}

void thank_feng(object obj,object ob)
{
    command( "jump");
    command( "say ��û�뵽���ܽ�ŷ������������л����\n");
    destruct(obj);
}


string ask_me_revenge()
{
    object me = this_player();

    if( me->query_temp("asked") )
	    return ("���Ѿ�˵���ˣ�ʱ��һ������Ȼ�ᶯ�֡�\n");


    command("say ����һ������������Ϊ���Ρ�˭ɱ�����ˣ�������ң����ȷʵ�Ļ�����һ��������ԩ����");
    tell_object(me, "����룺���� Ŀ��ID or fuchou ID\n");
    me->set_temp("qiuwait",1);
    return ("��㣡");
}

void do_destroy(object ob)
{
    if( ob ) destruct(ob);
}

int do_name(string target)
{
    object me, asker,ob;
    int i;
    asker = this_player();
    me = this_object();

    if( asker->query_temp("asked") )
  	      return notify_fail("���Ѿ�˵���ˣ�ʱ��һ������Ȼ�ᶯ�֡�\n");

    if(me->query("waiting_target"))
          return notify_fail("�𴦻�˵������������æ���أ�\n");

    if( !this_player()->query_temp("qiuwait") )
          return notify_fail("�𴦻�˵������֪ʩ��ʲô��˼��\n");

    if( !target || target==" ") return notify_fail("�𴦻�˵����ʲô�������������\n");

    if( !(ob = find_player(target)) ) {
    	ob = new(USER_OB);
        ob->set("id", target);
        if( !ob->restore() ) {
        	destruct(ob);
            return notify_fail("�𴦻�˵����û������ˡ�\n");
                     }
         }
         if( this_player()->query("combat_exp") < 10000 )
         {
            return notify_fail("�𴦻�˵����С����˵�Ļ���������\n");
         }

         if( ob->query("combat_exp") < this_player()->query("combat_exp")  )
         {
             return notify_fail("�𴦻�˵����������书��ô����Լ����ᶯ�֣�\n");
         }

         if( this_player()->query("combat_exp") >50000 )
         {
             return notify_fail("�𴦻�˵�������书�Ѿ��л����ˣ�����ǿ��Ϣ��Ŭ������Լ����£�\n");
         }

         if (ob->is_ghost())
             return notify_fail("�𴦻����˵�˵�����Ѿ��ܵ���Ӧ���ˣ��������ۣ�ƶ��Ҳ���س����ˡ�\n");

         if (ob->query("id") != asker->query_temp("my_killer"))
             return notify_fail("�𴦻�ҡҡͷ�����������ûɱ�㡣\n");

          if( asker->query_temp("pking/" + ob->query("id")) ) {
             command("say ���Լ����Ļ�������Թ���ˡ�");
             return 1;
          }

          if( asker->query("PKS") > 20 ) {
             command("say ��ɱ���������Լ�����ɡ�");
             return 1;
          }

          asker->set_temp("asked",1);

  		  if ( asker->query("family/family_name") != "ȫ���" && random(3)==1 ) {
        	command("say ����ƶ��Ҫ��������źá����Ȼ�ȥ�ɣ�\n");
        	return ;
    	  }

          set("job/" + time(), target);
          set("job_time/" + time(), time() );
          save();

          log_file("Qiu_Anti_Pker", sprintf("�𴦻�(qiu chuji) is called by %s(%s) at %s to kill %s(%s) \n",
                asker->query("name"), asker->query("id"), ctime(time()), ob->query("name"), target ));

          message("vision", HIG "�𴦻�Ц��Ц��˵�����ã�����ģ�ƶ����Ϊ�㸴��\n"NOR, environment());


          call_out("do_chase", 1, me);
          return 1;
}


void full_all(object me)
{
      me->set("eff_jing", (int)me->query("max_jing"));
      me->set("jing", (int)me->query("max_jing"));
      me->set("eff_qi", (int)me->query("max_qi"));
      me->set("qi", (int)me->query("max_qi"));
      me->set("jingli", (int)me->query("max_jingli"));
      me->set("neili", (int)me->query("max_neili"));
      me->set("food", (int)me->max_food_capacity());
      me->set("water", (int)me->max_water_capacity());
      me->set_temp("apply/armor", 120);
      me->set_temp("apply/damage", 50);
      me->set_temp("apply/dodge", 120);
      me->set_temp("apply/attack", 50);
      me->set("env/wimpy",60);
}

int auto_check()
{
      object fae, mengzhu, shangshan;
      string name1, name2,name3;
      object ob, dest;
      mapping job, job_time;
      int i, *times;

      string *parts, *safp = ({
 	     "death",
         "island",
         "wizard",
         "xiakedao",
      });

      if(!( mengzhu = find_living("mengzhu")) )
      	mengzhu = load_object("/clone/npc/meng-zhu");
        name1 = mengzhu->query("winner");

      if(!( shangshan = find_living("shangshan")) )
	    shangshan = load_object("/clone/npc/shang-shan");
        name2 = shangshan->query("winner");

      if(!( fae = find_living("fae")) )
        fae = load_object("/clone/npc/fa-e");
        name3 = fae->query("winner");

      if( !living(this_object()) || is_busy() || is_fighting() )
        return 0;

      if( base_name(environment()) != OFFICE )
        return 0;

      if( query_temp("target/id") )
      {
        ob = find_player(query_temp("target/id"));
        if(ob)
        {
	        message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
            full_all(this_object());
            call_out("do_chase", 1);
             return 1;
        }
       }

       if( !(job = query("job")) )
        return 0;
       job_time = query("job_time");

       times = keys(job_time);
       for(i = 0; i < sizeof(times); i++) {
  	     if( time() < job_time[times[i]] )
    	     continue;
         if( !(ob = find_player(job[times[i]])) )
             continue;
         if( !(dest = environment(ob)) )
             continue;
         if( dest->query("no_fight") )
             continue;
         parts = explode(base_name(dest), "/");
         if( parts[0] != "d" )
         	continue;
         if( member_array(parts[1], safp) != -1)
            continue;
         if( parts[2] == "duchuan" || parts[2] == "ship" || parts[2] == "dache" )
            continue;
         if( ob->query("combat_exp") > 800000 && !ob->is_busy() &&!ob->is_fighting() && ob->query("qi")*2 > ob->query("max_qi") &&
 	         ob->query("neili")*5 > ob->query("max_neili"))
            continue;

         if( base_name(environment(ob)) == "/d/city/leitai" ) return;

         if( ob->query("id") == name1 ) //��������
            continue;
         if( ob->query("id") == name2 ) //����ʹ��
            continue;
         if( ob->query("id") == name3 ) //faeʹ��
            continue;

         break;
         }

          if( i >= sizeof(times) )
                     return 0;

          map_delete(job, times[i]);
          map_delete(job_time, times[i]);

          set_temp("target/id", ob->query("id"));
          set_temp("target/name", ob->query("name"));
	      message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
          full_all(this_object());
          remove_call_out("do_chase");
          call_out("do_chase", 1);
          return 1;
}


void do_chase()
{
          object ob = find_player(query_temp("target/id"));

          if( !objectp(ob) || !environment(ob) )
          {
             remove_call_out("waiting");
             call_out("waiting", 0);
             return;
          }
          move(environment(ob));
}


void do_kill(object ob){

	if( objectp(ob) && present(ob, environment())
        && !environment()->query("no_fight") )
    {
    	message_vision("$NͻȻ����������ǰ��\n", this_object());
        set_leader(ob);
        command("look " + ob->query("id"));

        message_vision(HIR "$N��$n˵�����������ˣ�ƶ����Ϊ��������ˣ�\n"
                   +RANK_D->query_respect(ob)+"�����У�\n" NOR, this_object(), ob);
        set_leader(ob);
        kill_ob(ob);
        ob->fight_ob(this_object());
        auto_perform();

        remove_call_out("checking");
        call_out("checking", 2);
     } else
     {
        remove_call_out("waiting");
        call_out("waiting", 1);
     }

}


void waiting()
{
	object ob = find_player(query_temp("target/id"));
    object me = this_object();

    if ( me->query("qi") < me->query("max_qi")/2  && me->query("qi") >20)
    {
    	exert_function("recover");
        message_vision("$N˵�����ã���������������������̡�\n", this_object());
        message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
        move(OFFICE);
        message("vision", "�𴦻����˽���˵������С���书�ߣ��´��������鷳��\n",
             environment());

        full_all(this_object());
        return ;
     }

     if ( objectp(ob) )
     {
     	if( ob->is_ghost())
        {
        	delete_temp("target");
            remove_call_out("do_back");
            call_out("do_back", 1);
            return;
         }else if( is_fighting() && present(ob, environment()))
         {
            remove_call_out("checking");
            call_out("checking", 1);
            return;
         }else if( living(this_object()) && !environment(ob)->query("no_fight") && !is_busy() )
         {
            if ( me->query("eff_qi")*3 < me->query("max_qi")*2 )
            exert_function("heal");
            remove_call_out("do_chase");
            call_out("do_chase", 2);
            return;
          }
     }
     else
     {
          message_vision("$N˵������С����Ŀ죬�´��������鷳��\n", this_object());
          message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
          move(OFFICE);
          message("vision", "�𴦻����˽�����˵������С����Ŀ죬�´��������鷳��\n",
          environment());
          return;
     }

     remove_call_out("waiting");
     call_out("waiting", 20);
}

void checking()
{
          object ob,me;
          me = this_object();

          ob = find_player(query_temp("target/id"));
         if ( me->query("qi") < me->query("max_qi")/2  && me->query("qi") > 20)
         {
                exert_function("recover");
                message_vision("$N˵�����ã������书�ߣ�����������̡�\n", this_object());
                message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
                move(OFFICE);
                message("vision", "�𴦻����˽�����˵������С���书�ߣ��´��������鷳��\n",
                     environment());

                full_all(this_object());
                return ;
         }

          if(!ob)
          {
                message_vision("$N˵������С����Ŀ죬�´��������鷳��\n", this_object());
                message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
                move(OFFICE);
                message("vision", "�𴦻����˽�����˵������С����Ŀ죬�´��������鷳��\n",
                     environment());
              return;
          }

          if( is_fighting() ) {
                     auto_perform();
                     remove_call_out("checking");
                     call_out("checking", 2);
                     return;
          }

          if( objectp(ob = present("corpse", environment()) )
          && ob->query("victim_name") ==  query_temp("target/name") )
          {

         delete_temp("target/id");
                     delete_temp("target/name");
                     delete_temp("target");
                     remove_call_out("do_back");
                     call_out("do_back", 1);
                     return;
          }

          remove_call_out("waiting");
          call_out("waiting", 1);
}

void do_back()
{
        object me = this_object();
        message_vision("$N�Ҵ�ææ�뿪�ˡ�\n", this_object());
        move(OFFICE);
        message("vision", "�𴦻����˽�����Ц���������������е���һ�ء�\n",
                     environment());
        me->set_temp("apply/armor", 0);
        me->set_temp("apply/damage", 50);
        me->set_temp("apply/dodge", 0);
        me->set_temp("apply/attack", 0);

        command("follow none");
        save();
}

void die() {
          object ob,me;

          me = this_object();
          if( !living(this_object()) ) {revive(1);reincarnate();}
          if( base_name(environment()) != OFFICE || query_temp("target/id") == me->query_temp("last_damage_from")->query("id") )
          {
              ob = me->query_temp("last_damage_from");
              if(ob)
              {
                 full_all(me);
                 save();
              }
          }
        ::die();
}


int do_inquiry()
{
	object ob, dest, ob2;
    mapping job, job_time;
    int i, *times;
    string *parts, *safp = ({
    	"death",
        "island",
        "wizard",
        "xiakedao",
    });

    ob = this_player();
    if(!wizardp(ob))
    {
    	message_vision("�𴦻���$Nŭ��������ʲô������Ҳ������ƶ����\n",ob);
        command("kick "+ob->query("id") );
        return 1;
    }

    if( !living(this_object()) )
    {
        message_vision("�𴦻�û���ش�$N�������ˡ�\n",ob);
        return 1;
    }

    if( query_temp("target/id") )
    {
    	tell_object(ob, "�𴦻������㣺����ƶ������׷ɱ"+query_temp("target/name")+"("+ query_temp("target/id")+").\n");
        return 1;
    }

    if( !(job = query("job")) )
    {
         tell_object(ob, "�𴦻������㣺�����Ϸ�û������.\n");
         return 1;
    }

    job_time = query("job_time");

    times = keys(job_time);

    for(i = 0; i < sizeof(times); i++) {
    	tell_object(ob, "�𴦻������㣺����������" + ctime( job_time[times[i]] )+ "ɱ" + job[times[i]] +".\n");
        if( time() < job_time[times[i]] )
        {
        	tell_object(ob, "�𴦻������㣺����ʱ�仹û��.\n");
            continue;
        }

        if( !(ob2 = find_player(job[times[i]])) )
        {
        	tell_object(ob, "�𴦻������㣺������һﲻ������.\n");
            continue;
         }

         if( !(dest = environment(ob2)) )
         {
             tell_object(ob, "�𴦻������㣺������һ�      object ob2;��֪���Ķ�.\n");
             continue;
          }
         if( dest->query("no_fight") )
         {
              tell_object(ob, "�𴦻������㣺������һ���ڰ�ȫ�ط�.\n");
              continue;
          }

          parts = explode(base_name(dest), "/");
          if( parts[0] != "d" )
          {
               tell_object(ob, "�𴦻������㣺������һ��ڷǹ��ڳ���.\n");
               continue;
           }

          if( member_array(parts[1], safp) != -1)
          {
                tell_object(ob, "�𴦻������㣺������һ������Ƶش�.\n");
                continue;
          }

          if( parts[2] == "duchuan" || parts[2] == "ship" )
          {
                 tell_object(ob, "�𴦻������㣺������һ��ڴ���.\n");
                 continue;
          }
          if(  !ob2->is_busy() &&!ob2->is_fighting() && ob2->query("qi")*2 > ob2->query("max_qi") &&
            ob2->query("neili")*5 > ob2->query("max_neili")
            &&  ob2->query("combat_exp") > 800000 )
          {
     			     tell_object(ob, "�𴦻������㣺������һ��书�ϸ�.\n");
                 continue;
 		  }

    	  break;
    	  tell_object(ob, "�𴦻������㣺�ã��ö�����.\n");
    }

    if( i >= sizeof(times) )
    {
          tell_object(ob, "�𴦻������㣺��ʱ�����ܶ���.\n");
          return 1;
    }

    auto_check();
    return 1;
}

int auto_perform()
{
    object me = this_object();
    object target = me->select_opponent();
    object weapon = me->query_temp("weapon");

    if ( !me->is_fighting() ) {
        if ( me->query("eff_qi") < me->query("max_qi") )
	        exert_function("heal");
        me->set("jiali", 300);
        return 1;
    }

    if ( !objectp(target)
      || !random( (int)me->query("combat_exp") * 2
           / (int)target->query("combat_exp") + 1) ) return 0;

    if ( objectp(weapon) && weapon->query("skill_type") == "sword")
    {
          if( me->query("eff_qi",1) > me->query("max_qi",1)*2/3 )
            return perform_action("sword.sanqing");
          else perform_action("sword.tonggui");
    }
    else if ( objectp(weapon) && weapon->query("skill_type") == "whip")
    {
        return perform_action("whip.riyue");
    }
    else
    {
        if( !me->query_temp("sanhua",1) )

            return perform_action("strike.sanhua");
        else
            return perform_action("cuff.lianhuan");
    }
}

string ask_huansu()
{
    object ob, me;
    me=this_player();
    ob=this_object();

    if (me->query("quit/taoist"))
    {
    command("hmm");
    return "���Ѿ����ǳ���֮�ˣ���������֮˵����";
    }
    if (me->query("class") == "bonze" )
    {
    return "��λ"+RANK_D->query_respect(me)+"�˷������ˣ�����һ��ƶ��ʵ��������������ذɡ�";
    }
    if (me->query("family/family_name") == "ȫ���"
    && me->query("class") == "taoist" ){
    command("hmm "+me->query("id"));
    command("look "+me->query("id"));
    command("sigh "+me->query("id"));
    add_action("do_jueding", "������");
    me->set_temp("pending/quit_taoist", 1);
    return ""+RANK_D->query_respect(me)+"��Ȼ��Եδ�ˣ�ƶ��Ҳ����ǿ���������"+RANK_D->query_respect(me)+
           "������Ҫ���ף���ѧ�ķ���ѧʶ�����ۿۣ���"+RANK_D->query_respect(me)+"��˼���������ٸ���ƶ���ɡ�"
           "(type ������)";

    }
    else {
    return ""+RANK_D->query_respect(me)+"���ҵ����ˣ���ˡƶ������Ϊ����";
    }
}

int do_jueding()
{
    object ob, me;
    me=this_player();
    ob=this_object();

    if(!me->query_temp("pending/quit_taoist"))
    return 0;
    message_vision("$N���������ع���������$n��$N̾�˿�����\n\n"
               "$n��$Nͷ�ϵķ��ٲ����������ٰ�$N��������װ���ָ���$Nһ�����¡�\n\n",me,ob);
    command("ok");
    command("say ��������������׼ҵ����ˡ�");
    me->delete("class", "taoist");
    ob=new("clone/misc/cloth.c");
    ob->move(me);
    me->delete_temp("pending/quit_taoist");
    me->set_skill("taoism", me->query_skill("taoism")*2/3);
    me->set_skill("literate", me->query_skill("literate")*2/3);
    write(HIY"��ĵ�ѧ�ķ������ˣ���Ķ���д�ֽ����ˣ�\n"NOR);
    me->set("quit/taoist", 1);
    return 1;

}
//add choose job by lisser.
int do_caiyao()
{
	object ob, me, ob2, yaochu;
	me=this_player();
	ob=this_object();
	if (me->query_temp("qz/bdgranted") || me->query_temp("qz/caiyao"))
	{
		command("hmm "+me->query("id"));
		command("say �㲻������������Ϊʲô������ȥ��");
		return 1;
	}
	if ( time() < me->query( "mp_job_time" )+180 )
	    return notify_fail( "������ûʲô�£����һ�������ɡ�\n" );
	me->set( "mp_job_time", time() );
	me->add_temp("job_pos", -1);
	command("nod");
	command("say �ã���������õĲ�ҩ�������ˣ���ȥɽ��������ȥ��һЩ������");
	yaochu = present("yao chu",ob );
	if(yaochu)destruct(yaochu);
	ob2 = new("/d/zhongnan/obj/yaochu");
	ob2->move(me);
	me->set_temp("qz/caiyao",1);
	message_vision("$N��$nһ��ҩ����\n",ob,me);
	me->set( "mp_job_time", time() );
	me->set("qz/jobtime",time());
	me->set("qz/jobexp",0);
	me->set("qz/jobpot",0);
//	command("give yao chu to "+ob->query("id"));
//	log_file("job/quanzhen",me->query("name")+" (" + me->query("id") + ") ��ȡ��ҩ����  "+ctime(time())+"\n");
	command("say ��ȥ��أ�·��ҪС��һЩ��\n");
	return 1;
}

int do_lianzhen()
{
	object ob, me;
	me=this_player();
	ob=this_object();
	if (me->query_temp("qz/caiyao") || me->query_temp("qz/bdgranted"))
	{
		command("hmm "+me->query("id"));
		command("say �㲻������������Ϊʲô������ȥ��");
		return 1;
	}
	if ( time() < me->query( "mp_job_time" )+180 )
	    return notify_fail( "������ûʲô�£����һ�������ɡ�\n" );
	me->set( "mp_job_time", time() );
	command("nod");
	command("say �ã������˵��ǿ��Ҫ��������������");
	me->set_temp("qz/bdgranted",1);
	me->set_temp("qz/jobtime",time());
	me->set_temp("qz/jobexp",0);
	me->set_temp("qz/jobpot",0);
//	log_file("job/quanzhen",me->query("name")+" (" + me->query("id") + ") ��ȡ��������  "+ctime(time())+"\n");
	command("say ��ȥ��У����־���Ƕ��ú���ϰһ�¡��������!\n");
	return 1;
}

string ask_finish()
{
    int exp, pot;
    object me = this_player();
    if ( !me->query( "qzzhenfinish" ) )
        return "����ûȥ���������ʲô��\n";
    me->delete( "qzzhenfinish" );
    exp = 180 + random( 40 );
    pot = exp*2/5;
    me->add( "combat_exp", exp );
    me->add( "potential", pot );
    if ( me->query( "potential" ) > me->query( "max_potential" ) )
        me->set( "potential", me->query( "max_potential" ) );
    return "�������ˣ�ȥ��Ϣһ�°ɡ�\n";
}

