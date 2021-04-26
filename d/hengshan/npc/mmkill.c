//songshan killer by firefox 12/9/2001


inherit NPC;

#include <ansi.h>
#include "/d/hengshan/npc/npc_setup.h"
int auto_perform();
void unconcious();
void die();
//int block_road_all();
void make_killer(object killob,object ob);
void dest();
void create()
{
        set_name("������", ({ "mengmian ren","ren","mengmian" }) );
        set("gender", "����");
        set("age", 25+random(25));
        set("long",
                "��һ�ڽ����棬˫������ɱ����ʱ��ʱ�ͳ�����Ц��\n");
        set("combat_exp", 5000);
        set("shen_type", -1);
        set("attitude", "heroism");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               (: auto_perform :),
        }) ); 
        
        make_killer(this_object(),this_player());
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        call_out("dest",1200);
}
void make_killer(object killob,object ob)
{
        int player_exp=ob->query("combat_exp"),skillrate;
        if (player_exp<500000 ){
                player_exp=player_exp*2/3;
                skillrate=90; 
        }
        if (player_exp<2000000 && player_exp>=200000) {
                player_exp=player_exp;
                skillrate=100;
        }
        if (player_exp>2000000 ){
                player_exp=player_exp*3/2;
                skillrate=100;
        }
        set("combat_exp",player_exp);
        switch( random(5) )
        {
        case 0:
		set_skills("songshan",player_exp,skillrate,killob); 
		set("menpai","songshan"); 
        setup();
		carry_object("/clone/weapon/gangjian")->wield();
		break;
        case 1:
		set_skills("baituo",player_exp,skillrate,killob); 
		set("menpai","baituo"); 
		setup();
		carry_object("/clone/weapon/shezhang")->wield();
		break;
        case 2:
		set_skills("xingxiu",player_exp,skillrate,killob); 
		set("menpai","xingxiu"); 
		setup();
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
        case 3:
		set_skills("xueshan",player_exp,skillrate,killob); 
		set("menpai","xueshan"); 
		setup();
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
        case 4:        
		set_skills("gaibang",player_exp,skillrate,killob); 
		set("menpai","gaibang"); 
		setup();
		carry_object("/clone/weapon/gangdao")->wield();
        break;
        case 5:        
		set_skills("taohua",player_exp,skillrate,killob); 
		set("menpai","taohua"); 
		setup();
		carry_object("/clone/weapon/changbian")->wield();
        break;
        default:
		set_skills("songshan",player_exp,skillrate,killob); 
		set("menpai","songshan"); 
		setup();
		carry_object("/clone/weapon/gangjian")->wield();
        break;
		}
//		set_skills("songshan",player_exp,skillrate,killob); 
		set_hp(killob->query_skill("force",1),killob);
}
/*int block_road_all()
{
        object env;
        mapping exits1;
        string *road_exits;
        int i;
        env=environment(this_player());
        exits1=env->query("exits");
        road_exits=keys(exits1);
        for (i=0;i<sizeof(road_exits);i++) {
                env->set("exit_blockers/"+road_exits[i], this_object() );
        }
}*/

int auto_perform()
{
	object npc=this_object();
	object target = npc->select_opponent();

//	if(!npc->query_temp("weapon"))
				command("wield all");

	if (npc->query("menpai")=="songshan"){
		if (npc->query_temp("weapon")) 
				command("perform xuli");
				else command("perform leidong");
		}       
	else if(npc->query("menpai")=="baituo"){
		if (npc->query_temp("weapon")) {
				command("yun powerup");
//				command("perform shoot");
				}
				else command("perform puji");
		}       
	else if(npc->query("menpai")=="xingxiu"){
        if( objectp(npc->query_temp("weapon")) ) {
                command("perform jinxian");
        }
        else{
                if( !target->query_temp("huagong") )
                        command("perform sanyin");
 //               else	command("perform yiji");
						command("yun qisuck "+target->query("id"));
			}
        }       
	else if(npc->query("menpai")=="xueshan"){
		if (npc->query_temp("weapon")) {
				if( !npc->query_temp("wushang") )
						command("perform wushang");
//				else	command("perform feichu");
				}
				else command("perform yin");
		}	
	else if(npc->query("menpai")=="gaibang"){
		if (npc->query_temp("weapon")) 
			command("perform lianhuan");
		}	
	else if(npc->query("menpai")=="taohua"){
			command("perform bibo");
		}	
	else command("perform xuli");

	return 1;
}

void unconcious()
{
//      environment(this_object())->delete("exit_blockers");
        this_object()->die();
}
void die()
{
        object ob,me;
        ob=this_player();
        me=this_object();

//      if (me->query("player_id") == ob->query("id") )
//              ob->set("blockroad",2);
        if ( objectp(ob = me->query_temp("last_damage_from")) && objectp( ob = find_player(me->query("player_id") ) ) ) {
                ob->set_temp("blockroad",2);
        }

        message_vision("\n$N���һ������սȦ��һ��������\n", me);
        destruct(me);
}
void dest()
{
        tell_room(environment(this_object()),"�����˼���ææ�����ˡ�\n");
        destruct(this_object());
}
#include "/d/hengshan/npc/npc_setup.c"
