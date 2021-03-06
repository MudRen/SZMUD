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
        set_name("游坦之", ({ "you", "you tanzhi"}));  
        set("nickname", "铁丑");  
        set("long",   
                      "此人一张脸凹凹凸凸，一块红，一块黑，满是创伤痕痕，\n"  
                      "五官糜烂，丑陋可怖已极，无不骇然。\n");  
        set("gender", "男性");  
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
               "易筋经" : (: ask_book :),
                                
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
                say("游坦之大叫一声：“好你个"+RANK_D->query_rude(this_player())+"，居然想杀了阿紫姑娘，我跟你拼了！！”\n");
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
                
                write("游坦之匆匆的离开了。\n");
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
           if(!interactive(me))
                return;
                
               if(find_living("a zi"))
          ob=find_living("a zi");
          else { 
          tell_object(me,"游坦之说道：“我要去找阿紫姑娘。”\n");
            call_out("destruct_ob",1);
          return;
          }
                if(me = ob->query_temp("last_damage_from") ) 
                {
          if(ob=present("a zi",me) || ob=present("a zi"))
          {       
       if((int)ob->query("eff_qi")< (int)ob->query("max_qi")/2 )
        {   
                use_poison();
                who->kill_ob(me);
                who->set_leader(me);    
                me->fight_ob(who); 
                tell_object(me,"游坦之大怒：“狗贼，你把阿紫姑娘伤成这样，你去死吧！”\n");
        }
        else 
        {
                who->set_leader(me);
                tell_object(me,"游坦之大声叫道：“你要把阿紫姑娘带到哪里去？快把阿紫姑娘还给我！除非杀(kill)了我，要不然我绝对不会允许你把阿紫姑娘带走！”\n");
                    call_out("auto_kill",10);
        }
       } 
                else  
        {
        tell_object(me," 我要去找阿紫姑娘。\n");
            call_out("destruct_ob",1);
        }
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
        this_object()->command("halt");
              tell_object(ob, 
        "你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
        ob->apply_condition("bingcan_poison", 20);
             
}
void die()
{
          
    object player, corpse,ob;
    player = this_object()->query_temp("last_damage_from");
      if(objectp(corpse=CHAR_D->make_corpse(this_object())))
    {
        corpse->move(environment(this_object())); 
//        if ( objectp( player ) )
//
                tell_object(this_player(),"游坦之面目狰狞之极，手突然扬起，满是鲜血的
脸上居然露出了一丝诡异的笑容，这下用尽了他
所有的力气，终于缓缓的倒了下去。\n");
                destruct(this_object() );
                write("游坦之大叫一声，死了！\n");
                use_poison();
                tell_object(this_player(),"你搜了搜游坦之的尸体，发现胸口处有件东西，你连忙把它掏了出来。\n");
                ob=new("/u/rama/obj/book.c");
                ob->move(this_player());
                tell_object(this_player(),"你仔细一看原来是一本书。\n");
              this_player()->delete("azi/killer");
        

//      }
     }    
            
}

        
 
int accept_object(object me, object ob) 
{        
        if((string)ob->query("name")=="阿紫"||(string)ob->query("id") == "a zi")    
        {
        if((int)ob->query("eff_qi") < (int)ob->query("max_qi")) 
        { 
                 ob->kill_ob(me);
                 ob->set_leader(me);
                 me->fight_ob(ob);
                return notify_fail("你把阿紫伤成这个样子，你去死吧！\n"); 
        }
        
        else {  
                        //give some bonus and return, you disappear 
                        tell_object(ob,"真是太谢谢你!\n"); 
                        } 
        } 
        else return notify_fail("你拿什么东西消遣我！");
                  
}

void accept_kill(object me)
{
        object who;
        if(!me->query("azi/killer",1))
        {
        say("游坦之说道：“臭贼有帮手！咱们走！”\n");
        
        who=find_living("a zi");
                if(who)
                {
                        say("游坦之抓住阿紫的胳膊，一纵身飞也似的去了。\n");
                        me->delete("azi/killer",1);
                        destruct(who);
            call_out("destruct_ob",1);
                        return;
                        }
                else 
                {
                me->delete("azi/killer");
            call_out("destruct_ob",1);
                return;
                }
        }
        
}
int accept_fight(object me)
{
        if(!me->query("azi/killer",1))
        {
        tell_object(me,"游坦之说道：“我可没心思和你玩！”\n");
        return 0;
        }
        else
        {
        tell_object(me,"游坦之怒道：“既然你这么急着投胎，我就成全你！”\n");
        kill_ob(me);
        return 1;
        }
        return 1;
}
/* void destruct_me(object me)
{             
         object ob,ob1;  
              me=this_object();
          remove_call_out("destruct_me");
             if(objectp(this_player() != me->query_temp("last_damage_from")) )
               return;
              tell_object(this_player(),"游坦之面目狰狞之极，手突然扬起，满是鲜血的
脸上居然露出了一丝诡异的笑容，这下用尽了他
所有的力气，终于缓缓的倒了下去。\n");
             write("游坦之大叫一声，死了！\n");
              use_poison();
              tell_object(this_player(),"可能是游坦之浑身剧毒的缘故，尸体竟然在短短的时间
化为了一堆白骨，让人不寒而栗。你突然发现白骨之中有件什么东西，赶紧把它捡了起来。\n");
           ob=new("/u/rama/obj/book.c");
           ob->move(this_player());
           tell_object(this_player(),"你仔细一看原来是一本书。\n");
              this_player()->delete("azi/killer");
                        seteuid(geteuid(me));
              destruct(me);
              
                              
} */
void destruct_ob(object me)
{

        me=this_object();
        destruct(me);
}







