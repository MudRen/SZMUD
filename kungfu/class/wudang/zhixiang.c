// Code of ShenZhou
// zhixiang.c ������� 
// Marz@XKX, 11/11/96
// xQin 04/01

#include <ansi.h>
#include "daozhang.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

string ask_job();
void greeting(object);
int do_say(string);
int do_kill(string);

void create()
{
        set_name("�������", ({ "lingxu daozhang", "lingxu", "zhixiang daozhang", "zhixiang", "daozhang" }));
        set("nickname", "�������");
        set("long",
                "�����ǳ����ʦ�����顣\n"
                "����ʮ���ְ꣬λ�������������������𣬼������Ǯ��\n");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1000);
        set("max_jing", 750);
        set("neili", 1250);
        set("max_neili", 12500);
        set("jiali", 50);
        set("combat_exp", 60000);
        set("score", 6000);

        set_skill("force", 80);
        set_skill("taiji-shengong", 80);
        set_skill("dodge", 60);
        set_skill("tiyunzong", 60);
        set_skill("strike", 80);
        set_skill("mian-zhang",80);
        set_skill("parry", 60);
        set_skill("sword", 50);
        set_skill("literate", 50);
        set_skill("taoism", 50);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "mian-zhang");

        prepare_skill("strike", "mian-zhang");


        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        set("inquiry", 
                ([
                        "���" : "������Ʋ��ף�����������ˣ��Ϸ����߷��ܵ�֮��\n",
                        "����" : "���㣿ͯ���޼ɣ�ͯ���޼ɣ�Ҫ˵������ǣ�\n",
                        "����" : "���õ���������Ӳ��ϣ�����Ϊ���䵱���Ӻ�ɽ����ͼ�ʱ���\n",
                        "�Ϸ���" : "�Ϸ��׾���������������Ǯ�������幤��\n",
                        "����" : "�������������������Ǯ�������幤��\n",
                        "����" : "�䵱������ɽ�Ÿ�����\n",
                        "����" : "�䵱���־������湬��\n",
                        "����" : "���Ͼ��Ǻ��ɺ���أ���ÿ�춼Ҫ����ȥ������\n",
                        "����" : (: ask_job :),
                        "��ľ" : (: ask_job :),
                        "����" : "������ÿ�춼��Ҫ��ȥ�������������������Щ�������Ǹ��á�\n",
                        "�ɻ�" : "������ÿ�춼��Ҫ��ȥ�������������������Щ�������Ǹ��á�\n",
                ]));
                                
//      set("wanted", ({ HIR"��������"NOR, "�������" }));
        set("wanted", ({ HIR"��������"NOR }));

        set("chat_chance", 5);
        set("chat_msg", ({
                "����˵����������Ʋ��ף�����������ˣ��Ϸ����߷��ܵ�֮��\n",
                "����˵�������ɺ���ض����������ĺò��ϡ�\n",
                "����˵������������Ǵ������￳��������\n",
                "����˵�����䵱�����ֺͰ��ֶ����˼������ˣ���û������ͨ����\n",
                "����˵����������ʱ��Ҫ���С�ģ����ɳ������ĵ�ʿ����Щ����ȥ�޻ء�\n",
        }) );

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}


void init()
{
        object me = this_player();
        
        ::init();

        add_action("do_kill", "kill");

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}



