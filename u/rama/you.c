//rama@sz   
#include "/u/rama/npc/auto_perform.h"
inherit NPC;  
inherit F_MASTER;  
        
//int ask_book();  
void check_azi();
void cp_npc(object ob,object me);
void use_poison();  
       
void create()  
{  
        set_name("��̹֮", ({ "You TanZhi", "you"}));  
        set("nickname", "����");  
        set("long",   
                      "����һ��������͹͹��һ��죬һ��ڣ����Ǵ��˺ۺۣ�\n"  
                      "������ã���ª�ɲ��Ѽ����޲���Ȼ��\n");  
        set("gender", "����");  
        set("age", 25);  
        set("attitude", "peaceful");  
        set("shen_type", -1);  
        set("str", 35);  
        set("int", 20);  
        set("con", 30);  
        set("dex", 20);
                              
        set("max_qi", 6500); 
        set("qi",6500); 
        set("max_jing", 4500); 
        set("jing",4500); 
        set("neili", 8000); 
        set("max_neili", 8000); 
        set("jingli",6000); 
        set("max_jingli",6000); 
        set("jiali", 250); 
        set("combat_exp", 3500000); 
        set("shen", -400000); 
        set("apply/armor", 90); 
        set("PKS", 1000000);  
                                             
        set_skill("force", 400);  
        set_skill("huagong-dafa", 400);  
        set_skill("dodge", 350);  
        set_skill("strike", 350);  
        set_skill("claw", 350);  
        set_skill("sanyin-zhua", 350);  
        set_skill("poison", 600);  
        set_skill("chousui-zhang", 350);  
        set_skill("parry", 350);  
        set_skill("tianshan-zhang", 350);  
        set_skill("feixing-shu", 350);  
              
        map_skill("force", "huagong-dafa");  
        map_skill("dodge", "zhaixinggong");  
        map_skill("strike", "chousui-zhang");  
        map_skill("parry", "chousui-zhang");  
        map_skill("claw", "sanyin-zhua");  
        map_skill("sword", "tianshan-zhang");  
              
        prepare_skill("strike", "chousui-duzhang");  
        prepare_skill("claw", "sanyin-zhua");  
                   
        set("chat_chance_combat", 50);  
                       
        set("chat_chance_combat", 90); 
        set("chat_msg_combat", ({ 
            (: auto_perform :), 
            }) );  
 /*       set("inquiry", ([  
               "�׽" : (: ask_book :),
                                
                      ]));  
*/              
        setup();  
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();  
          carry_object("/u/rama/obj/muding.c");
}  
void init()
{
        object who;
        if(this_player()->query("azi/killer",1))
        {
                say("��̹֮���һ�����������"+RANK_D->query_rude(this_player())+"����Ȼɱ���˰��Ϲ���Ҹ���ƴ�ˣ�����\n");
                cp_npc(this_player(),this_object());
                //copy_status() 1.5*exp 1*neili 1*jingli
                kill_ob(this_player());
                set_leader(this_player());
                this_player()->fight_ob(this_object());
                    return;
        }
          else
          check_azi();
/*      else
        {
                
                write("��̹֮�Ҵҵ��뿪�ˡ�\n");
                who=find_living("a zi");
                if(who)
                {
                        destruct(who);
                        destruct(this_object());
                }
                else
                destruct(this_object());
        }       */
}

