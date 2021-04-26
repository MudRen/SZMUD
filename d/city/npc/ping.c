// Code of ShenZhou
// ping.c ƽһָ

inherit NPC;
inherit F_DEALER;
#include <ansi.h>;
#include "/d/REGIONS.h"

string ask_renshen();
int ask_me();

void create()
{
        set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
        set("title", "ҩ���ϰ�");
        set("nickname","ɱ����ҽ");
        set("gender", "����");
        set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
        set("age", 65);

        set("int", 30);
        
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("shen_type", 1);

        set("combat_exp", 50000);
        set("attitude", "peaceful");

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_temp("apply/attack", 140);
        set_temp("apply/defense", 140);
        set_temp("apply/damage", 50);
        set("inquiry", ([
                "����":(:ask_me:),
                "heal":(:ask_me:),
                 "����ɽ�˲�" : (: ask_renshen :),
                 "renshen" : (: ask_renshen :),
        ]) );
      //  set("vendor_goods", ({}));
        set("vendor_goods", ({
                DRUG_D("jinchuang"),
                DRUG_D("sheyao"),
                DRUG_D("yangjing")
        }));
        setup();
//        add_money("gold", 1);
}
void init()
{       
        object ob;
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        if( interactive(ob = this_player()) && !is_fighting()&&!ob->query_temp("fengyaoover") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        int eff_qi,max_qi,hurt,body;
        if( !ob || environment(ob) != environment() ) return;
        eff_qi = ob->query("eff_qi");
        max_qi = ob->query("max_qi");
        if(100*eff_qi/max_qi<=35) hurt = 3;
        else if(100*eff_qi/max_qi<=60) hurt = 2;
        else if(100*eff_qi/max_qi<=90) hurt = 1;
        else hurt = 0;
        switch(hurt)
        {
                case 1 : message_vision(CYN"ƽһָ�������еض�$N˵������λ" + RANK_D->query_respect(ob)
                                + "�������˵����ˣ����������ƵĽ�ҩ������������ϰա�\n"NOR,ob);
                         break;
                case 2 : message_vision(CYN"ƽһָ��$N˵������λ" + RANK_D->query_respect(ob)+"�������˲��ᣬ����������һЩ��ҩ�ɡ�\n"NOR,ob);
                         break;
                case 3 : message_vision(CYN"ƽһָ����$N�����̾��һ������˵������λ" + RANK_D->query_respect(ob)+"���ش�Σ���������ӡ�\n"NOR,ob);
                         break;
                default : command("look "+ob->query("id"));
                         break;
        }
}

string value_string(int value)
{
    if( value < 1 ) value = 1;
    else    if( value < 100 )
        return chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": ""); 
}

int ask_me()
{
    int body;
    object ob;
    mapping inv;
    string str,*cond;
    int i;
        ob=this_player(); 
    inv=ob->query_conditions();
        body = body = ((int)this_player()->query("max_qi") - (int)this_player()->query("eff_qi")) + ((int)this_player()->query("max_jing") - (int)this_player()->query("eff_jing"))*2;
       if (((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
         && ((int)this_player()->query("eff_jing") == (int)this_player()->query("max_jing"))
    && !sizeof(inv)){
                command("say ������ֻ�����ƾ������ܾ��������ġ�");
                command("say ����߿����������β���");
        return 1;
    }
        tell_object(ob, "\nƽһָ̧ͷ�����㼸�ۡ�\n");
    str="";
    if (sizeof(inv)){
        cond=keys(inv);
        for (i=0;i<sizeof(inv);i++){
            if (cond[i]=="drunk")
            str+="���������ģ�һ���Ǻ����ˣ�";
            if (cond[i]=="killer"){
                command("say �ٸ���ͨ�����أ��㻹�ǿ��߰ɣ�");
                return 1;
            }
    }
    if (str==""){
        command("say ����ʲô���ɣ��ҿɲ����Σ�");
                return 1;
    }

        ob->set_temp("count",sizeof(inv)*10);
    }
        if ( (int)this_player()->query("eff_qi") < (int)this_player()->query("max_qi") )
        {
             ob->set_temp("count",5); 
             str+="��������������˵����ˡ��� \n";
         }
    if ( (int)this_player()->query("eff_jing") < (int)this_player()->query("max_jing") )
        {
                 ob->set_temp("count",10);
                 str+="�����㾫Ԫ���˵����ˡ��� \n";
        }            
        str+="��"+value_string(body * 2 * ob->query_temp("count") )+"���ȸ�Ǯ�����β��� \n";
        command("say "+str);
                return 1;
}

int accept_object(object who, object ob)
{
    int body;
    body = ((int)this_player()->query("max_qi") - (int)this_player()->query("eff_qi")) + ((int)this_player()->query("max_jing") - (int)this_player()->query("eff_jing"))*2;
    if (who->query_temp("count"))
        if (ob->query("money_id") && ob->value() >= who->query_temp("count")*body * 2 ){ 
                who->set("eff_qi",who->query("max_qi"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("eff_gin",who->query("max_gin"));
                who->apply_condition("drunk",0);
                who->start_busy(body/1000);
                tell_object(who, "ƽһָ�ó�Щҩ�������£�����һ����������ɫ�������ö��ˡ�\n");
            who->set_temp("count",0);
                return 1;
            }  else
                tell_object(who, "ƽһָ����һЦ����Ȼ��û�г��⣬�αػ�Ҫ������ûȤ��\n");
    return 0;
}
string ask_renshen()
{
        object obj, me = this_player();
        mapping prices;
        string *places, place;
        int price;

        if( !(obj = present("bang ling", me)) )
                return RANK_D->query_respect(me) + "�������⣬���ز��Ĳμۡ�";

        if( (string)obj->query("job/type") != "����" )
                return RANK_D->query_respect(me) + "�������⣬���ز��Ĳμۡ�";

        if( (string)obj->query("job/name") != "����ɽ�˲�" )
                return "��ֻ֪���μۣ�" + RANK_D->query_respect(me) + "����ȥ����˴����ɡ�";

        if( !mapp(prices = obj->query("job/prices")) )
                return "����μۻ��ң��Ҳ���̫�����";

        price = 0;
        place = "city";
        places = keys(prices);
        for(int i = 0; i < sizeof(places); i++) {
                if( prices[places[i]] > price ) {
                        price = prices[places[i]];
                        place = places[i];
                }
        }
        return "��˵" + region_names[place] + "һ���μ���ߡ�";
}