void greeting(object me)
{
        mapping myfam;
        object where, ob;

        ob = this_object();
        myfam = (mapping)me->query("family");
        where = environment(ob);

        if( !me || !living(ob) || strsrch(file_name(where), "/d/wudang/") < 0
                || environment(me) != environment() )
                return;

        if ( (string)me->query("job/supervisor") == "�������" )
        {
                me->set_temp("apply/short", 
                        ({ HIW"�䵱��ľ��"NOR+me->query("name")+"("+capitalize(me->query("id"))+")"}));

                message_vision("���������ס$N��������ȥ�ҵ�" + me->query("job/object")
                        +"���������ˣ�\n", me);

        } else if ( myfam && myfam["family_name"] == "�䵱��" )
        {
                if ( me->query("wudang/offerring") < me->query("age") )
//                        message_vision("�����������$Nŭ����������ھ���뱻���ɽ�Ų�Զ�ˣ�\n", me);
                             message_vision("�����������$N�����ĳ��������䵱���ӣ���Ӧ������ף�" 
                                     + RANK_D->query_respect(me)+ "Ҫ��ǿŬ������\n", me); 
                else if ( me->query("wudang/offerring") < me->query("age")*4/3)
                        message_vision("�����������$N�����ĳ��������䵱���ӣ���Ӧ������ף�"
                                + RANK_D->query_respect(me)+ "Ҫ��ǿŬ������\n", me);
                else if ( me->query("wudang/offerring") < me->query("age")*2)
                        message_vision("���������$N˵����" + RANK_D->query_respect(me)
                                + "�ܾ�ְ����ڵ�����������⡣\n", me);
                else 
                        message_vision("�������ָ��$N��̾����" + RANK_D->query_respect(me)
                                + "���ھ�������ұ���ģҲ��\n", me);
    } else if ( me->query("title") == "�䵱��ͯ" ) 
                message_vision("�����������$N˵��������Ŭ������ȡ��������ɽ�š�\n", me);
        else if ( me->query("wudang/offerring") > me->query("age")*2 ) 
                message_vision("�����������$N�ʺ����ԭ���Ǵ���͵��ˣ�ʧӭ��ʧӭ��\n", me);
        else if ( me->query("wudang/offerring") > me->query("age") ) 
                message_vision("�����������$N�ʺ������λ������ˣ�\n", me);
        else 
        {
                me->set("wudang/yuzhen_block", 1);
                say("�������˵�����粻�Ǿ��㣬������ɽ��\n");
        }
}


string ask_job()
{
        object ob;
        string what;
        string *wanted;

        ob = this_player();

        if ( ob->query("job/supervisor") )
        {
                command("say ���һ�ݻ����û����������ڶ��ݣ�");

                if ( ob->query("job/supervisor") == "�������") 
                {
                add_action("do_say", "say");
                return ("�����ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�");
                }
                
                return ("�����ɲ��ˣ�����ֱ��ȥ����"+ob->query("job/supervisor"));    
        }

        if (ob->query("mp_job_time") + 120 < time ()) return ("��л��λ" +RANK_D->query_respect(ob) 
                                     +"��������Ҫ�Ĳ��϶��Ѿ��������ˡ�\n"); 

        if (query_temp("stock") > 1000000)
                return ("�������ˣ�����Ļ���Ҷ��������ˡ�");

        add_temp("stock", 1);

        wanted = query("wanted");
        what = wanted[random(sizeof(wanted))];

        ob->set("job/supervisor", "�������");
        ob->set("job/object", what);
        ob->set("job/description", what);
        ob->set("job/wage", 3);
        ob->set_temp("apply/short", 
                ({ HIW"�䵱��ľ��"NOR+ob->query("name")+"("+capitalize(ob->query("id"))+")"}));
                                

        message_vision("����������˶�$N˵�����������ã�������ȱ���֣�\n", ob);
        return ("����Ҫ"+ what +"�����ã���ȥ���ҿ�Щ���ɣ�\n");
}

int accept_kill(object obj)
{
        if (obj->is_killing(this_object()) ) return 1;
        command("menpai ��λ�䵱ͬ�ţ�" + obj->name() + "���" + RANK_D->query_rude(obj
) + "�������䵱��Ұ������һ������ϣ�");
}