void check_azi() 
{      
              object ob;
        object me=this_player();
        object who =this_object();
        if(find_living("a zi"))
          ob=find_living("a zi");
          else { 
          command("say ��Ҫȥ�Ұ��Ϲ��\n");
          destruct(who);
          return;
          }
          if(!interactive(me))
                return;
          if(ob=present("a zi",me) || ob=present("a zi"))
          {       
       if((int)ob->query("eff_qi")< (int)ob->query("max_qi")/2 )
        {   
                use_poison();
                who->kill_ob(me);
                who->set_leader(me);    
                me->fight_ob(who); 
                command("say ��������Ѱ��Ϲ����˳���������ȥ���ɣ�\n");
        }
        else 
        {
                command("follow "+me->query("id"));
                command("say ��Ҫ�Ѱ��Ϲ����������ȥ����Ѱ��Ϲ��ﻹ���ң�����ɱ(kill)���ң�Ҫ��Ȼ�Ҿ��Բ���������Ѱ��Ϲ�����ߣ�\n");
                    call_out("auto_kill",10);
        }
       } 
        else  
        {
        command("say ��Ҫȥ�Ұ��Ϲ��\n");
        destruct(who);
        }

}
int auto_kill()
{
        object me=this_player();
        object ob=this_object();
        ob->kill_ob(me);
        me->fight_ob(ob);
        remove_call_out("auto_kill");
}
 
void cp_npc(object ob,object me)
{
        mapping hp_status;
                hp_status = ob->query_entire_dbase();

                me->set("combat_exp", hp_status["combat_exp"]*(3/2));
                me->set("score",hp_status["score"]*1.5);
                me->set("str", hp_status["str"]);
                me->set("int", hp_status["int"]);
                me->set("con", hp_status["con"]);
                me->set("dex", hp_status["dex"]);

                me->set("max_qi",    hp_status["max_qi"]);
                me->set("eff_qi",    hp_status["eff_qi"]);
                me->set("qi",        hp_status["qi"]);
                me->set("max_jing",  hp_status["max_jing"]);
                me->set("eff_jing",  hp_status["eff_jing"]);
                me->set("jing",      hp_status["jing"]);
                me->set("max_neili", hp_status["max_neili"]);
                me->set("neili",     hp_status["neili"]);
                me->set("jiali",     hp_status["jiali"]);
}
void use_poison()
{
        object *enemy, ob;
        string msg;
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if( ob->query_condition("bingcan_poison") ) return;
        tell_object(ob, 
        "����������ƺ�մ����ʲ�ᶫ��������һ��ȴʲ��Ҳû�С�\n");
        ob->apply_condition("bingcan_poison", 20);
}
void die()
{
        tell_object(this_player(),"��̹֮��Ŀ����֮������ͻȻ����������Ѫ��
���Ͼ�Ȼ¶����һ˿�����Ц�ݣ������þ�����
���е����������ڻ����ĵ�����ȥ��\n");
        use_poison();
        this_player()->delete("azi/killer");
        ::die();
}

        
 
int accept_object(object me, object ob) 
{        
        if((string)ob->query("name")=="����"||(string)ob->query("id") == "a zi")    
        {
        if((int)ob->query("eff_qi") < (int)ob->query("max_qi")) 
        { 
                 ob->kill_ob(me);
                 ob->set_leader(me);
                 me->fight_ob(ob);
                return notify_fail("��Ѱ����˳�������ӣ���ȥ���ɣ�\n"); 
        }
        
        else {  
                        //give some bonus and return, you disappear 
                        tell_object(ob,"����̫лл��!\n"); 
                        } 
        } 
        else return notify_fail("����ʲô������ǲ�ң�");
                  
}

void accept_kill(object me)
{
        object who;
        if(!me->query("azi/killer2",1))
        {
        say("��̹֮˵�����������а��֣������ߣ���\n");
        
        who=find_living("a zi");
                if(who)
                {
                        say("��̹֮ץס���ϵĸ첲��һ�����Ҳ�Ƶ�ȥ�ˡ�\n");
                        me->delete("azi/killer2",1);
                        destruct(who);
                        destruct(this_object());
                        return;
                        }
                else 
                {
                me->delete("azi/killer2");
                destruct(this_object());
                return;
                }
        }
        
}
int accept_fight(object me)
{
        if(!me->query("azi/killer2",1))
        {
        say("��̹֮˵�������ҿ�û��˼�����棡��\n");
        return 0;
        }
        else
        {
        say("��̹֮ŭ��������Ȼ����ô����Ͷ̥���Ҿͳ�ȫ�㣡��\n");
        kill_ob(me);
        return 1;
        }
        return 1;
}





