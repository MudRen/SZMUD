                                       //Create by cheap
// Jay 11/9/01

// Code Last Update by Scatter on 12/31/2001

// MODIFY INFORMATION
/*
        This fix the problem of the owner ship for the car.
*/

inherit NPC;
string ask_car();

void create()
{
        set_name("����", ({ "feng dagui","feng","dagui" }));
        set_color("$HIW$"); 
        set("long", "���ǿ��е��ϰ壬�����ô�ü���ۣ�һ���׶�����ӡ�\n");
        set("title","�����ϰ�");
        set("gender", "����");
        set("age", 47);
        set("no_get_from", 1);
        set("max_jing", 5000);
        set("jing", 5000);
        set("max_jingli", 500);
        set("jingli", 500);
        set("max_qi", 500);
        set("qi", 500);
        set("PKS", 1000000);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 120);
        set_temp("apply/attack", 120);
        set_temp("apply/damage", 50);

        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("inquiry", ([
                "�⳵" : (: ask_car :),
                "��" : (: ask_car :),
]));
        setup();
        carry_object("/clone/armor/cloth")->wear();
}

void init()
{     
        add_action("return_car", "��");
        add_action("return_car", "return");
}
int return_car(string arg)
{
                object ob, me = this_player();   
            if( !arg || arg=="" ) return 0;
        if (!ob=present("car", environment(me)))  return 0;
                if (ob->query_lord() != me) return 0;
                
                if( arg=="car" ) 
                {
                        message_vision("��ӭ�´�������\n", me, this_object());
                        add("car_count", -1);    
                        if(me->query("rided"))
                        me->set("rided", 0);
                        destruct(ob);
                        return 1;
        }
}
        

string ask_car()
{
                object ob , me;
                me = this_player();

        if (me->query("rided") || me->query_temp("mark/��"))
                {
                        return("�㲻�����˳���");
        }

        if (query("car_count") > 10)
            return("�Բ������еĿ󳵶����˳�ȥ,Ҫ�����ǻ�����˵�ɡ�");

                ob=new("/newjob/tiejiang/obj/xiao_tc");
        ob->move("/newjob/tiejiang/gate");
                ob->set("owner",me->query("id"));

        add("car_count", 1);
        ob->set_lord(me);
        ob->set_leader(me);
        me->set_temp("mark/��", 1);
        say("����ȥǰ���ó��ˡ�\n");
        return(RANK_D->query_respect(me) + "�ǵ���㻹������");
}

