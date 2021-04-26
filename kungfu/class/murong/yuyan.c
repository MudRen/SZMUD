// Code of ShenZhou
// wang yuyan
// arthurgu 1999.9
      
#include <ansi.h>
inherit F_SSERVER;
inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_me1();       
string ask_me2();
string ask_me3();

int do_taojiao(string);

void create()
{
        set_name("������", ({ "wang yuyan", "wang", "yuyan" }));
    set("long","��ׯ�д���������������֮ò��\n");
        set("title", "����ɽׯ С��");
    set("gender", "Ů��");
    set("age", 20);
    set_skill("cuff", 80);
    set_skill("dodge", 80);
    set_skill("parry", 80);
    set_skill("force", 105);
   
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
    set("shen_type", 1);
    set("max_qi", 800);
    set("max_jing", 600);
    set("neili", 800);
    set("max_neili", 300);
    set("combat_exp", 50000);
    set("attitude", "peaceful");
    set("no_get","������Ů���𶯻��Խ");
        set("inquiry", ([
                "Ľ�ݸ�" :  (: ask_me :),
                "����" :  (: ask_me :),
                "����": ({ (: command("smile") :),
                          "�����Ǵ��Ӹ���" }),
                "name" : "��Ϊ��Ҫ������?",
                "here" : "����ô���ҵ�����ģ���Ȼ���ˣ�¶�����书���ҿ����������������书����ô����",
                "����" :  (: ask_me1 :),
                "Ľ�ݲ�" :  (: ask_me2 :),
                "job" : "��Ҫ�ɻ��������ȥ������ȱ�����ֻ��ء�",
                "��Ҫ��Ľ�ݲ�" : (:ask_me3 :),
                ]));

     set("chat_chance",4);
    	set("chat_msg",({
           (: command("sigh") :),
	    "���������������������γ��ţ��ǵ�����ȥ����\n",
        "�����ã���.....���潫�򹷰���ʹ�úܿ죿��\n",
        "����һζ���죬��ؤ���и��ֶ����֣�ֻ��....���з��Ӵ�����ȥ�������𣿡�\n",
	   }) );

    create_family("����Ľ��", 18, "����");

    setup();
    carry_object("/d/city/obj/flower_shoe")->wield();
    carry_object("/d/murong/obj/qingyi")->wear();
}

void init()
{
        object ob;
        
        ::init();
       	        
        if( interactive(ob = this_player()) && !is_fighting()  )
         {
                remove_call_out("check_job");
                call_out("check_job", 1, ob);
        }
	
	if( interactive(ob = this_player()) && !is_fighting() && (string)this_player()->query("id") == "arthurgu" ) {
		remove_call_out("wanfu");
		call_out("wanfu", 1, ob);
        }

        {
        add_action("do_taojiao", "taojiao");
         }
}

