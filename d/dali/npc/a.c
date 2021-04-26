// Code of ShenZhou
#include <ansi.h>

inherit NPC;

int do_train(string);
int do_walkhorse();
void end_walkhorse(object, int);

int djobid = 1;

void create()
{
        set_name("���", ({ "ma fu", "ma", "fu" }) );
        set("gender", "����");
        set("age", 40);
        set("long",
"����һ������������ʵʵ�������ר�Ÿ������ү����\n");
 
        set("str", 30);
        set("int", 35);
        set("con", 25);
        set("dex", 35);
        set("attitude", "peaceful");
        set("combat_exp", 4000);
        set("title", "ƽ���������");
        set("inquiry", ([
               "name" : "������ү�����ר�Ÿ�������",
                "here" : "��������",
                "����" : "�õĺܣ���������ȱ�����أ������������ֻһ����\n"
                         
"����(walkhorse)����ֻҪ����һ��ǣ�������������ˡ� \n"
                         
"��һ����ѵ��(trainhorse)��û����ˢ���㻹�Ǳ��ϡ� \n",      
        ]));

        set("wanted", ({ "����ƽ���������" }));

        setup();
        }
void init()
{
        object me = this_player();
        mapping myfam;

        ::init();
        
        myfam = (mapping)me->query("family");

        add_action("do_train", "train");
        add_action("do_walkhorse", "walkhorse");
        if( interactive(me) && !is_fighting() )
        {
                remove_call_out("greeting");

                call_out("greeting", 1, me);
        }
}
void greeting(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if( !me || environment(me) != environment() ) return;

        if ( myfam && myfam["family_name"] == "����μ�" )
        command("say ��λ" + RANK_D->query_respect(me)+ 
"���ˣ���ӭ����������\n");
        else 
              
  command("say 
����ʲô�ˣ�˽���ʼ�֮�أ�����͵���ɣ�");
}


int do_walkhorse()
{
        object ob;
        string what;
        string *wanted;
         mapping myfam;
        
        
        ob = this_player();
        myfam = (mapping)ob->query("family");

        if ( myfam && myfam["family_name"] != "����μ�" )
           {
     command("say
��Щ������ү�İ����ҿɲ����Ľ̸����ˣ�");
 return 1;
        }

        if ( ob->is_busy() || ob->is_fighting() )
        {
                tell_object(ob, "��������æ�ţ�\n");
                return 1;
        }               
        if ( ob->query("djob/supervisor") )

        message_vision("$N����������\n", ob);

        if ( ob->query("djob/supervisor") )
        {
                command("say �������������أ�����뽻�");

                if ( ob->query("djob/supervisor") == "���") 
                {
                        add_action("do_say", "say");
                        command("say 
����㼱��ȥ����������Ը���˵�����ߡ�");
                } else  
                        command("say 
����������ߣ�����ֱ��ȥ����"+ob->query("djob/supervisor"));        
                
                return 1;
        }

         if (query_temp("aaa") > 1)
        
        {
                command("say �����ͦ�ã�����͵õ����ˡ�");
                return 1;
        }

        add_temp("aaa", 1);

        wanted = query("wanted");
        what = wanted[random(sizeof(wanted))];

        ob->set("djob/supervisor", "���");
        ob->set("djob/object", what);
        ob->set("djob/description", what);
        ob->set("djob/id", djobid);
        ob->set_temp("apply/short", 
                ({ HIW" 
����ƽ���������"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
        
message_vision("�����˶�$N˵�����������ã�������ȱ���֡�\n", ob);
        command("say 
���������úð���æ�ɣ�");

        call_out("end_walkhorse", 300, ob, djobid);
        djobid++;

        return 1;
}

void end_walkhorse(object who, int jobid)
{
        int i; 
        if ( !objectp(who) || !present(who, environment(this_object())) 
                || (string)who->query("djob/description") != 
"����ƽ���������"  
                || (int)who->query("djob/id") != djobid )
                return;

        
message_vision("����$N˵�����ã��ã������о�����ˣ���������ˣ�\n", 
who);
        command("goodkid " + who->query("id"));
        
        who->delete_temp("apply/short");
        who->add("dali/jobdone", 1);
        who->delete("djob/supervisor");
        who->delete("djob/description");
        who->delete("djob/wage");
        who->delete("djob/object");
        who->delete("djob/id");
        who->add("max_jingli", 1);
        add_temp("aaa", -1);
}


int do_say(string arg)
{
    object ob, who;

    who = this_player();
    ob = this_object();

        if ( arg != "��������") return 0;

    if ( who->query("djob/supervisor") != ob->query("name")) return 0;

    message_vision("$N����˵��� �����һ�����ȥ�������ɡ�\n", who);
    command("disapp "+ who->query("id"));
    command("say ����û��Ϣ�Ķ������ҿ�������Ҳ������ʲô��������");

        who->delete_temp("apply/short");

    this_object()->add_temp("aaa", -1);
    who->add("djob/fail", 1);
    who->delete("djob/supervisor");
    who->delete("djob/description");
    who->delete("djob/object");
    who->delete("djob/id");

    return 1;
}


int do_train(string arg)
{
        object me;
        int a,b,c,d,reward;
        me=this_player();
        if ( !arg || arg != "horse" )
             return notify_fail( "ѱʲô��\n");

        if (me->query_temp("trainhorse")) {

                if (me->is_busy())
                        return notify_fail("����æ���ء�\n");

        if ( me->query("djob/supervisor") )
                      
                return notify_fail(" ����������˵ѱ����¡�");
        
                tell_object(me, "�㿪ʼսս������ѱ���ˡ�\n");
  a = me->query_skill("force");
  b = me->query_skill("dodge");
  c = me->query_skill("finger");
  d = me->query_skill("kar");
  reward = random(3);   
if  (random(a+b+c+d) < 40)
{
message_vision("$N��һ����������������һ���Ӱ�$N����һ�����������ڵ��ϰ���ߺ�ߴߴ����������\n", me);

                me->receive_damage("qi", 50);
                me->start_busy(150);
 me->delete_temp("trainhorse");
return 1;
}
if  (random(a+b+c+d) > 40 && (random(a+b+c+d) < 70) )
{
message_vision("$NС���������������ȴ�����������һ��������ˤ�ڵ��ϰ���ߺ�ߴߴ����������\n", me);

                        
                me->receive_damage("qi", 50);
                me->start_busy(120);
 me->delete_temp("trainhorse");
return 1;
}
else
 {
message_vision("$N��������Ĳ�������������˵������ÿɰ��ϡ�\n", me);
 tell_object(me, "��ϲ��ѱ��ɹ���\n");

 me->add("max_jingli", reward);
me->start_busy(120);
me->add("dali/jobdone", 1);
 me->delete_temp("trainhorse");
}
return 1;
}
}

