//rama@sz   
#include "/d/quest/xingxiu/auto_perform.h"
inherit NPC;  
inherit F_MASTER;  
        
//int ask_book();  
void check_azi();
void cp_npc(object ob,object me);
void use_poison();
int auto_kill();  
       
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
//        set("shen_type", -1);  
        set("str", 35);  
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
        set("chat_msg_combat", ({ 
                (: auto_perform :), 
            }) );  
 /*       set("inquiry", ([  
               "易筋经" : (: ask_book :),
                                
                      ]));  
*/              
        setup();  
        carry_object("/d/xingxiu/obj/yellow-cloth")->wear();  
}  
void init()
{
        if(this_player()->query_temp("azi/killer",1))
        {
                say("游坦之大叫一声：“好你个"+RANK_D->query_rude(this_player())+"，居然想杀了阿紫姑娘，我跟你拼了！！”\n");
//                cp_npc(this_player(),this_object());
                //copy_status() 1.5*exp 1*neili 1*jingli
                kill_ob(this_player());
                set_leader(this_player());
                this_player()->fight_ob(this_object());
                return;
                     
        }

}

void check_azi() 
{      
        object ob,player;
        object me=this_player();
        object who=this_object();
        if( !interactive(me))
        return;
        ob=find_living("a zi");
  
        player=ob->query_temp("last_damage_from");
                if( objectp(player) ) 
                {
                if(ob=present("a zi",player) || ob=present("a zi"))
                {       
                        if((int)ob->query("qi")< (int)ob->query("max_qi")/2 )
                        {   
                                who->kill_ob(player);
                                player->fight_ob(who); 
                                tell_object(player,"游坦之大怒：“狗贼，你把阿紫姑娘伤成这样，你去死吧！”\n");
                        }
                        else 
                        {
                                who->set_leader(player);
                                tell_object(player,"游坦之大声叫道：“你要把阿紫姑娘带到哪里去？快把阿紫姑娘还给我！除非杀(kill)了我，要不然我绝对不会允许你把阿紫姑娘带走！”\n");
                                call_out("auto_kill",10);
                        }
                }
                
                 
        }
        else  
        {
                tell_object(me,"游坦之道：“我要去找阿紫姑娘。”\n");
                call_out("destruct_ob",1);
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
        me->set("score",hp_status["score"]*(3/2));
        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("dex", hp_status["dex"]);

        me->set("max_qi",    hp_status["max_qi"]*(3/2));
        me->set("eff_qi",    hp_status["eff_qi"]*(3/2));
        me->set("qi",        hp_status["qi"]*(3/2));
        me->set("max_jing",  hp_status["max_jing"]*(3/2));
        me->set("eff_jing",  hp_status["eff_jing"]*(3/2));
        me->set("jing",      hp_status["jing"]*(3/2));
        me->set("max_neili", hp_status["max_neili"]*(3/2));
        me->set("neili",     hp_status["neili"]*(3/2));
        me->set("jiali",     hp_status["jiali"]);
}

void use_poison()
{
        object *enemy, ob;
        string msg;
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if( ob->query_condition("bingcan_poison") ) return;
        if( ob->query_condition("bingcan_poison") ) return;
        this_object()->command("halt");
        tell_object(ob, 
        "你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
        ob->apply_condition("bingcan_poison", 20);
             
}
void die()
{
          
        object player,corpse,ob;
        player = this_object()->query_temp("last_damage_from");
        if(objectp(corpse=CHAR_D->make_corpse(this_object())))
        corpse->move(environment(this_object())); 
        if ( objectp( player ) ) 
        {
        message_vision("游坦之面目狰狞之极，手突然扬起，满是鲜血的
脸上居然露出了一丝诡异的笑容，这下用尽了他
所有的力气，终于缓缓的倒了下去。\n",player);
        message_vision("游坦之大叫一声，死了！\n",player);
        tell_object(player, 
        "你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
        player->apply_condition("bingcan_poison", 40);
        tell_object(player,"你搜了搜游坦之的尸体，发现胸口处有件东西，你连忙把它掏了出来。\n");
        ob=new("/d/quest/xingxiu/obj/book.c");
        ob->move(player);
        tell_object(player,"你仔细一看原来是一本书。\n");
        if(!find_living("xiao feng") )
        {
                player->delete_temp("azi/killer2",1);
                player->delete_temp("azi/killer");
        }
        player->set_temp("you/done",1);
        destruct(this_object() );
//      ::die();        
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
        if(!me->query_temp("azi/killer",1) && !me->query_temp("azi/killer2",1) )
        {
        say("游坦之说道：“臭贼有帮手！咱们走！”\n");
        
        who=find_living("a zi");
                if(who)
                {
                        say("游坦之抓住阿紫的胳膊，一纵身飞也似的去了。\n");
                        
                        me->delete_temp("azi/killer",1);
                        me->delete_temp("azi/killer2",1);
                        destruct(who);
                        call_out("destruct_ob",1);
                        return;
                        }
                
        }
        
}
int accept_fight(object me)
{
        if(!me->query_temp("azi/killer",1) || !me->query_temp("azi/killer2",1) )
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
void destruct_ob(object me)
{

        me=this_object();
        destruct(me);
}