int do_taojiao(string arg)
{
        object me=this_object(), who=this_player();
        int skill, myint;

        if (!arg)
                return notify_fail("�����ֽ�ʲô����\n");

        if (who->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (who->is_fighting())
                return notify_fail("����ĥǹ������������\n");

        if (who->query("family/family_name")!="����Ľ��")
                return notify_fail("�Բ����Ҳ�����䲻��ɵ��ˡ�\n");

      
        if (who->query("family")
                && who->query("family/family_name") != "��"
                && who->query("murong/rank")<2)
                return notify_fail("������̫�ͣ������ý��㡣\n");

        if (me->is_fighting() || me->is_busy())
                return notify_fail("û������æ��\n");

        if (!living(me))
                return notify_fail("����������˵�ɡ�\n");

        if (arg!="banruo-zhang"
                && arg!="canglang-bian"
                && arg!="chunyang-quan"
                && arg!="dagou-bang"
                && arg!="duanjia-jian"
                && arg!="duanyun-bian"
                && arg!="feifeng-bian"
                && arg!="fengmo-zhang"
                && arg!="fengyun-shou"
                && arg!="fumo-jian"
                && arg!="huagu-mianzhang"
                && arg!="huashan-jianfa"
                && arg!="huifeng-jian"
                && arg!="hunyuan-zhang"
                && arg!="huoyan-dao"
                && arg!="jiangshi-quan"
                && arg!="jinding-zhang"
                && arg!="jingang-quan"
                && arg!="jinshe-jianfa"
                && arg!="jinshe-zhuifa"
                && arg!="jinyu-quan"
                && arg!="jiuyin-zhao"
                && arg!="lanhua-fuxue"
                && arg!="liangyi-dao"
                && arg!="lingshe-quan"
                && arg!="lingshe-zhang"
                && arg!="liuhe-dao"
                && arg!="luohan-quan"
                && arg!="mingwang-jian"
                && arg!="mo-bang"
                && arg!="nianhua-zhi"
                && arg!="pishi-poyu"
                && arg!="qianzhu-wandu"
                && arg!="quanzhen-jian"
                && arg!="riyue-lun"
                && arg!="riyue-bian"
                && arg!="sanhua-juding"
                && arg!="sanhua-zhang"
                && arg!="shexing-diaoshou"
                && arg!="taiji-dao"
                && arg!="taiji-jian"
                && arg!="taiji-quan"
                && arg!="tangshi-jian"
               && arg!="tanzhi-shentong"
               && arg!="tiangang-zhi"
               && arg!="tianshan-zhang"
               && arg!="weituo-gun"
               && arg!="wuchang-zhang"
               && arg!="wugou-jianfa"
               && arg!="wuhu-duanmen"
               && arg!="xuanfeng-saoye"
               && arg!="xue-dao"
               && arg!="yanxing-dao"
               && arg!="yizhi-chan"
               && arg!="yunu-jianfa"
               && arg!="zui-gun"
               && arg!="murong-shenfa"
               && arg!="shenhe-zhi"
                && arg!="damo-jian")
                return notify_fail("���Ź����Ҳ�׼�����㡣\n");

        if ((int)who->query("potential") < 5)
                return notify_fail("���Ǳ�ܲ��㣬�޷�����κζ�����\n");

        if ((int)who->query("jing") <100 )
                return notify_fail("����ȥ��Ϣ��Ϣ�ɡ�\n");

        skill=who->query_skill(arg,1);

        if (skill * skill * skill / 10 > (int)who->query("combat_exp"))
                return notify_fail("���ʵս���鲻�㣬�޷��ٽ�����\n");

        message_vision("$N������һ���书����$n��ָ���¾���������ߡ�\n", who, me);
        myint=who->query_int();
        who->add("potential", -5);
        who->improve_skill(arg, random(2*me->query("int")));
        who->receive_damage("jing", 20);
        return 1;
}

int wanfu(object me, object ob)
{
	
	if( !ob || environment(ob) != environment() ) return;
      
                me->command("wanfu "+ob->query("id"));
                me->command("whisper "+ob->query("id")+"��������!");
        return 1;
}

string ask_me()
{       
	object ob;
	ob=this_player();
        

  //      if (!ob->query_temp("job") && !ob->query_temp("murong/job1")) {
                ob->set_temp("murong/job1",1);               
                return "��˵���ؤ����ֶ����빫��Ϊ�ѣ����Ǽ������ˣ�Ҫ�����������͸��žͺ��ˡ�\n";
  //      }
  //      else return "���ͷ���Ե����̽ɶ��Ϣ��";
}

string ask_me1()
{
       object who=this_player();
       object obj;
     
       if (obj=present("mr-letter", who))
                return RANK_D->query_respect(who)+"������ϵ������͵���˵";
      
       if (obj=present("xinwu", who))
              return RANK_D->query_respect(who)+"����ȥ����ȡ��ѽ��";

        if( ( who->query("mud_age") - who->query("murong/lastjob")  )<300)
             return "�Ҹյõ���������Ϣ��������������������Űɡ�\n";
                         
            
        if (who->query_temp("murong/job1"))
        {       who->delete_temp("murong/job1");
                who->set_temp("mrjob_status", 1);
                                              
            switch( random(2) ) 
          {

            case 0:
             {  command("say ̫���ˣ������ɣ��������з��ţ��㽻���˰ٴ�����Ϳ����ˣ�����֪ͨ����С�ĵġ�\n");
                obj = new("/d/murong/obj/mr-letter");
                obj->move(who);
                obj->set("job",who->query("id"));
                who->set("murong/lastjob", who->query("mud_age")); 
                break;    }
              
             case 1:
              { command("say ̫���ˣ������ɣ���˵����л��Ÿ��ң��ڰ��������������ȥ��һ�˰ɡ�");
               obj = new("/d/murong/obj/xinwu");
               obj->move(who);
               obj->set("job",who->query("id")); 
               who->set("murong/lastjob", who->query("mud_age"));  
               break;   }               
           }
           remove_call_out("check_job");
           call_out("check_job", 1, who);
           return "�����鷳��";
         }
         return "���ͷ���Ե����̽ɶ��Ϣ��";
}

string ask_me2()
{
        object me;
        me=this_player();

 //       if (!me->query_temp("mrquest") && !me->query_temp("mrquest/quest1")) {
                me->set_temp("mrquest/quest1",1);
                return "�����������������û��˵���������˼һ���������\n";
 //       }
 //       else return "���ͷ���Ե����̽ɶ��Ϣ��";
}

string ask_me3()
{
        object me;
        int old1,old2,old3,old4,new1;
        me=this_player();
        old1=random(8)+1;
        old2=random(8)+1;
        old3=random(8)+1;
        old4=random(9);
        new1=1000*old1+100*old2+10*old3+old4;

        if (me->query_temp("mrquest/quest1")) {
                if (me->query("family/family_name")=="����Ľ��") {
                        write("����������һ��������� ������ȵ�Ĺ�����ң�˵�������ҳ�Щ���ߡ�\n");
                        command("whisper "+getuid(me)+" ��ס ��"+CHINESE_D->chinese_number(old1)+"ǰ"+CHINESE_D->chinese_number(old2)+"��"+CHINESE_D->chinese_number(old3)+"��"+CHINESE_D->chinese_number(old4)+"��");
                        me->set_temp("passwd", new1);
                        me->delete_temp("mrquest/quest1");
                        me->set_temp("mrquest/quest2",1);
                }
                else {
                        write("����֪��Ľ�ݲ������䡱\n");
                        return "�����㻹��ȥ�ʱ��˰ɡ�\n";
                }
        }
        return "�Ҳ����Ѿ�����������?";
}

int check_job()
{           object ob;
            ob=this_player();
            
            
            if ( ob->query("mrjob_status") == 3 )
               { ob->delete("mrjob_status");
                 ob->add("mrjob_comp", 1);
                 ob->add("combat_exp", 80+random(50));
                 ob->add("potential", 50+random(30));
                 
                 if ( ob->query("potential") > ob->query("max_potential") )
                        ob->set("potential", ob->query("max_potential"));
                        
               command("thank");         
               message_vision("�����̶�$N����лл�������ֺͱ��ͨ��ѶϢ�ˡ�������ﲻ�ɾ��⡣\n", ob); 
                }
        
             return 1;
}