int accept_object(object who, object ob)
{

        object obn, wage;       
        int i, j, k;
        string *wanted;

/*      if (ob->query("money_id") && ob->value() >= 100*(int)who->query("age") ) 
        {
                if ((string)(who->query("family/family_name")) == "�䵱��") 
                        tell_object(who, "��������һЦ����Ȼ������˳��������"
                        +"�������������һ֦���������ȥ����ɡ�\n");
                else 
                        tell_object(who, "��������һЦ����Ȼʩ����˳��������"
                        +"�������������һ֦����ʩ����ȥ����ɡ�\n");

                obn = new("/d/wudang/obj/incense");
                obn->move(who);
                return 1;
        } else 
*/
                if (ob->query("money_id") )     
        {
                if ((string)(who->query("family/family_name")) == "�䵱��") 
                        tell_object(who, 
                        "����������̾�����䵱ɽ���ʢ��ȫ�����������������𰡣�\n");
                else  
                        tell_object(who, 
                        "����������̾�����䵱ɽ���ʢ��ȫ����������������Ͱ���\n");

//              if (random(ob->value())/50 > who->query("age"))
//                      who->add("wudang/offerring", 1);
                return 1;
        } else if (  ((string)who->query("job/supervisor") == "�������")
                        && (string)who->query("job/object") == (string)ob->query("name") )   
        {
                i = (int)who->query("job/wage");
                if (i < 0 || i >= 13) i = 2;

                wage = new("/clone/money/silver");
                wage->set_amount(i);
                wage->move(who);

                command("say ������λ"+RANK_D->query_respect(who)+"�ˡ�");
                command("thumb " + who->query("id"));
                message_vision("���������$N"+chinese_number(i)+"��������Ϊ�������ꡣ\n", who);

         if (who->query("mp_job_time") + 120 < time ()) who->add("combat_exp", 180 + random(40));
         if (who->query("mp_job_time") + 120 < time ()) who->add("potential", 60 + random(40));
                        who->set("mp_job_time",time());
                who->delete_temp("apply/short");
                who->add("job/succeed", 1);
                who->delete("job/supervisor");
                who->delete("job/description");
                who->delete("job/wage");
                who->delete("job/object");

                return 1;
        } else if( (int)member_array((string)ob->query("name"), (string *)query("wanted")) != -1 )    
        {
                if ( query_temp("stock") > 2000000 )                 
                {
                        say("����ҡҡͷ˵����л��λ" +RANK_D->query_respect(who)
                                +"��������Ҫ�Ĳ��϶��Ѿ��������ˡ�\n");
                        return 1;                       
                }       
                
                message_vision("����������˶�$N˵�����������ã�������������Ҫ�ģ�\n", who);

                add_temp("stock", 1);   
                who->add("wudang/offerring", random(1));

        i = (int)who->query("job/wage");
                j = who->query("wudang/offerring") - who->query("age")*2; 
    
                if ( (who->query("family/family_name") == "�䵱��" ) &&  (j > 0 ) )
                {
         if (who->query("mp_job_time") + 120 < time ()) who->add("combat_exp", 180 + random(40));
                        k = j/2 + random(i);
                        
         if (who->query("mp_job_time") + 120 < time ()) who->add("potential", 60 + random(40));
                        if (who->query("potential") > who->query("max_potential"))
                        who->set("mp_job_time",time());
                        who->set("potential", who->query("max_potential"));
                        if ( random(2) ) 
                        {
                                tell_object(who, "�������������һ֦������ȥ����ɡ�\n");
                                who->add("wudang/offerring", -1-random(3));
                                obn = new("/d/wudang/obj/incense");
                                obn->move(who);
                        }
                        
                } else if ( who->query("family/family_name") == "�䵱��" )
                {
         if (who->query("mp_job_time") + 120 < time ()) who->add("combat_exp", 180 + random(40));
         if (who->query("mp_job_time") + 120 < time ()) who->add("potential", 60 + random(40));
                        who->set("mp_job_time",time());
                        k = 1+random(i);
                if (who->query("potential") > who->query("max_potential"))
                who->set("potential", who->query("max_potential"));
                } else  
                        who->add("combat_exp", 1+random(i));

                command("say �������ԸΪ�䵱Ч�����պ�س��䵱������");
                command("thumb " + who->query("id"));
                
                return 1;
        }


        return 0;
}


int do_say(string arg)
{
    object ob, who;

    who = this_player();
    ob = this_object();

        if ( (string)arg != "�ɲ���") return 0;

    if ( who->query("job/supervisor") != ob->query("name")) return 0;

    message_vision("$N����˵�����������ɵĻ��Ҹɲ��ˡ�\n", who);
    command("pat "+ who->query("id"));
    command("say û��ϵ���´˺úøɣ�");

    this_object()->add_temp("stock", -1);
    who->delete_temp("apply/short");
    who->add("job/fail", 1);
    who->delete("job/supervisor");
    who->delete("job/description");
    who->delete("job/wage");
    who->delete("job/object");

    return 1;
}


int do_kill(string arg)
{
        int i;
        object me, ob;

        me = this_player();
        ob = this_object();

        if (!arg || !ob->id(arg)) return 0;

        if ( me->query("job/supervisor") == "�������" )
        {
               message_vision("$N��ɱ��$n��\n"
                   "$n������$N���������췴�ģ������������\n", me, ob);
               me->set("job/wage", 0);
               return 1;
        }

        if ( me->query("family/family_name") == "�䵱��" )
                {
                        message_vision( "$N��ɱ��$n��\n$n������$N�������ұ�ͬ�ţ�"
                        "ȴΪ�����຦���ң�\n$n��$N�ܲ����⣡\n", me, ob);

            me->add("wudang/offerring", -20);
             return 1;
        }

        return 0;
}



// End of File
